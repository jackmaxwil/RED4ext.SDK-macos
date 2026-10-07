#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/Scripting/Natives/Generated/Vector3.hpp>
#include <RED4ext/Scripting/Natives/Generated/physics/ICollider.hpp>

namespace RED4ext
{
namespace physics
{
struct __declspec(align(0x10)) ColliderBox : physics::ICollider
{
    static constexpr const char* NAME = "physicsColliderBox";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    Vector3 halfExtents; // 88
    bool isObstacle; // 94
    uint8_t unk95[0xA0 - 0x95]; // 95
#else
    Vector3 halfExtents; // 90
    bool isObstacle; // 9C
    uint8_t unk9D[0xA0 - 0x9D]; // 9D
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(ColliderBox, 0xA0);
RED4EXT_ASSERT_OFFSET(ColliderBox, halfExtents, 0x88);
RED4EXT_ASSERT_OFFSET(ColliderBox, isObstacle, 0x94);
#else
RED4EXT_ASSERT_SIZE(ColliderBox, 0xA0);
#endif
} // namespace physics
using physicsColliderBox = physics::ColliderBox;
} // namespace RED4ext

// clang-format on
