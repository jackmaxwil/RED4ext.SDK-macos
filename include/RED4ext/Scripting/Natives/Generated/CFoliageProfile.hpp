#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/NativeTypes.hpp>
#include <RED4ext/Scripting/Natives/Generated/CResource.hpp>

namespace RED4ext
{
struct CGradient;

struct CFoliageProfile : CResource
{
    static constexpr const char* NAME = "CFoliageProfile";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    uint8_t unk39[0x3C - 0x39]; // 39
    float cutoffAlphaMinMip; // 3C
    float cutoffAlphaMaxMip; // 40
    float billboardCutoffAlpha; // 44
    float aoScale; // 48
    float terrainBlendScale; // 4C
    float terrainBlendBias; // 50
    float billboardDepthScale; // 54
    float preserveOriginalColor; // 58
    float billboardRoughnessBias; // 5C
    Ref<CGradient> colorGradient; // 60
    float colorGradientWeight; // 78
    float colorGradientDarkenWeight; // 7C
    uint8_t unk80[0x90 - 0x80]; // 80
#else
    float cutoffAlphaMinMip; // 40
    float cutoffAlphaMaxMip; // 44
    float billboardCutoffAlpha; // 48
    float aoScale; // 4C
    float terrainBlendScale; // 50
    float terrainBlendBias; // 54
    float billboardDepthScale; // 58
    float preserveOriginalColor; // 5C
    float billboardRoughnessBias; // 60
    uint8_t unk64[0x68 - 0x64]; // 64
    Ref<CGradient> colorGradient; // 68
    float colorGradientWeight; // 80
    float colorGradientDarkenWeight; // 84
    uint8_t unk88[0x98 - 0x88]; // 88
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(CFoliageProfile, 0x90);
RED4EXT_ASSERT_OFFSET(CFoliageProfile, cutoffAlphaMinMip, 0x3C);
RED4EXT_ASSERT_OFFSET(CFoliageProfile, cutoffAlphaMaxMip, 0x40);
RED4EXT_ASSERT_OFFSET(CFoliageProfile, billboardCutoffAlpha, 0x44);
RED4EXT_ASSERT_OFFSET(CFoliageProfile, aoScale, 0x48);
RED4EXT_ASSERT_OFFSET(CFoliageProfile, terrainBlendScale, 0x4C);
RED4EXT_ASSERT_OFFSET(CFoliageProfile, terrainBlendBias, 0x50);
RED4EXT_ASSERT_OFFSET(CFoliageProfile, billboardDepthScale, 0x54);
RED4EXT_ASSERT_OFFSET(CFoliageProfile, preserveOriginalColor, 0x58);
RED4EXT_ASSERT_OFFSET(CFoliageProfile, billboardRoughnessBias, 0x5C);
RED4EXT_ASSERT_OFFSET(CFoliageProfile, colorGradient, 0x60);
RED4EXT_ASSERT_OFFSET(CFoliageProfile, colorGradientWeight, 0x78);
RED4EXT_ASSERT_OFFSET(CFoliageProfile, colorGradientDarkenWeight, 0x7C);
#else
RED4EXT_ASSERT_SIZE(CFoliageProfile, 0x98);
#endif
} // namespace RED4ext

// clang-format on
