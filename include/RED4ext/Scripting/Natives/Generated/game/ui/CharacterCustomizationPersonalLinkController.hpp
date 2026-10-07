#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/CName.hpp>
#include <RED4ext/Scripting/Natives/Generated/game/ui/ICharacterCustomizationComponent.hpp>

namespace RED4ext
{
namespace game::ui
{
struct CharacterCustomizationPersonalLinkController : game::ui::ICharacterCustomizationComponent
{
    static constexpr const char* NAME = "gameuiCharacterCustomizationPersonalLinkController";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    CName simpleLinkGroup; // 90
    uint8_t unk98[0xC0 - 0x98]; // 98
#else
    CName simpleLinkGroup; // 98
    uint8_t unkA0[0xC8 - 0xA0]; // A0
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(CharacterCustomizationPersonalLinkController, 0xC0);
RED4EXT_ASSERT_OFFSET(CharacterCustomizationPersonalLinkController, simpleLinkGroup, 0x90);
#else
RED4EXT_ASSERT_SIZE(CharacterCustomizationPersonalLinkController, 0xC8);
#endif
} // namespace game::ui
using gameuiCharacterCustomizationPersonalLinkController = game::ui::CharacterCustomizationPersonalLinkController;
} // namespace RED4ext

// clang-format on
