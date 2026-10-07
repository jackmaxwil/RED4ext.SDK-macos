#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/CName.hpp>
#include <RED4ext/Handle.hpp>
#include <RED4ext/Scripting/Natives/Generated/AI/behavior/TaskDefinition.hpp>

namespace RED4ext
{
namespace AI { struct ArgumentMapping; }

namespace AI::behavior
{
struct SelectCoverTaskDefinition : AI::behavior::TaskDefinition
{
    static constexpr const char* NAME = "AIbehaviorSelectCoverTaskDefinition";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    uint8_t unk31[0x38 - 0x31]; // 31
    CName sectorSelection; // 38
    Handle<AI::ArgumentMapping> cover; // 40
    Handle<AI::ArgumentMapping> coverID; // 50
    Handle<AI::ArgumentMapping> multiCoverID; // 60
    Handle<AI::ArgumentMapping> combatTarget; // 70
    Handle<AI::ArgumentMapping> friendlyTarget; // 80
    Handle<AI::ArgumentMapping> combatZone; // 90
    Handle<AI::ArgumentMapping> ignoreRestrictMovementArea; // A0
    Handle<AI::ArgumentMapping> selectionPreset; // B0
    Handle<AI::ArgumentMapping> onActivationSelectionPreset; // C0
    Handle<AI::ArgumentMapping> secondStagePreset; // D0
    Handle<AI::ArgumentMapping> coverChangeThreshold; // E0
    Handle<AI::ArgumentMapping> coverGatheringCenterObject; // F0
    Handle<AI::ArgumentMapping> coverDisablingDuration; // 100
#else
    CName sectorSelection; // 38
    Handle<AI::ArgumentMapping> cover; // 40
    Handle<AI::ArgumentMapping> coverID; // 50
    Handle<AI::ArgumentMapping> multiCoverID; // 60
    Handle<AI::ArgumentMapping> combatTarget; // 70
    Handle<AI::ArgumentMapping> friendlyTarget; // 80
    Handle<AI::ArgumentMapping> combatZone; // 90
    Handle<AI::ArgumentMapping> ignoreRestrictMovementArea; // A0
    Handle<AI::ArgumentMapping> selectionPreset; // B0
    Handle<AI::ArgumentMapping> onActivationSelectionPreset; // C0
    Handle<AI::ArgumentMapping> secondStagePreset; // D0
    Handle<AI::ArgumentMapping> coverChangeThreshold; // E0
    Handle<AI::ArgumentMapping> coverGatheringCenterObject; // F0
    Handle<AI::ArgumentMapping> coverDisablingDuration; // 100
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(SelectCoverTaskDefinition, 0x110);
RED4EXT_ASSERT_OFFSET(SelectCoverTaskDefinition, sectorSelection, 0x38);
RED4EXT_ASSERT_OFFSET(SelectCoverTaskDefinition, cover, 0x40);
RED4EXT_ASSERT_OFFSET(SelectCoverTaskDefinition, coverID, 0x50);
RED4EXT_ASSERT_OFFSET(SelectCoverTaskDefinition, multiCoverID, 0x60);
RED4EXT_ASSERT_OFFSET(SelectCoverTaskDefinition, combatTarget, 0x70);
RED4EXT_ASSERT_OFFSET(SelectCoverTaskDefinition, friendlyTarget, 0x80);
RED4EXT_ASSERT_OFFSET(SelectCoverTaskDefinition, combatZone, 0x90);
RED4EXT_ASSERT_OFFSET(SelectCoverTaskDefinition, ignoreRestrictMovementArea, 0xA0);
RED4EXT_ASSERT_OFFSET(SelectCoverTaskDefinition, selectionPreset, 0xB0);
RED4EXT_ASSERT_OFFSET(SelectCoverTaskDefinition, onActivationSelectionPreset, 0xC0);
RED4EXT_ASSERT_OFFSET(SelectCoverTaskDefinition, secondStagePreset, 0xD0);
RED4EXT_ASSERT_OFFSET(SelectCoverTaskDefinition, coverChangeThreshold, 0xE0);
RED4EXT_ASSERT_OFFSET(SelectCoverTaskDefinition, coverGatheringCenterObject, 0xF0);
RED4EXT_ASSERT_OFFSET(SelectCoverTaskDefinition, coverDisablingDuration, 0x100);
#else
RED4EXT_ASSERT_SIZE(SelectCoverTaskDefinition, 0x110);
#endif
} // namespace AI::behavior
using AIbehaviorSelectCoverTaskDefinition = AI::behavior::SelectCoverTaskDefinition;
} // namespace RED4ext

// clang-format on
