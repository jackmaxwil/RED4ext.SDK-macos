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
struct ExtractMountDataTaskDefinition : AI::behavior::TaskDefinition
{
    static constexpr const char* NAME = "AIbehaviorExtractMountDataTaskDefinition";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    uint8_t unk31[0x38 - 0x31]; // 31
    Handle<AI::ArgumentMapping> mountEventData; // 38
    Handle<AI::ArgumentMapping> outWorkspotData; // 48
    Handle<AI::ArgumentMapping> outIsInstant; // 58
    Handle<AI::ArgumentMapping> outAllowFailsafeTeleport; // 68
#else
    Handle<AI::ArgumentMapping> mountEventData; // 38
    Handle<AI::ArgumentMapping> outWorkspotData; // 48
    Handle<AI::ArgumentMapping> outIsInstant; // 58
    Handle<AI::ArgumentMapping> outAllowFailsafeTeleport; // 68
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(ExtractMountDataTaskDefinition, 0x78);
RED4EXT_ASSERT_OFFSET(ExtractMountDataTaskDefinition, mountEventData, 0x38);
RED4EXT_ASSERT_OFFSET(ExtractMountDataTaskDefinition, outWorkspotData, 0x48);
RED4EXT_ASSERT_OFFSET(ExtractMountDataTaskDefinition, outIsInstant, 0x58);
RED4EXT_ASSERT_OFFSET(ExtractMountDataTaskDefinition, outAllowFailsafeTeleport, 0x68);
#else
RED4EXT_ASSERT_SIZE(ExtractMountDataTaskDefinition, 0x78);
#endif
} // namespace AI::behavior
using AIbehaviorExtractMountDataTaskDefinition = AI::behavior::ExtractMountDataTaskDefinition;
} // namespace RED4ext

// clang-format on
