#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/Scripting/Natives/Generated/ent/PhysicalTriggerComponent.hpp>
#include <RED4ext/Scripting/Natives/Generated/physics/FractureFieldParams.hpp>

namespace RED4ext
{
namespace ent
{
struct __declspec(align(0x10)) PhysicalFractureFieldComponent : ent::PhysicalTriggerComponent
{
    static constexpr const char* NAME = "entPhysicalFractureFieldComponent";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    physics::FractureFieldParams fractureFieldParams; // 188
#else
    physics::FractureFieldParams fractureFieldParams; // 190
    uint8_t unk1A8[0x1B0 - 0x1A8]; // 1A8
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(PhysicalFractureFieldComponent, 0x1A0);
RED4EXT_ASSERT_OFFSET(PhysicalFractureFieldComponent, fractureFieldParams, 0x188);
#else
RED4EXT_ASSERT_SIZE(PhysicalFractureFieldComponent, 0x1B0);
#endif
} // namespace ent
using entPhysicalFractureFieldComponent = ent::PhysicalFractureFieldComponent;
} // namespace RED4ext

// clang-format on
