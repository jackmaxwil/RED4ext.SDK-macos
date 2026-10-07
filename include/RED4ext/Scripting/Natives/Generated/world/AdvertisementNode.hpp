#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/DynArray.hpp>
#include <RED4ext/NativeTypes.hpp>
#include <RED4ext/Scripting/Natives/Generated/AdvertisementFormat.hpp>
#include <RED4ext/Scripting/Natives/Generated/Vector3.hpp>
#include <RED4ext/Scripting/Natives/Generated/world/AdvertisementLightData.hpp>
#include <RED4ext/Scripting/Natives/Generated/world/StaticMeshNode.hpp>

namespace RED4ext
{
namespace world
{
struct AdvertisementNode : world::StaticMeshNode
{
    static constexpr const char* NAME = "worldAdvertisementNode";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    Vector3 meshInitialScale; // 5C
    AdvertisementFormat format; // 68
    uint8_t unk69[0x6C - 0x69]; // 69
    TweakDBID adGroupTDBID; // 6C
    uint8_t unk74[0x7C - 0x74]; // 74
    bool enableOverride; // 7C
    uint8_t unk7D[0x80 - 0x7D]; // 7D
    TweakDBID adOverrideTDBID; // 80
    uint32_t adVersion; // 88
    float glitchValue; // 8C
    uint8_t unk90[0xA8 - 0x90]; // 90
    DynArray<world::AdvertisementLightData> lightsData; // A8
    uint8_t unkB8[0xC0 - 0xB8]; // B8
#else
    Vector3 meshInitialScale; // 60
    AdvertisementFormat format; // 6C
    uint8_t unk6D[0x70 - 0x6D]; // 6D
    TweakDBID adGroupTDBID; // 70
    uint8_t unk78[0x80 - 0x78]; // 78
    bool enableOverride; // 80
    uint8_t unk81[0x84 - 0x81]; // 81
    TweakDBID adOverrideTDBID; // 84
    uint32_t adVersion; // 8C
    float glitchValue; // 90
    uint8_t unk94[0xB0 - 0x94]; // 94
    DynArray<world::AdvertisementLightData> lightsData; // B0
    uint8_t unkC0[0xC8 - 0xC0]; // C0
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(AdvertisementNode, 0xC0);
RED4EXT_ASSERT_OFFSET(AdvertisementNode, meshInitialScale, 0x5C);
RED4EXT_ASSERT_OFFSET(AdvertisementNode, format, 0x68);
RED4EXT_ASSERT_OFFSET(AdvertisementNode, adGroupTDBID, 0x6C);
RED4EXT_ASSERT_OFFSET(AdvertisementNode, enableOverride, 0x7C);
RED4EXT_ASSERT_OFFSET(AdvertisementNode, adOverrideTDBID, 0x80);
RED4EXT_ASSERT_OFFSET(AdvertisementNode, adVersion, 0x88);
RED4EXT_ASSERT_OFFSET(AdvertisementNode, glitchValue, 0x8C);
RED4EXT_ASSERT_OFFSET(AdvertisementNode, lightsData, 0xA8);
#else
RED4EXT_ASSERT_SIZE(AdvertisementNode, 0xC8);
#endif
} // namespace world
using worldAdvertisementNode = world::AdvertisementNode;
} // namespace RED4ext

// clang-format on
