#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/Scripting/Natives/Generated/physics/ICollider.hpp>

namespace RED4ext
{
namespace physics
{
struct __declspec(align(0x10)) ColliderCapsule : physics::ICollider
{
    static constexpr const char* NAME = "physicsColliderCapsule";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    float radius; // 88
    float height; // 8C
#else
    float radius; // 90
    float height; // 94
    uint8_t unk98[0xA0 - 0x98]; // 98
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(ColliderCapsule, 0x90);
RED4EXT_ASSERT_OFFSET(ColliderCapsule, radius, 0x88);
RED4EXT_ASSERT_OFFSET(ColliderCapsule, height, 0x8C);
#else
RED4EXT_ASSERT_SIZE(ColliderCapsule, 0xA0);
#endif
} // namespace physics
using physicsColliderCapsule = physics::ColliderCapsule;
} // namespace RED4ext

// clang-format on
