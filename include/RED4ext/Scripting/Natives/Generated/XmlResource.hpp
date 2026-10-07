#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/NativeTypes.hpp>
#include <RED4ext/Scripting/Natives/Generated/CResource.hpp>

namespace RED4ext
{
struct XmlResource : CResource
{
    static constexpr const char* NAME = "XmlResource";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    uint8_t unk39[0x40 - 0x39]; // 39
    CString data; // 40
    uint8_t unk60[0x68 - 0x60]; // 60
#else
    CString data; // 40
    uint8_t unk60[0x68 - 0x60]; // 60
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(XmlResource, 0x68);
RED4EXT_ASSERT_OFFSET(XmlResource, data, 0x40);
#else
RED4EXT_ASSERT_SIZE(XmlResource, 0x68);
#endif
} // namespace RED4ext

// clang-format on
