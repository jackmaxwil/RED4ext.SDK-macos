#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/Containers/StaticArray.hpp>
#include <RED4ext/Handle.hpp>
#include <RED4ext/Scripting/Natives/Generated/CResource.hpp>
#include <RED4ext/Scripting/Natives/Generated/move/MovementParameters.hpp>

namespace RED4ext
{
namespace AI::behavior { struct ParameterizedBehavior; }

namespace AI
{
struct Archetype : CResource
{
    static constexpr const char* NAME = "AIArchetype";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    uint8_t unk39[0x40 - 0x39]; // 39
    Handle<AI::behavior::ParameterizedBehavior> behaviorDefinition; // 40
    StaticArray<move::MovementParameters, 5> movementParameters; // 50
#else
    Handle<AI::behavior::ParameterizedBehavior> behaviorDefinition; // 40
    StaticArray<move::MovementParameters, 5> movementParameters; // 50
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(Archetype, 0xE0);
RED4EXT_ASSERT_OFFSET(Archetype, behaviorDefinition, 0x40);
RED4EXT_ASSERT_OFFSET(Archetype, movementParameters, 0x50);
#else
RED4EXT_ASSERT_SIZE(Archetype, 0xE0);
#endif
} // namespace AI
using AIArchetype = AI::Archetype;
} // namespace RED4ext

// clang-format on
