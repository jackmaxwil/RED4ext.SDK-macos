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
struct PhysicsJointAngularLimitPair : physics::PhysicsJointLimitBase
{
    static constexpr const char* NAME = "physicsPhysicsJointAngularLimitPair";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    float lower; // 1C
    float upper; // 20
    physics::PhysicsJointMotion twist; // 24
    uint8_t unk25[0x28 - 0x25]; // 25
#else
    float lower; // 20
    float upper; // 24
    physics::PhysicsJointMotion twist; // 28
    uint8_t unk29[0x30 - 0x29]; // 29
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(PhysicsJointAngularLimitPair, 0x28);
RED4EXT_ASSERT_OFFSET(PhysicsJointAngularLimitPair, lower, 0x1C);
RED4EXT_ASSERT_OFFSET(PhysicsJointAngularLimitPair, upper, 0x20);
RED4EXT_ASSERT_OFFSET(PhysicsJointAngularLimitPair, twist, 0x24);
#else
RED4EXT_ASSERT_SIZE(PhysicsJointAngularLimitPair, 0x30);
#endif
} // namespace physics
using physicsPhysicsJointAngularLimitPair = physics::PhysicsJointAngularLimitPair;
} // namespace RED4ext

// clang-format on
