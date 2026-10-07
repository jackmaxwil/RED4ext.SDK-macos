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
struct OwnerThreatCoverSelection : AI::CoverSelectionParameters
{
    static constexpr const char* NAME = "AIOwnerThreatCoverSelection";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
#else
    uint8_t unk10[0x18 - 0x10]; // 10
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(OwnerThreatCoverSelection, 0x10);
#else
RED4EXT_ASSERT_SIZE(OwnerThreatCoverSelection, 0x18);
#endif
} // namespace AI
using AIOwnerThreatCoverSelection = AI::OwnerThreatCoverSelection;
} // namespace RED4ext

// clang-format on
