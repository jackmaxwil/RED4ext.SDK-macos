#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/Scripting/Natives/Generated/NavGenNavigationSetting.hpp>
#include <RED4ext/Scripting/Natives/Generated/TrafficGenDynamicTrafficSetting.hpp>
#include <RED4ext/Scripting/Natives/Generated/world/MeshNode.hpp>

namespace RED4ext
{
namespace world
{
struct DynamicMeshNode : world::MeshNode
{
    static constexpr const char* NAME = "worldDynamicMeshNode";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    TrafficGenDynamicTrafficSetting dynamicTrafficSetting; // 5A
    NavGenNavigationSetting navigationSetting; // 5C
    bool startAsleep; // 5E
    bool isDebris; // 5F
    bool initialGuess; // 60
    bool useMeshNavmeshSettings; // 61
    uint8_t unk62[0x68 - 0x62]; // 62
#else
    TrafficGenDynamicTrafficSetting dynamicTrafficSetting; // 60
    NavGenNavigationSetting navigationSetting; // 62
    bool startAsleep; // 64
    bool isDebris; // 65
    bool initialGuess; // 66
    bool useMeshNavmeshSettings; // 67
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(DynamicMeshNode, 0x68);
RED4EXT_ASSERT_OFFSET(DynamicMeshNode, dynamicTrafficSetting, 0x5A);
RED4EXT_ASSERT_OFFSET(DynamicMeshNode, navigationSetting, 0x5C);
RED4EXT_ASSERT_OFFSET(DynamicMeshNode, startAsleep, 0x5E);
RED4EXT_ASSERT_OFFSET(DynamicMeshNode, isDebris, 0x5F);
RED4EXT_ASSERT_OFFSET(DynamicMeshNode, initialGuess, 0x60);
RED4EXT_ASSERT_OFFSET(DynamicMeshNode, useMeshNavmeshSettings, 0x61);
#else
RED4EXT_ASSERT_SIZE(DynamicMeshNode, 0x68);
#endif
} // namespace world
using worldDynamicMeshNode = world::DynamicMeshNode;
} // namespace RED4ext

// clang-format on
