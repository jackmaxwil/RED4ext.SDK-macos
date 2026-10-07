#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/CName.hpp>
#include <RED4ext/Scripting/Natives/Generated/game/ui/CharacterCustomizationBrokenNoseControllerBrokenNoseAppearance.hpp>
#include <RED4ext/Scripting/Natives/Generated/game/ui/ICharacterCustomizationComponent.hpp>

namespace RED4ext
{
namespace game::ui
{
struct CharacterCustomizationBrokenNoseController : game::ui::ICharacterCustomizationComponent
{
    static constexpr const char* NAME = "gameuiCharacterCustomizationBrokenNoseController";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    game::ui::CharacterCustomizationBrokenNoseControllerBrokenNoseAppearance stage1App; // 90
    game::ui::CharacterCustomizationBrokenNoseControllerBrokenNoseAppearance stage2App; // A0
    CName finalSceneGroup; // B0
    uint8_t unkB8[0xD0 - 0xB8]; // B8
#else
    game::ui::CharacterCustomizationBrokenNoseControllerBrokenNoseAppearance stage1App; // 98
    game::ui::CharacterCustomizationBrokenNoseControllerBrokenNoseAppearance stage2App; // A8
    CName finalSceneGroup; // B8
    uint8_t unkC0[0xD8 - 0xC0]; // C0
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(CharacterCustomizationBrokenNoseController, 0xD0);
RED4EXT_ASSERT_OFFSET(CharacterCustomizationBrokenNoseController, stage1App, 0x90);
RED4EXT_ASSERT_OFFSET(CharacterCustomizationBrokenNoseController, stage2App, 0xA0);
RED4EXT_ASSERT_OFFSET(CharacterCustomizationBrokenNoseController, finalSceneGroup, 0xB0);
#else
RED4EXT_ASSERT_SIZE(CharacterCustomizationBrokenNoseController, 0xD8);
#endif
} // namespace game::ui
using gameuiCharacterCustomizationBrokenNoseController = game::ui::CharacterCustomizationBrokenNoseController;
} // namespace RED4ext

// clang-format on
