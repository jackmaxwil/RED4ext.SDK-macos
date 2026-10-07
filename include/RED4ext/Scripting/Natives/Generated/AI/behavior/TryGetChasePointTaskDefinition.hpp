#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/Handle.hpp>
#include <RED4ext/Scripting/Natives/Generated/AI/behavior/TaskDefinition.hpp>

namespace RED4ext
{
namespace AI { struct ArgumentMapping; }

namespace AI::behavior
{
struct TryGetChasePointTaskDefinition : AI::behavior::TaskDefinition
{
    static constexpr const char* NAME = "AIbehaviorTryGetChasePointTaskDefinition";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    uint8_t unk31[0x38 - 0x31]; // 31
    Handle<AI::ArgumentMapping> inPlayerPositionDelay; // 38
    Handle<AI::ArgumentMapping> inPlayerPositionMaxDistance; // 48
    Handle<AI::ArgumentMapping> inNearestNavmeshPolyExtent; // 58
    Handle<AI::ArgumentMapping> outChasePosition; // 68
#else
    Handle<AI::ArgumentMapping> inPlayerPositionDelay; // 38
    Handle<AI::ArgumentMapping> inPlayerPositionMaxDistance; // 48
    Handle<AI::ArgumentMapping> inNearestNavmeshPolyExtent; // 58
    Handle<AI::ArgumentMapping> outChasePosition; // 68
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(TryGetChasePointTaskDefinition, 0x78);
RED4EXT_ASSERT_OFFSET(TryGetChasePointTaskDefinition, inPlayerPositionDelay, 0x38);
RED4EXT_ASSERT_OFFSET(TryGetChasePointTaskDefinition, inPlayerPositionMaxDistance, 0x48);
RED4EXT_ASSERT_OFFSET(TryGetChasePointTaskDefinition, inNearestNavmeshPolyExtent, 0x58);
RED4EXT_ASSERT_OFFSET(TryGetChasePointTaskDefinition, outChasePosition, 0x68);
#else
RED4EXT_ASSERT_SIZE(TryGetChasePointTaskDefinition, 0x78);
#endif
} // namespace AI::behavior
using AIbehaviorTryGetChasePointTaskDefinition = AI::behavior::TryGetChasePointTaskDefinition;
} // namespace RED4ext

// clang-format on
