#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/Containers/DynArray.hpp>
#include <RED4ext/Scripting/Natives/Generated/quest/CharacterManagerVisuals_EntityAppearanceOperationBaseEntityAppearanceEntry.hpp>
#include <RED4ext/Scripting/Natives/Generated/quest/ICharacterManagerVisuals_NodeSubType.hpp>

namespace RED4ext
{
namespace quest
{
struct CharacterManagerVisuals_EntityAppearanceOperationBase : quest::ICharacterManagerVisuals_NodeSubType
{
    static constexpr const char* NAME = "questCharacterManagerVisuals_EntityAppearanceOperationBase";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    uint8_t unk6C[0x70 - 0x6C]; // 6C
    DynArray<quest::CharacterManagerVisuals_EntityAppearanceOperationBaseEntityAppearanceEntry> appearanceEntries; // 70
    uint8_t unk80[0xD0 - 0x80]; // 80
#else
    uint8_t unk70[0x78 - 0x70]; // 70
    DynArray<quest::CharacterManagerVisuals_EntityAppearanceOperationBaseEntityAppearanceEntry> appearanceEntries; // 78
    uint8_t unk88[0xD8 - 0x88]; // 88
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(CharacterManagerVisuals_EntityAppearanceOperationBase, 0xD0);
RED4EXT_ASSERT_OFFSET(CharacterManagerVisuals_EntityAppearanceOperationBase, appearanceEntries, 0x70);
#else
RED4EXT_ASSERT_SIZE(CharacterManagerVisuals_EntityAppearanceOperationBase, 0xD8);
#endif
} // namespace quest
using questCharacterManagerVisuals_EntityAppearanceOperationBase = quest::CharacterManagerVisuals_EntityAppearanceOperationBase;
} // namespace RED4ext

// clang-format on
