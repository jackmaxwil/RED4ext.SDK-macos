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
struct ActionEquipItemState : game::ActionReplicatedState
{
    static constexpr const char* NAME = "gameActionEquipItemState";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    TweakDBID slotId; // 24
    ItemID itemId; // 2C
    uint8_t unk3C[0x40 - 0x3C]; // 3C
    CName animFeatureNameRight; // 40
    CName animFeatureNameLeft; // 48
    float duration; // 50
    float spawnDelay; // 54
#else
    TweakDBID slotId; // 28
    ItemID itemId; // 30
    CName animFeatureNameRight; // 40
    CName animFeatureNameLeft; // 48
    float duration; // 50
    float spawnDelay; // 54
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(ActionEquipItemState, 0x58);
RED4EXT_ASSERT_OFFSET(ActionEquipItemState, slotId, 0x24);
RED4EXT_ASSERT_OFFSET(ActionEquipItemState, itemId, 0x2C);
RED4EXT_ASSERT_OFFSET(ActionEquipItemState, animFeatureNameRight, 0x40);
RED4EXT_ASSERT_OFFSET(ActionEquipItemState, animFeatureNameLeft, 0x48);
RED4EXT_ASSERT_OFFSET(ActionEquipItemState, duration, 0x50);
RED4EXT_ASSERT_OFFSET(ActionEquipItemState, spawnDelay, 0x54);
#else
RED4EXT_ASSERT_SIZE(ActionEquipItemState, 0x58);
#endif
} // namespace game
using gameActionEquipItemState = game::ActionEquipItemState;
} // namespace RED4ext

// clang-format on
