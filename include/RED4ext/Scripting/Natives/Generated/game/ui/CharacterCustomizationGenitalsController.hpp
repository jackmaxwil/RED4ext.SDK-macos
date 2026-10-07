#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/CName.hpp>
#include <RED4ext/Scripting/Natives/Generated/game/ui/CharacterCustomizationBodyPartsController.hpp>

namespace RED4ext
{
namespace game::ui
{
struct CharacterCustomizationGenitalsController : game::ui::CharacterCustomizationBodyPartsController
{
    static constexpr const char* NAME = "gameuiCharacterCustomizationGenitalsController";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    CName upperBodyGroupName; // B8
    CName bottomBodyGroupName; // C0
    bool forceHideGenitals; // C8
    uint8_t unkC9[0x178 - 0xC9]; // C9
#else
    CName upperBodyGroupName; // C0
    CName bottomBodyGroupName; // C8
    bool forceHideGenitals; // D0
    uint8_t unkD1[0x180 - 0xD1]; // D1
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(CharacterCustomizationGenitalsController, 0x178);
RED4EXT_ASSERT_OFFSET(CharacterCustomizationGenitalsController, upperBodyGroupName, 0xB8);
RED4EXT_ASSERT_OFFSET(CharacterCustomizationGenitalsController, bottomBodyGroupName, 0xC0);
RED4EXT_ASSERT_OFFSET(CharacterCustomizationGenitalsController, forceHideGenitals, 0xC8);
#else
RED4EXT_ASSERT_SIZE(CharacterCustomizationGenitalsController, 0x180);
#endif
} // namespace game::ui
using gameuiCharacterCustomizationGenitalsController = game::ui::CharacterCustomizationGenitalsController;
} // namespace RED4ext

// clang-format on
