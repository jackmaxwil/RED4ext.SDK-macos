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
    physics::SimulationType simulationType; // 5C
    uint8_t unk5D[0x60 - 0x5D]; // 5D
    Handle<physics::FilterData> filterData; // 60
    physics::FilterDataSource filterDataSource; // 70
    uint8_t unk71[0x78 - 0x71]; // 71
    RaRef<world::Effect> fracturingEffect; // 78
    RaRef<world::Effect> idleEffect; // 80
    RaRef<CMesh> staticMesh; // 88
    CName staticMeshAppearance; // 90
    float impulseToDamage; // 98
    float damageThreshold; // 9C
    float damageEndurance; // A0
    bool useAggregate; // A4
    bool enableSelfCollisionInAggregate; // A5
    bool startInactive; // A6
    bool turnDynamicOnImpulse; // A7
    bool isDestructible; // A8
    bool accumulateDamage; // A9
    bool isPierceable; // AA
    bool isWorkspot; // AB
    bool useMeshNavmeshSettings; // AC
    uint8_t unkAD[0xAE - 0xAD]; // AD
    uint16_t systemsToNotifyFlags; // AE
    DynArray<Transform> instanceTransforms; // B0
#else
    NavGenNavigationSetting navigationSetting; // 60
    physics::SimulationType simulationType; // 62
    uint8_t unk63[0x68 - 0x63]; // 63
    Handle<physics::FilterData> filterData; // 68
    physics::FilterDataSource filterDataSource; // 78
    uint8_t unk79[0x80 - 0x79]; // 79
    RaRef<world::Effect> fracturingEffect; // 80
    RaRef<world::Effect> idleEffect; // 88
    RaRef<CMesh> staticMesh; // 90
    CName staticMeshAppearance; // 98
    float impulseToDamage; // A0
    float damageThreshold; // A4
    float damageEndurance; // A8
    bool useAggregate; // AC
    bool enableSelfCollisionInAggregate; // AD
    bool startInactive; // AE
    bool turnDynamicOnImpulse; // AF
    bool isDestructible; // B0
    bool accumulateDamage; // B1
    bool isPierceable; // B2
    bool isWorkspot; // B3
    bool useMeshNavmeshSettings; // B4
    uint8_t unkB5[0xB6 - 0xB5]; // B5
    uint16_t systemsToNotifyFlags; // B6
    DynArray<Transform> instanceTransforms; // B8
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(InstancedDestructibleMeshNode, 0xC0);
RED4EXT_ASSERT_OFFSET(InstancedDestructibleMeshNode, navigationSetting, 0x5A);
RED4EXT_ASSERT_OFFSET(InstancedDestructibleMeshNode, simulationType, 0x5C);
RED4EXT_ASSERT_OFFSET(InstancedDestructibleMeshNode, filterData, 0x60);
RED4EXT_ASSERT_OFFSET(InstancedDestructibleMeshNode, filterDataSource, 0x70);
RED4EXT_ASSERT_OFFSET(InstancedDestructibleMeshNode, fracturingEffect, 0x78);
RED4EXT_ASSERT_OFFSET(InstancedDestructibleMeshNode, idleEffect, 0x80);
RED4EXT_ASSERT_OFFSET(InstancedDestructibleMeshNode, staticMesh, 0x88);
RED4EXT_ASSERT_OFFSET(InstancedDestructibleMeshNode, staticMeshAppearance, 0x90);
RED4EXT_ASSERT_OFFSET(InstancedDestructibleMeshNode, impulseToDamage, 0x98);
RED4EXT_ASSERT_OFFSET(InstancedDestructibleMeshNode, damageThreshold, 0x9C);
RED4EXT_ASSERT_OFFSET(InstancedDestructibleMeshNode, damageEndurance, 0xA0);
RED4EXT_ASSERT_OFFSET(InstancedDestructibleMeshNode, useAggregate, 0xA4);
RED4EXT_ASSERT_OFFSET(InstancedDestructibleMeshNode, enableSelfCollisionInAggregate, 0xA5);
RED4EXT_ASSERT_OFFSET(InstancedDestructibleMeshNode, startInactive, 0xA6);
RED4EXT_ASSERT_OFFSET(InstancedDestructibleMeshNode, turnDynamicOnImpulse, 0xA7);
RED4EXT_ASSERT_OFFSET(InstancedDestructibleMeshNode, isDestructible, 0xA8);
RED4EXT_ASSERT_OFFSET(InstancedDestructibleMeshNode, accumulateDamage, 0xA9);
RED4EXT_ASSERT_OFFSET(InstancedDestructibleMeshNode, isPierceable, 0xAA);
RED4EXT_ASSERT_OFFSET(InstancedDestructibleMeshNode, isWorkspot, 0xAB);
RED4EXT_ASSERT_OFFSET(InstancedDestructibleMeshNode, useMeshNavmeshSettings, 0xAC);
RED4EXT_ASSERT_OFFSET(InstancedDestructibleMeshNode, systemsToNotifyFlags, 0xAE);
RED4EXT_ASSERT_OFFSET(InstancedDestructibleMeshNode, instanceTransforms, 0xB0);
#else
RED4EXT_ASSERT_SIZE(InstancedDestructibleMeshNode, 0xC8);
#endif
} // namespace world
using worldInstancedDestructibleMeshNode = world::InstancedDestructibleMeshNode;
} // namespace RED4ext

// clang-format on
