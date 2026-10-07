#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/Scripting/Natives/Generated/Vector3.hpp>
#include <RED4ext/Scripting/Natives/Generated/ent/PhysicalTriggerComponent.hpp>

namespace RED4ext
{
namespace ent
{
struct __declspec(align(0x10)) PhysicalImpulseAreaComponent : ent::PhysicalTriggerComponent
{
    static constexpr const char* NAME = "entPhysicalImpulseAreaComponent";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    Vector3 impulse; // 188
    float impulseRadius; // 194
    uint8_t unk198[0x1A0 - 0x198]; // 198
#else
    Vector3 impulse; // 190
    float impulseRadius; // 19C
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(PhysicalImpulseAreaComponent, 0x1A0);
RED4EXT_ASSERT_OFFSET(PhysicalImpulseAreaComponent, impulse, 0x188);
RED4EXT_ASSERT_OFFSET(PhysicalImpulseAreaComponent, impulseRadius, 0x194);
#else
RED4EXT_ASSERT_SIZE(PhysicalImpulseAreaComponent, 0x1A0);
#endif
} // namespace ent
using entPhysicalImpulseAreaComponent = ent::PhysicalImpulseAreaComponent;
} // namespace RED4ext

// clang-format on
