#include <RED4ext/RED4ext.hpp>
#include <RED4ext/Relocation.hpp>

#include <cstdint>
#include <fstream>
#include <iostream>
#include <string_view>

#if defined(__APPLE__)
#include <mach-o/dyld.h>
#include <mach-o/loader.h>
#endif

namespace
{
#if defined(__APPLE__)
std::ostream& LogStream()
{
    static std::ofstream s_log("/tmp/RED4ext.SDK_segment_resolution_test.log", std::ios::out | std::ios::app);
    if (s_log.is_open())
    {
        static bool s_configured = false;
        if (!s_configured)
        {
            s_log << std::unitbuf;
            s_configured = true;
        }
        return s_log;
    }
    return std::cerr;
}

struct SegmentBases
{
    std::uintptr_t text{0};
    std::uintptr_t dataConst{0};
    std::uintptr_t data{0};
};

SegmentBases GetSegmentBases()
{
    SegmentBases bases{};

    const auto* header = reinterpret_cast<const mach_header_64*>(_dyld_get_image_header(0));
    if (!header || header->magic != MH_MAGIC_64)
        return bases;

    const auto slide = static_cast<std::intptr_t>(_dyld_get_image_vmaddr_slide(0));
    const auto* cmd = reinterpret_cast<const std::uint8_t*>(header) + sizeof(mach_header_64);

    for (std::uint32_t i = 0; i < header->ncmds; ++i)
    {
        const auto* lc = reinterpret_cast<const load_command*>(cmd);
        if (!lc || lc->cmdsize == 0)
            break;

        if (lc->cmd == LC_SEGMENT_64 && lc->cmdsize >= sizeof(segment_command_64))
        {
            const auto* seg = reinterpret_cast<const segment_command_64*>(cmd);
            std::size_t nameLen = 0;
            while (nameLen < sizeof(seg->segname) && seg->segname[nameLen] != '\0')
                ++nameLen;

            const std::string_view segName(seg->segname, nameLen);
            const auto runtimeBase = static_cast<std::uintptr_t>(static_cast<std::intptr_t>(seg->vmaddr) + slide);

            if (segName == "__TEXT")
                bases.text = runtimeBase;
            else if (segName == "__DATA_CONST")
                bases.dataConst = runtimeBase;
            else if (segName == "__DATA")
                bases.data = runtimeBase;
        }

        cmd += lc->cmdsize;
    }

    return bases;
}
#endif
} // namespace

RED4EXT_C_EXPORT bool RED4EXT_CALL Main(RED4ext::v1::PluginHandle aHandle, RED4ext::v1::EMainReason aReason,
                                        const RED4ext::v1::Sdk* aSdk)
{
    RED4EXT_UNUSED_PARAMETER(aHandle);
    RED4EXT_UNUSED_PARAMETER(aSdk);

    if (aReason != RED4ext::v1::EMainReason::Load)
        return true;

#if defined(__APPLE__)
    auto& log = LogStream();
    log << "[RED4ext.SDK segment] Load\n";

    constexpr std::uintptr_t kOffset = 0x20;
    constexpr std::uint32_t kHashText = 0x10000001;
    constexpr std::uint32_t kHashDataConst = 0x10000002;
    constexpr std::uint32_t kHashData = 0x10000003;

    const auto bases = GetSegmentBases();
    log << "[RED4ext.SDK segment] bases.text=0x" << std::hex << bases.text << " bases.dataConst=0x" << bases.dataConst
        << " bases.data=0x" << bases.data << std::dec << "\n";

    const auto addrText = RED4ext::UniversalRelocBase::Resolve(kHashText);
    const auto addrDataConst = RED4ext::UniversalRelocBase::Resolve(kHashDataConst);
    const auto addrData = RED4ext::UniversalRelocBase::Resolve(kHashData);

    log << "[RED4ext.SDK segment] Resolve(" << std::hex << kHashText << ")=0x" << addrText << std::dec << "\n";
    log << "[RED4ext.SDK segment] Resolve(" << std::hex << kHashDataConst << ")=0x" << addrDataConst << std::dec
        << "\n";
    log << "[RED4ext.SDK segment] Resolve(" << std::hex << kHashData << ")=0x" << addrData << std::dec << "\n";

    const auto expectedText = bases.text ? (bases.text + kOffset) : 0;
    const auto expectedDataConst = bases.dataConst ? (bases.dataConst + kOffset) : 0;
    const auto expectedData = bases.data ? (bases.data + kOffset) : 0;

    log << "[RED4ext.SDK segment] expectedText=0x" << std::hex << expectedText << " expectedDataConst=0x"
        << expectedDataConst << " expectedData=0x" << expectedData << std::dec << "\n";

    const bool okText = expectedText != 0 && addrText == expectedText;
    const bool okDataConst = expectedDataConst != 0 && addrDataConst == expectedDataConst;
    const bool okData = expectedData != 0 && addrData == expectedData;

    log << "[RED4ext.SDK segment] result text=" << (okText ? "OK" : "FAIL")
        << " dataConst=" << (okDataConst ? "OK" : "FAIL") << " data=" << (okData ? "OK" : "FAIL") << "\n";
#endif

    return true;
}

RED4EXT_C_EXPORT void RED4EXT_CALL Query(RED4ext::v1::PluginInfo* aInfo)
{
    aInfo->name = L"RED4ext.SDK.macos_segment_resolution";
    aInfo->author = L"RED4ext macOS port";
    aInfo->version = RED4EXT_V1_SEMVER(1, 0, 0);
    aInfo->runtime = RED4EXT_V1_RUNTIME_VERSION_LATEST;
    aInfo->sdk = RED4EXT_V1_SDK_VERSION_CURRENT;
}

RED4EXT_C_EXPORT uint32_t RED4EXT_CALL Supports()
{
    return RED4EXT_API_VERSION_1;
}
