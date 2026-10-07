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
struct CharacterCustomizationHeadPartsController : game::ui::CharacterCustomizationBodyPartsController
{
    static constexpr const char* NAME = "gameuiCharacterCustomizationHeadPartsController";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    CName groupName; // B8
    uint8_t unkC0[0x118 - 0xC0]; // C0
#else
    CName groupName; // C0
    uint8_t unkC8[0x120 - 0xC8]; // C8
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(CharacterCustomizationHeadPartsController, 0x118);
RED4EXT_ASSERT_OFFSET(CharacterCustomizationHeadPartsController, groupName, 0xB8);
#else
RED4EXT_ASSERT_SIZE(CharacterCustomizationHeadPartsController, 0x120);
#endif
} // namespace game::ui
using gameuiCharacterCustomizationHeadPartsController = game::ui::CharacterCustomizationHeadPartsController;
} // namespace RED4ext

// clang-format on
