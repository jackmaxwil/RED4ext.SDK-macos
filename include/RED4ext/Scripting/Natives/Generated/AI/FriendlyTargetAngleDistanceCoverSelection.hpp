#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/Scripting/Natives/Generated/AI/CoverSelectionParameters.hpp>

namespace RED4ext
{
namespace AI
{
struct FriendlyTargetAngleDistanceCoverSelection : AI::CoverSelectionParameters
{
    static constexpr const char* NAME = "AIFriendlyTargetAngleDistanceCoverSelection";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    uint8_t unk10[0x20 - 0x10]; // 10
#else
    uint8_t unk10[0x28 - 0x10]; // 10
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(FriendlyTargetAngleDistanceCoverSelection, 0x20);
#else
RED4EXT_ASSERT_SIZE(FriendlyTargetAngleDistanceCoverSelection, 0x28);
#endif
} // namespace AI
using AIFriendlyTargetAngleDistanceCoverSelection = AI::FriendlyTargetAngleDistanceCoverSelection;
} // namespace RED4ext

// clang-format on
