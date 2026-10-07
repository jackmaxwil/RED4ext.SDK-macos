#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>

namespace RED4ext
{
namespace physics
{
struct PhysicsJointLimitBase
{
    static constexpr const char* NAME = "physicsPhysicsJointLimitBase";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    alignas(8) uint8_t unk00[0x8 - 0x0]; // 0
    float restitution; // 08
    float bounceThreshold; // 0C
    float stiffness; // 10
    float damping; // 14
    float contactDistance; // 18
    ~PhysicsJointLimitBase() {} // non-POD, so clang reuses the tail padding like the game
#else
    uint8_t unk00[0x8 - 0x0]; // 0
    float restitution; // 08
    float bounceThreshold; // 0C
    float stiffness; // 10
    float damping; // 14
    float contactDistance; // 18
    uint8_t unk1C[0x20 - 0x1C]; // 1C
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(PhysicsJointLimitBase, 0x20);
RED4EXT_ASSERT_OFFSET(PhysicsJointLimitBase, restitution, 0x8);
RED4EXT_ASSERT_OFFSET(PhysicsJointLimitBase, bounceThreshold, 0xC);
RED4EXT_ASSERT_OFFSET(PhysicsJointLimitBase, stiffness, 0x10);
RED4EXT_ASSERT_OFFSET(PhysicsJointLimitBase, damping, 0x14);
RED4EXT_ASSERT_OFFSET(PhysicsJointLimitBase, contactDistance, 0x18);
#else
RED4EXT_ASSERT_SIZE(PhysicsJointLimitBase, 0x20);
#endif
} // namespace physics
using physicsPhysicsJointLimitBase = physics::PhysicsJointLimitBase;
} // namespace RED4ext

// clang-format on
