#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/CName.hpp>
#include <RED4ext/Handle.hpp>
#include <RED4ext/Scripting/Natives/Generated/AI/behavior/ConditionDefinition.hpp>

namespace RED4ext
{
namespace AI { struct ArgumentMapping; }

namespace AI::behavior
{
struct WaitingMountCommandConditionDefinition : AI::behavior::ConditionDefinition
{
    static constexpr const char* NAME = "AIbehaviorWaitingMountCommandConditionDefinition";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    uint8_t unk34[0x38 - 0x34]; // 34
    Handle<AI::ArgumentMapping> requestArgument; // 38
    CName callbackName; // 48
#else
    Handle<AI::ArgumentMapping> requestArgument; // 38
    CName callbackName; // 48
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(WaitingMountCommandConditionDefinition, 0x50);
RED4EXT_ASSERT_OFFSET(WaitingMountCommandConditionDefinition, requestArgument, 0x38);
RED4EXT_ASSERT_OFFSET(WaitingMountCommandConditionDefinition, callbackName, 0x48);
#else
RED4EXT_ASSERT_SIZE(WaitingMountCommandConditionDefinition, 0x50);
#endif
} // namespace AI::behavior
using AIbehaviorWaitingMountCommandConditionDefinition = AI::behavior::WaitingMountCommandConditionDefinition;
} // namespace RED4ext

// clang-format on
