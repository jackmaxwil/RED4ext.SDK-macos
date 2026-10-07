#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/CName.hpp>
#include <RED4ext/DynArray.hpp>
#include <RED4ext/NativeTypes.hpp>
#include <RED4ext/Scripting/Natives/Generated/NavGenNavigationSetting.hpp>
#include <RED4ext/Scripting/Natives/Generated/physics/DestructionLevelData.hpp>
#include <RED4ext/Scripting/Natives/Generated/physics/DestructionParams.hpp>
#include <RED4ext/Scripting/Natives/Generated/world/Node.hpp>

namespace RED4ext
{
struct CMesh;

namespace world
{
struct PhysicalDestructionNode : world::Node
{
    static constexpr const char* NAME = "worldPhysicalDestructionNode";
    static constexpr const char* ALIAS = "PhysicalDestructionNode";

#ifdef __APPLE__
    uint8_t unk32[0x34 - 0x32]; // 32
    physics::DestructionParams destructionParams; // 34
    uint8_t unk84[0x88 - 0x84]; // 84
    DynArray<physics::DestructionLevelData> destructionLevelData; // 88
    RaRef<CMesh> mesh; // 98
    CName meshAppearance; // A0
    CName audioMetadata; // A8
    float forceAutoHideDistance; // B0
    int32_t forceLODLevel; // B4
    NavGenNavigationSetting navigationSetting; // B8
    uint16_t systemsToNotifyFlags; // BA
    bool useMeshNavmeshSettings; // BC
    uint8_t unkBD[0xC0 - 0xBD]; // BD
#else
    physics::DestructionParams destructionParams; // 38
    DynArray<physics::DestructionLevelData> destructionLevelData; // 88
    RaRef<CMesh> mesh; // 98
    CName meshAppearance; // A0
    CName audioMetadata; // A8
    float forceAutoHideDistance; // B0
    int32_t forceLODLevel; // B4
    NavGenNavigationSetting navigationSetting; // B8
    uint16_t systemsToNotifyFlags; // BA
    bool useMeshNavmeshSettings; // BC
    uint8_t unkBD[0xC0 - 0xBD]; // BD
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(PhysicalDestructionNode, 0xC0);
RED4EXT_ASSERT_OFFSET(PhysicalDestructionNode, destructionParams, 0x34);
RED4EXT_ASSERT_OFFSET(PhysicalDestructionNode, destructionLevelData, 0x88);
RED4EXT_ASSERT_OFFSET(PhysicalDestructionNode, mesh, 0x98);
RED4EXT_ASSERT_OFFSET(PhysicalDestructionNode, meshAppearance, 0xA0);
RED4EXT_ASSERT_OFFSET(PhysicalDestructionNode, audioMetadata, 0xA8);
RED4EXT_ASSERT_OFFSET(PhysicalDestructionNode, forceAutoHideDistance, 0xB0);
RED4EXT_ASSERT_OFFSET(PhysicalDestructionNode, forceLODLevel, 0xB4);
RED4EXT_ASSERT_OFFSET(PhysicalDestructionNode, navigationSetting, 0xB8);
RED4EXT_ASSERT_OFFSET(PhysicalDestructionNode, systemsToNotifyFlags, 0xBA);
RED4EXT_ASSERT_OFFSET(PhysicalDestructionNode, useMeshNavmeshSettings, 0xBC);
#else
RED4EXT_ASSERT_SIZE(PhysicalDestructionNode, 0xC0);
#endif
} // namespace world
using worldPhysicalDestructionNode = world::PhysicalDestructionNode;
using PhysicalDestructionNode = world::PhysicalDestructionNode;
} // namespace RED4ext

// clang-format on
