#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/NativeTypes.hpp>
#include <RED4ext/Scripting/Natives/Generated/world/ITriggerAreaNotifer.hpp>

namespace RED4ext
{
namespace ent
{
struct TriggerNotifier_Entity : world::ITriggerAreaNotifer
{
    static constexpr const char* NAME = "entTriggerNotifier_Entity";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    uint8_t unkB2[0xB8 - 0xB2]; // B2
    NodeRef entityRef; // B8
#else
    NodeRef entityRef; // B8
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(TriggerNotifier_Entity, 0xC0);
RED4EXT_ASSERT_OFFSET(TriggerNotifier_Entity, entityRef, 0xB8);
#else
RED4EXT_ASSERT_SIZE(TriggerNotifier_Entity, 0xC0);
#endif
} // namespace ent
using entTriggerNotifier_Entity = ent::TriggerNotifier_Entity;
} // namespace RED4ext

// clang-format on
