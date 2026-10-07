#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/CName.hpp>
#include <RED4ext/Handle.hpp>
#include <RED4ext/Scripting/Natives/Generated/game/EntityReference.hpp>
#include <RED4ext/Scripting/Natives/Generated/quest/SignalStoppingNodeDefinition.hpp>

namespace RED4ext
{
namespace quest { struct TransformAnimatorNode_ActionType; }

namespace quest
{
struct TransformAnimatorNodeDefinition : quest::SignalStoppingNodeDefinition
{
    static constexpr const char* NAME = "questTransformAnimatorNodeDefinition";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    uint8_t unk42[0x48 - 0x42]; // 42
    game::EntityReference objectRef; // 48
    CName animationName; // 80
    Handle<quest::TransformAnimatorNode_ActionType> action; // 88
#else
    game::EntityReference objectRef; // 48
    CName animationName; // 80
    Handle<quest::TransformAnimatorNode_ActionType> action; // 88
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(TransformAnimatorNodeDefinition, 0x98);
RED4EXT_ASSERT_OFFSET(TransformAnimatorNodeDefinition, objectRef, 0x48);
RED4EXT_ASSERT_OFFSET(TransformAnimatorNodeDefinition, animationName, 0x80);
RED4EXT_ASSERT_OFFSET(TransformAnimatorNodeDefinition, action, 0x88);
#else
RED4EXT_ASSERT_SIZE(TransformAnimatorNodeDefinition, 0x98);
#endif
} // namespace quest
using questTransformAnimatorNodeDefinition = quest::TransformAnimatorNodeDefinition;
} // namespace RED4ext

// clang-format on
