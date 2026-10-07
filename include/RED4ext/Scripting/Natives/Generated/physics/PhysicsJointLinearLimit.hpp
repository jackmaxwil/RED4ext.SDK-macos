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
struct PhysicsJointLinearLimit : physics::PhysicsJointLimitBase
{
    static constexpr const char* NAME = "physicsPhysicsJointLinearLimit";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    float value; // 1C
    physics::PhysicsJointMotion x; // 20
    physics::PhysicsJointMotion y; // 21
    physics::PhysicsJointMotion z; // 22
    uint8_t unk23[0x28 - 0x23]; // 23
#else
    float value; // 20
    physics::PhysicsJointMotion x; // 24
    physics::PhysicsJointMotion y; // 25
    physics::PhysicsJointMotion z; // 26
    uint8_t unk27[0x28 - 0x27]; // 27
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(PhysicsJointLinearLimit, 0x28);
RED4EXT_ASSERT_OFFSET(PhysicsJointLinearLimit, value, 0x1C);
RED4EXT_ASSERT_OFFSET(PhysicsJointLinearLimit, x, 0x20);
RED4EXT_ASSERT_OFFSET(PhysicsJointLinearLimit, y, 0x21);
RED4EXT_ASSERT_OFFSET(PhysicsJointLinearLimit, z, 0x22);
#else
RED4EXT_ASSERT_SIZE(PhysicsJointLinearLimit, 0x28);
#endif
} // namespace physics
using physicsPhysicsJointLinearLimit = physics::PhysicsJointLinearLimit;
} // namespace RED4ext

// clang-format on
