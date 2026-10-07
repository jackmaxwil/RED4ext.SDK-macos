#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/Scripting/Natives/Generated/CResource.hpp>
#include <RED4ext/Scripting/Natives/Generated/rend/RenderMultilayerMaskResource.hpp>

namespace RED4ext
{
struct Multilayer_Mask : CResource
{
    static constexpr const char* NAME = "Multilayer_Mask";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    uint8_t unk39[0x48 - 0x39]; // 39
    rend::RenderMultilayerMaskResource renderResourceBlob; // 48
    uint8_t unk58[0x78 - 0x58]; // 58
#else
    uint8_t unk40[0x48 - 0x40]; // 40
    rend::RenderMultilayerMaskResource renderResourceBlob; // 48
    uint8_t unk58[0x78 - 0x58]; // 58
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(Multilayer_Mask, 0x78);
RED4EXT_ASSERT_OFFSET(Multilayer_Mask, renderResourceBlob, 0x48);
#else
RED4EXT_ASSERT_SIZE(Multilayer_Mask, 0x78);
#endif
} // namespace RED4ext

// clang-format on
