#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/CName.hpp>
#include <RED4ext/NativeTypes.hpp>
#include <RED4ext/Scripting/Natives/Generated/ent/PhysicalMeshComponent.hpp>
#include <RED4ext/Scripting/Natives/Generated/physics/FractureFieldType.hpp>

namespace RED4ext
{
struct CMesh;
namespace world { struct Effect; }

namespace ent
{
struct __declspec(align(0x10)) BakedDestructionComponent : ent::PhysicalMeshComponent
{
    static constexpr const char* NAME = "entBakedDestructionComponent";
    static constexpr const char* ALIAS = "BakedDestructionComponent";

#ifdef __APPLE__
    uint8_t unk230[0x248 - 0x230]; // 230
    RaRef<world::Effect> destructionEffect; // 248
    RaRef<CMesh> meshFractured; // 250
    uint8_t unk258[0x288 - 0x258]; // 258
    CName audioMetadata; // 288
    CName meshFracturedAppearance; // 290
    uint8_t unk298[0x308 - 0x298]; // 298
    float damageThreshold; // 308
    float damageEndurance; // 30C
    float impulseToDamage; // 310
    float contactToDamage; // 314
    uint8_t unk318[0x320 - 0x318]; // 318
    float numFrames; // 320
    float frameRate; // 324
    physics::FractureFieldType fractureFieldMask; // 328
    bool playOnlyOnce; // 32A
    bool restartOnTrigger; // 32B
    bool disableCollidersOnTrigger; // 32C
    bool accumulateDamage; // 32D
    uint8_t unk32E[0x330 - 0x32E]; // 32E
#else
    uint8_t unk240[0x260 - 0x240]; // 240
    RaRef<world::Effect> destructionEffect; // 260
    RaRef<CMesh> meshFractured; // 268
    uint8_t unk270[0x2A0 - 0x270]; // 270
    CName audioMetadata; // 2A0
    CName meshFracturedAppearance; // 2A8
    uint8_t unk2B0[0x320 - 0x2B0]; // 2B0
    float damageThreshold; // 320
    float damageEndurance; // 324
    float impulseToDamage; // 328
    float contactToDamage; // 32C
    uint8_t unk330[0x338 - 0x330]; // 330
    float numFrames; // 338
    float frameRate; // 33C
    physics::FractureFieldType fractureFieldMask; // 340
    bool playOnlyOnce; // 342
    bool restartOnTrigger; // 343
    bool disableCollidersOnTrigger; // 344
    bool accumulateDamage; // 345
    uint8_t unk346[0x350 - 0x346]; // 346
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(BakedDestructionComponent, 0x330);
RED4EXT_ASSERT_OFFSET(BakedDestructionComponent, destructionEffect, 0x248);
RED4EXT_ASSERT_OFFSET(BakedDestructionComponent, meshFractured, 0x250);
RED4EXT_ASSERT_OFFSET(BakedDestructionComponent, audioMetadata, 0x288);
RED4EXT_ASSERT_OFFSET(BakedDestructionComponent, meshFracturedAppearance, 0x290);
RED4EXT_ASSERT_OFFSET(BakedDestructionComponent, damageThreshold, 0x308);
RED4EXT_ASSERT_OFFSET(BakedDestructionComponent, damageEndurance, 0x30C);
RED4EXT_ASSERT_OFFSET(BakedDestructionComponent, impulseToDamage, 0x310);
RED4EXT_ASSERT_OFFSET(BakedDestructionComponent, contactToDamage, 0x314);
RED4EXT_ASSERT_OFFSET(BakedDestructionComponent, numFrames, 0x320);
RED4EXT_ASSERT_OFFSET(BakedDestructionComponent, frameRate, 0x324);
RED4EXT_ASSERT_OFFSET(BakedDestructionComponent, fractureFieldMask, 0x328);
RED4EXT_ASSERT_OFFSET(BakedDestructionComponent, playOnlyOnce, 0x32A);
RED4EXT_ASSERT_OFFSET(BakedDestructionComponent, restartOnTrigger, 0x32B);
RED4EXT_ASSERT_OFFSET(BakedDestructionComponent, disableCollidersOnTrigger, 0x32C);
RED4EXT_ASSERT_OFFSET(BakedDestructionComponent, accumulateDamage, 0x32D);
#else
RED4EXT_ASSERT_SIZE(BakedDestructionComponent, 0x350);
#endif
} // namespace ent
using entBakedDestructionComponent = ent::BakedDestructionComponent;
using BakedDestructionComponent = ent::BakedDestructionComponent;
} // namespace RED4ext

// clang-format on
