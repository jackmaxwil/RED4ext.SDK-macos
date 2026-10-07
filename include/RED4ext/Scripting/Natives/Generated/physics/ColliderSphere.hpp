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
struct __declspec(align(0x10)) ColliderSphere : physics::ICollider
{
    static constexpr const char* NAME = "physicsColliderSphere";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    float radius; // 88
    uint8_t unk8C[0x90 - 0x8C]; // 8C
#else
    float radius; // 90
    uint8_t unk94[0xA0 - 0x94]; // 94
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(ColliderSphere, 0x90);
RED4EXT_ASSERT_OFFSET(ColliderSphere, radius, 0x88);
#else
RED4EXT_ASSERT_SIZE(ColliderSphere, 0xA0);
#endif
} // namespace physics
using physicsColliderSphere = physics::ColliderSphere;
} // namespace RED4ext

// clang-format on
