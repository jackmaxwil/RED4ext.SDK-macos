#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/Scripting/Natives/Generated/game/events/DeathDirection.hpp>
#include <RED4ext/Scripting/Natives/Generated/quest/ICharacterManagerCombat_NodeSubType.hpp>

namespace RED4ext
{
namespace quest
{
struct CharacterManagerCombat_SetDeathDirection : quest::ICharacterManagerCombat_NodeSubType
{
    static constexpr const char* NAME = "questCharacterManagerCombat_SetDeathDirection";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    uint8_t unk69[0x6C - 0x69]; // 69
    game::events::DeathDirection direction; // 6C
#else
    game::events::DeathDirection direction; // 70
    uint8_t unk74[0x78 - 0x74]; // 74
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(CharacterManagerCombat_SetDeathDirection, 0x70);
RED4EXT_ASSERT_OFFSET(CharacterManagerCombat_SetDeathDirection, direction, 0x6C);
#else
RED4EXT_ASSERT_SIZE(CharacterManagerCombat_SetDeathDirection, 0x78);
#endif
} // namespace quest
using questCharacterManagerCombat_SetDeathDirection = quest::CharacterManagerCombat_SetDeathDirection;
} // namespace RED4ext

// clang-format on
