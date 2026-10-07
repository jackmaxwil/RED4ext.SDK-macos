#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/Scripting/Natives/Generated/physics/PhysicsJointLimitBase.hpp>
#include <RED4ext/Scripting/Natives/Generated/physics/PhysicsJointMotion.hpp>

namespace RED4ext
{
namespace physics
{
struct PhysicsJointLimitConePair : physics::PhysicsJointLimitBase
{
    static constexpr const char* NAME = "physicsPhysicsJointLimitConePair";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    float yAngle; // 1C
    float zAngle; // 20
    physics::PhysicsJointMotion swingY; // 24
    physics::PhysicsJointMotion swingZ; // 25
    uint8_t unk26[0x28 - 0x26]; // 26
#else
    float yAngle; // 20
    float zAngle; // 24
    physics::PhysicsJointMotion swingY; // 28
    physics::PhysicsJointMotion swingZ; // 29
    uint8_t unk2A[0x30 - 0x2A]; // 2A
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(PhysicsJointLimitConePair, 0x28);
RED4EXT_ASSERT_OFFSET(PhysicsJointLimitConePair, yAngle, 0x1C);
RED4EXT_ASSERT_OFFSET(PhysicsJointLimitConePair, zAngle, 0x20);
RED4EXT_ASSERT_OFFSET(PhysicsJointLimitConePair, swingY, 0x24);
RED4EXT_ASSERT_OFFSET(PhysicsJointLimitConePair, swingZ, 0x25);
#else
RED4EXT_ASSERT_SIZE(PhysicsJointLimitConePair, 0x30);
#endif
} // namespace physics
using physicsPhysicsJointLimitConePair = physics::PhysicsJointLimitConePair;
} // namespace RED4ext

// clang-format on
