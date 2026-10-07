#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/Scripting/Natives/Generated/ent/PhysicalTriggerComponent.hpp>

namespace RED4ext
{
namespace ent
{
struct __declspec(align(0x10)) TriggerComponent : ent::PhysicalTriggerComponent
{
    static constexpr const char* NAME = "entTriggerComponent";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    uint8_t unk188[0x190 - 0x188]; // 188
#else
    uint8_t unk190[0x1A0 - 0x190]; // 190
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(TriggerComponent, 0x190);
#else
RED4EXT_ASSERT_SIZE(TriggerComponent, 0x1A0);
#endif
} // namespace ent
using entTriggerComponent = ent::TriggerComponent;
} // namespace RED4ext

// clang-format on
