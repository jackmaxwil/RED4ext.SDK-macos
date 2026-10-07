#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/Scripting/Natives/Generated/game/ui/ICharacterCustomizationBodyController.hpp>

namespace RED4ext
{
namespace game::ui
{
struct CharacterCustomizationBodyController : game::ui::ICharacterCustomizationBodyController
{
    static constexpr const char* NAME = "gameuiCharacterCustomizationBodyController";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    uint8_t unk90[0xB0 - 0x90]; // 90
#else
    uint8_t unk98[0xB8 - 0x98]; // 98
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(CharacterCustomizationBodyController, 0xB0);
#else
RED4EXT_ASSERT_SIZE(CharacterCustomizationBodyController, 0xB8);
#endif
} // namespace game::ui
using gameuiCharacterCustomizationBodyController = game::ui::CharacterCustomizationBodyController;
} // namespace RED4ext

// clang-format on
