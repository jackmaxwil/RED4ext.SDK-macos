#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/Scripting/Natives/Generated/game/ui/CharacterCustomization_BrokenNoseStage.hpp>
#include <RED4ext/Scripting/Natives/Generated/quest/ICharacterManagerVisuals_NodeSubType.hpp>

namespace RED4ext
{
namespace quest
{
struct CharacterManagerVisuals_SetBrokenNoseStage : quest::ICharacterManagerVisuals_NodeSubType
{
    static constexpr const char* NAME = "questCharacterManagerVisuals_SetBrokenNoseStage";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    game::ui::CharacterCustomization_BrokenNoseStage brokenNoseStage; // 6C
#else
    game::ui::CharacterCustomization_BrokenNoseStage brokenNoseStage; // 70
    uint8_t unk74[0x78 - 0x74]; // 74
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(CharacterManagerVisuals_SetBrokenNoseStage, 0x70);
RED4EXT_ASSERT_OFFSET(CharacterManagerVisuals_SetBrokenNoseStage, brokenNoseStage, 0x6C);
#else
RED4EXT_ASSERT_SIZE(CharacterManagerVisuals_SetBrokenNoseStage, 0x78);
#endif
} // namespace quest
using questCharacterManagerVisuals_SetBrokenNoseStage = quest::CharacterManagerVisuals_SetBrokenNoseStage;
} // namespace RED4ext

// clang-format on
