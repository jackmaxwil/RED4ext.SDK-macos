#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/CName.hpp>
#include <RED4ext/Handle.hpp>
#include <RED4ext/NativeTypes.hpp>
#include <RED4ext/Scripting/Natives/Generated/NavGenNavigationSetting.hpp>
#include <RED4ext/Scripting/Natives/Generated/physics/FilterDataSource.hpp>
#include <RED4ext/Scripting/Natives/Generated/physics/FractureFieldType.hpp>
#include <RED4ext/Scripting/Natives/Generated/world/MeshNode.hpp>

namespace RED4ext
{
struct CMesh;
namespace physics { struct FilterData; }
namespace world { struct Effect; }

namespace world
{
struct BakedDestructionNode : world::MeshNode
{
    static constexpr const char* NAME = "worldBakedDestructionNode";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    uint8_t unk5A[0x60 - 0x5A]; // 5A
    Handle<physics::FilterData> filterData; // 60
    RaRef<world::Effect> destructionEffect; // 70
    RaRef<CMesh> meshFractured; // 78
    CName audioMetadata; // 80
    CName meshFracturedAppearance; // 88
    physics::FilterDataSource filterDataSource; // 90
    uint8_t unk91[0x94 - 0x91]; // 91
    float damageThreshold; // 94
    float damageEndurance; // 98
    float impulseToDamage; // 9C
    float contactToDamage; // A0
    float numFrames; // A4
    float frameRate; // A8
    physics::FractureFieldType fractureFieldMask; // AC
    bool playOnlyOnce; // AE
    bool restartOnTrigger; // AF
    bool disableCollidersOnTrigger; // B0
    bool useMeshNavmeshSettings; // B1
    bool accumulateDamage; // B2
    uint8_t unkB3[0xB4 - 0xB3]; // B3
    NavGenNavigationSetting navigationSetting; // B4
    uint8_t unkB6[0xB8 - 0xB6]; // B6
#else
    Handle<physics::FilterData> filterData; // 60
    RaRef<world::Effect> destructionEffect; // 70
    RaRef<CMesh> meshFractured; // 78
    CName audioMetadata; // 80
    CName meshFracturedAppearance; // 88
    physics::FilterDataSource filterDataSource; // 90
    uint8_t unk91[0x94 - 0x91]; // 91
    float damageThreshold; // 94
    float damageEndurance; // 98
    float impulseToDamage; // 9C
    float contactToDamage; // A0
    float numFrames; // A4
    float frameRate; // A8
    physics::FractureFieldType fractureFieldMask; // AC
    bool playOnlyOnce; // AE
    bool restartOnTrigger; // AF
    bool disableCollidersOnTrigger; // B0
    bool useMeshNavmeshSettings; // B1
    bool accumulateDamage; // B2
    uint8_t unkB3[0xB4 - 0xB3]; // B3
    NavGenNavigationSetting navigationSetting; // B4
    uint8_t unkB6[0xB8 - 0xB6]; // B6
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(BakedDestructionNode, 0xB8);
RED4EXT_ASSERT_OFFSET(BakedDestructionNode, filterData, 0x60);
RED4EXT_ASSERT_OFFSET(BakedDestructionNode, destructionEffect, 0x70);
RED4EXT_ASSERT_OFFSET(BakedDestructionNode, meshFractured, 0x78);
RED4EXT_ASSERT_OFFSET(BakedDestructionNode, audioMetadata, 0x80);
RED4EXT_ASSERT_OFFSET(BakedDestructionNode, meshFracturedAppearance, 0x88);
RED4EXT_ASSERT_OFFSET(BakedDestructionNode, filterDataSource, 0x90);
RED4EXT_ASSERT_OFFSET(BakedDestructionNode, damageThreshold, 0x94);
RED4EXT_ASSERT_OFFSET(BakedDestructionNode, damageEndurance, 0x98);
RED4EXT_ASSERT_OFFSET(BakedDestructionNode, impulseToDamage, 0x9C);
RED4EXT_ASSERT_OFFSET(BakedDestructionNode, contactToDamage, 0xA0);
RED4EXT_ASSERT_OFFSET(BakedDestructionNode, numFrames, 0xA4);
RED4EXT_ASSERT_OFFSET(BakedDestructionNode, frameRate, 0xA8);
RED4EXT_ASSERT_OFFSET(BakedDestructionNode, fractureFieldMask, 0xAC);
RED4EXT_ASSERT_OFFSET(BakedDestructionNode, playOnlyOnce, 0xAE);
RED4EXT_ASSERT_OFFSET(BakedDestructionNode, restartOnTrigger, 0xAF);
RED4EXT_ASSERT_OFFSET(BakedDestructionNode, disableCollidersOnTrigger, 0xB0);
RED4EXT_ASSERT_OFFSET(BakedDestructionNode, useMeshNavmeshSettings, 0xB1);
RED4EXT_ASSERT_OFFSET(BakedDestructionNode, accumulateDamage, 0xB2);
RED4EXT_ASSERT_OFFSET(BakedDestructionNode, navigationSetting, 0xB4);
#else
RED4EXT_ASSERT_SIZE(BakedDestructionNode, 0xB8);
#endif
} // namespace world
using worldBakedDestructionNode = world::BakedDestructionNode;
} // namespace RED4ext

// clang-format on
