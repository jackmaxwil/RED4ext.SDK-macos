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
struct UtilityLossCoverSelection : AI::CoverSelectionParameters
{
    static constexpr const char* NAME = "AIUtilityLossCoverSelection";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    uint8_t unk10[0x28 - 0x10]; // 10
#else
    uint8_t unk10[0x30 - 0x10]; // 10
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(UtilityLossCoverSelection, 0x28);
#else
RED4EXT_ASSERT_SIZE(UtilityLossCoverSelection, 0x30);
#endif
} // namespace AI
using AIUtilityLossCoverSelection = AI::UtilityLossCoverSelection;
} // namespace RED4ext

// clang-format on
