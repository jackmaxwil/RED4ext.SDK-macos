#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/NativeTypes.hpp>
#include <RED4ext/Scripting/Natives/Generated/AdvertisementFormat.hpp>
#include <RED4ext/Scripting/Natives/Generated/IWorldWidgetComponent.hpp>

namespace RED4ext
{
struct __declspec(align(0x10)) AdvertisementWidgetComponent : IWorldWidgetComponent
{
    static constexpr const char* NAME = "AdvertisementWidgetComponent";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    AdvertisementFormat format; // 2AC
    uint8_t unk2AD[0x2B0 - 0x2AD]; // 2AD
    TweakDBID adGroupTDBID; // 2B0
    uint8_t unk2B8[0x2C0 - 0x2B8]; // 2B8
    bool enableOverride; // 2C0
    uint8_t unk2C1[0x2C4 - 0x2C1]; // 2C1
    TweakDBID adOverrideTDBID; // 2C4
    uint32_t adVersion; // 2CC
    bool useOnlyAttachedLights; // 2D0
    uint8_t unk2D1[0x330 - 0x2D1]; // 2D1
#else
    AdvertisementFormat format; // 2B0
    uint8_t unk2B1[0x2B4 - 0x2B1]; // 2B1
    TweakDBID adGroupTDBID; // 2B4
    uint8_t unk2BC[0x2C4 - 0x2BC]; // 2BC
    bool enableOverride; // 2C4
    uint8_t unk2C5[0x2C8 - 0x2C5]; // 2C5
    TweakDBID adOverrideTDBID; // 2C8
    uint32_t adVersion; // 2D0
    bool useOnlyAttachedLights; // 2D4
    uint8_t unk2D5[0x330 - 0x2D5]; // 2D5
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(AdvertisementWidgetComponent, 0x330);
RED4EXT_ASSERT_OFFSET(AdvertisementWidgetComponent, format, 0x2AC);
RED4EXT_ASSERT_OFFSET(AdvertisementWidgetComponent, adGroupTDBID, 0x2B0);
RED4EXT_ASSERT_OFFSET(AdvertisementWidgetComponent, enableOverride, 0x2C0);
RED4EXT_ASSERT_OFFSET(AdvertisementWidgetComponent, adOverrideTDBID, 0x2C4);
RED4EXT_ASSERT_OFFSET(AdvertisementWidgetComponent, adVersion, 0x2CC);
RED4EXT_ASSERT_OFFSET(AdvertisementWidgetComponent, useOnlyAttachedLights, 0x2D0);
#else
RED4EXT_ASSERT_SIZE(AdvertisementWidgetComponent, 0x330);
#endif
} // namespace RED4ext

// clang-format on
