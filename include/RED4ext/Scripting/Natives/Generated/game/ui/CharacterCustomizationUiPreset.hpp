#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/Containers/DynArray.hpp>
#include <RED4ext/Scripting/Natives/Generated/CResource.hpp>
#include <RED4ext/Scripting/Natives/Generated/game/ui/CharacterCustomizationUiPresetValue.hpp>

namespace RED4ext
{
namespace game::ui
{
struct CharacterCustomizationUiPreset : CResource
{
    static constexpr const char* NAME = "gameuiCharacterCustomizationUiPreset";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    bool isMaleVO; // 39
    uint8_t unk3A[0x40 - 0x3A]; // 3A
    DynArray<game::ui::CharacterCustomizationUiPresetValue> values; // 40
#else
    bool isMaleVO; // 40
    uint8_t unk41[0x48 - 0x41]; // 41
    DynArray<game::ui::CharacterCustomizationUiPresetValue> values; // 48
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(CharacterCustomizationUiPreset, 0x50);
RED4EXT_ASSERT_OFFSET(CharacterCustomizationUiPreset, isMaleVO, 0x39);
RED4EXT_ASSERT_OFFSET(CharacterCustomizationUiPreset, values, 0x40);
#else
RED4EXT_ASSERT_SIZE(CharacterCustomizationUiPreset, 0x58);
#endif
} // namespace game::ui
using gameuiCharacterCustomizationUiPreset = game::ui::CharacterCustomizationUiPreset;
} // namespace RED4ext

// clang-format on
