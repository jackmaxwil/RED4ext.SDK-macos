#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/Containers/DynArray.hpp>
#include <RED4ext/Scripting/Natives/Generated/game/ui/ForcePlayerCustomizationData.hpp>
#include <RED4ext/Scripting/Natives/Generated/quest/ICharacterManagerVisuals_NodeSubType.hpp>

namespace RED4ext
{
namespace quest
{
struct CharacterManagerVisuals_OverridePlayerCustomizations : quest::ICharacterManagerVisuals_NodeSubType
{
    static constexpr const char* NAME = "questCharacterManagerVisuals_OverridePlayerCustomizations";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    uint8_t unk6C[0x70 - 0x6C]; // 6C
    DynArray<game::ui::ForcePlayerCustomizationData> customizationData; // 70
#else
    DynArray<game::ui::ForcePlayerCustomizationData> customizationData; // 70
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(CharacterManagerVisuals_OverridePlayerCustomizations, 0x80);
RED4EXT_ASSERT_OFFSET(CharacterManagerVisuals_OverridePlayerCustomizations, customizationData, 0x70);
#else
RED4EXT_ASSERT_SIZE(CharacterManagerVisuals_OverridePlayerCustomizations, 0x80);
#endif
} // namespace quest
using questCharacterManagerVisuals_OverridePlayerCustomizations = quest::CharacterManagerVisuals_OverridePlayerCustomizations;
} // namespace RED4ext

// clang-format on
