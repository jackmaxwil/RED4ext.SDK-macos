#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/CName.hpp>
#include <RED4ext/NativeTypes.hpp>
#include <RED4ext/Scripting/Natives/Generated/game/ActionReplicatedState.hpp>

namespace RED4ext
{
namespace game
{
struct ActionUnequipItemState : game::ActionReplicatedState
{
    static constexpr const char* NAME = "gameActionUnequipItemState";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    TweakDBID slotId; // 24
    uint8_t unk2C[0x30 - 0x2C]; // 2C
    CName animFeatureNameRight; // 30
    CName animFeatureNameLeft; // 38
    float duration; // 40
    uint8_t unk44[0x48 - 0x44]; // 44
#else
    TweakDBID slotId; // 28
    CName animFeatureNameRight; // 30
    CName animFeatureNameLeft; // 38
    float duration; // 40
    uint8_t unk44[0x48 - 0x44]; // 44
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(ActionUnequipItemState, 0x48);
RED4EXT_ASSERT_OFFSET(ActionUnequipItemState, slotId, 0x24);
RED4EXT_ASSERT_OFFSET(ActionUnequipItemState, animFeatureNameRight, 0x30);
RED4EXT_ASSERT_OFFSET(ActionUnequipItemState, animFeatureNameLeft, 0x38);
RED4EXT_ASSERT_OFFSET(ActionUnequipItemState, duration, 0x40);
#else
RED4EXT_ASSERT_SIZE(ActionUnequipItemState, 0x48);
#endif
} // namespace game
using gameActionUnequipItemState = game::ActionUnequipItemState;
} // namespace RED4ext

// clang-format on
