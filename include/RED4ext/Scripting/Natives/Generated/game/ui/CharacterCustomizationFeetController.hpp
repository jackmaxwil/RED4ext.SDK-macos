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
struct CharacterCustomizationFeetController : game::ui::CharacterCustomizationBodyPartsController
{
    static constexpr const char* NAME = "gameuiCharacterCustomizationFeetController";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    CName liftedFeetGroupName; // B8
    CName flatFeetGroupName; // C0
    uint8_t unkC8[0x168 - 0xC8]; // C8
#else
    CName liftedFeetGroupName; // C0
    CName flatFeetGroupName; // C8
    uint8_t unkD0[0x170 - 0xD0]; // D0
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(CharacterCustomizationFeetController, 0x168);
RED4EXT_ASSERT_OFFSET(CharacterCustomizationFeetController, liftedFeetGroupName, 0xB8);
RED4EXT_ASSERT_OFFSET(CharacterCustomizationFeetController, flatFeetGroupName, 0xC0);
#else
RED4EXT_ASSERT_SIZE(CharacterCustomizationFeetController, 0x170);
#endif
} // namespace game::ui
using gameuiCharacterCustomizationFeetController = game::ui::CharacterCustomizationFeetController;
} // namespace RED4ext

// clang-format on
