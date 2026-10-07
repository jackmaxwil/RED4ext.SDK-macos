#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/CName.hpp>
#include <RED4ext/Containers/DynArray.hpp>
#include <RED4ext/Handle.hpp>
#include <RED4ext/NativeTypes.hpp>
#include <RED4ext/Scripting/Natives/Generated/NavGenNavigationSetting.hpp>
#include <RED4ext/Scripting/Natives/Generated/Transform.hpp>
#include <RED4ext/Scripting/Natives/Generated/physics/FilterDataSource.hpp>
#include <RED4ext/Scripting/Natives/Generated/physics/SimulationType.hpp>
#include <RED4ext/Scripting/Natives/Generated/world/MeshNode.hpp>
#include <RED4ext/Scripting/Natives/Generated/world/TransformBuffer.hpp>

namespace RED4ext
{
struct CMesh;
namespace physics { struct FilterData; }
namespace world { struct Effect; }

namespace world
{
struct InstancedDestructibleMeshNode : world::MeshNode
{
    static constexpr const char* NAME = "worldInstancedDestructibleMeshNode";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    NavGenNavigationSetting navigationSetting; // 5A
    uint8_t unk5C[0x60 - 0x5C]; // 5C
    world::TransformBuffer cookedInstanceTransforms; // 60
    physics::SimulationType simulationType; // 78
    uint8_t unk79[0x80 - 0x79]; // 79
    Handle<physics::FilterData> filterData; // 80
    physics::FilterDataSource filterDataSource; // 90
    uint8_t unk91[0x98 - 0x91]; // 91
    RaRef<world::Effect> fracturingEffect; // 98
    RaRef<world::Effect> idleEffect; // A0
    RaRef<CMesh> staticMesh; // A8
    CName staticMeshAppearance; // B0
    float impulseToDamage; // B8
    float damageThreshold; // BC
    float damageEndurance; // C0
    bool useAggregate; // C4
    bool enableSelfCollisionInAggregate; // C5
    bool startInactive; // C6
    bool turnDynamicOnImpulse; // C7
    bool isDestructible; // C8
    bool accumulateDamage; // C9
    bool isPierceable; // CA
    bool isWorkspot; // CB
    bool useMeshNavmeshSettings; // CC
    uint8_t unkCD[0xCE - 0xCD]; // CD
    uint16_t systemsToNotifyFlags; // CE
    DynArray<Transform> instanceTransforms; // D0
#else
    NavGenNavigationSetting navigationSetting; // 60
    uint8_t unk62[0x68 - 0x62]; // 62
    world::TransformBuffer cookedInstanceTransforms; // 68
    physics::SimulationType simulationType; // 80
    uint8_t unk81[0x88 - 0x81]; // 81
    Handle<physics::FilterData> filterData; // 88
    physics::FilterDataSource filterDataSource; // 98
    uint8_t unk99[0xA0 - 0x99]; // 99
    RaRef<world::Effect> fracturingEffect; // A0
    RaRef<world::Effect> idleEffect; // A8
    RaRef<CMesh> staticMesh; // B0
    CName staticMeshAppearance; // B8
    float impulseToDamage; // C0
    float damageThreshold; // C4
    float damageEndurance; // C8
    bool useAggregate; // CC
    bool enableSelfCollisionInAggregate; // CD
    bool startInactive; // CE
    bool turnDynamicOnImpulse; // CF
    bool isDestructible; // D0
    bool accumulateDamage; // D1
    bool isPierceable; // D2
    bool isWorkspot; // D3
    bool useMeshNavmeshSettings; // D4
    uint8_t unkD5[0xD6 - 0xD5]; // D5
    uint16_t systemsToNotifyFlags; // D6
    DynArray<Transform> instanceTransforms; // D8
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(InstancedDestructibleMeshNode, 0xE0);
RED4EXT_ASSERT_OFFSET(InstancedDestructibleMeshNode, navigationSetting, 0x5A);
RED4EXT_ASSERT_OFFSET(InstancedDestructibleMeshNode, cookedInstanceTransforms, 0x60);
RED4EXT_ASSERT_OFFSET(InstancedDestructibleMeshNode, simulationType, 0x78);
RED4EXT_ASSERT_OFFSET(InstancedDestructibleMeshNode, filterData, 0x80);
RED4EXT_ASSERT_OFFSET(InstancedDestructibleMeshNode, filterDataSource, 0x90);
RED4EXT_ASSERT_OFFSET(InstancedDestructibleMeshNode, fracturingEffect, 0x98);
RED4EXT_ASSERT_OFFSET(InstancedDestructibleMeshNode, idleEffect, 0xA0);
RED4EXT_ASSERT_OFFSET(InstancedDestructibleMeshNode, staticMesh, 0xA8);
RED4EXT_ASSERT_OFFSET(InstancedDestructibleMeshNode, staticMeshAppearance, 0xB0);
RED4EXT_ASSERT_OFFSET(InstancedDestructibleMeshNode, impulseToDamage, 0xB8);
RED4EXT_ASSERT_OFFSET(InstancedDestructibleMeshNode, damageThreshold, 0xBC);
RED4EXT_ASSERT_OFFSET(InstancedDestructibleMeshNode, damageEndurance, 0xC0);
RED4EXT_ASSERT_OFFSET(InstancedDestructibleMeshNode, useAggregate, 0xC4);
RED4EXT_ASSERT_OFFSET(InstancedDestructibleMeshNode, enableSelfCollisionInAggregate, 0xC5);
RED4EXT_ASSERT_OFFSET(InstancedDestructibleMeshNode, startInactive, 0xC6);
RED4EXT_ASSERT_OFFSET(InstancedDestructibleMeshNode, turnDynamicOnImpulse, 0xC7);
RED4EXT_ASSERT_OFFSET(InstancedDestructibleMeshNode, isDestructible, 0xC8);
RED4EXT_ASSERT_OFFSET(InstancedDestructibleMeshNode, accumulateDamage, 0xC9);
RED4EXT_ASSERT_OFFSET(InstancedDestructibleMeshNode, isPierceable, 0xCA);
RED4EXT_ASSERT_OFFSET(InstancedDestructibleMeshNode, isWorkspot, 0xCB);
RED4EXT_ASSERT_OFFSET(InstancedDestructibleMeshNode, useMeshNavmeshSettings, 0xCC);
RED4EXT_ASSERT_OFFSET(InstancedDestructibleMeshNode, systemsToNotifyFlags, 0xCE);
RED4EXT_ASSERT_OFFSET(InstancedDestructibleMeshNode, instanceTransforms, 0xD0);
#else
RED4EXT_ASSERT_SIZE(InstancedDestructibleMeshNode, 0xE8);
#endif
} // namespace world
using worldInstancedDestructibleMeshNode = world::InstancedDestructibleMeshNode;
} // namespace RED4ext

// clang-format on
