#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/Scripting/Natives/Generated/CResource.hpp>
#include <RED4ext/Scripting/Natives/Generated/Color.hpp>

namespace RED4ext
{
struct CSkinProfile : CResource
{
    static constexpr const char* NAME = "CSkinProfile";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    uint8_t unk39[0x3C - 0x39]; // 39
    float blurSize; // 3C
    Color diffuse; // 40
    Color falloff; // 44
    float roughness0; // 48
    float roughness1; // 4C
    float lobeMix; // 50
    uint8_t unk54[0x68 - 0x54]; // 54
#else
    float blurSize; // 40
    Color diffuse; // 44
    Color falloff; // 48
    float roughness0; // 4C
    float roughness1; // 50
    float lobeMix; // 54
    uint8_t unk58[0x68 - 0x58]; // 58
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(CSkinProfile, 0x68);
RED4EXT_ASSERT_OFFSET(CSkinProfile, blurSize, 0x3C);
RED4EXT_ASSERT_OFFSET(CSkinProfile, diffuse, 0x40);
RED4EXT_ASSERT_OFFSET(CSkinProfile, falloff, 0x44);
RED4EXT_ASSERT_OFFSET(CSkinProfile, roughness0, 0x48);
RED4EXT_ASSERT_OFFSET(CSkinProfile, roughness1, 0x4C);
RED4EXT_ASSERT_OFFSET(CSkinProfile, lobeMix, 0x50);
#else
RED4EXT_ASSERT_SIZE(CSkinProfile, 0x68);
#endif
} // namespace RED4ext

// clang-format on
