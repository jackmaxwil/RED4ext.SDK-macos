#pragma once

#include <RED4ext/Common.hpp>
#include <RED4ext/Scripting/Natives/Generated/game/EntityReference.hpp>
#include <RED4ext/Scripting/Natives/Generated/quest/IConditionType.hpp>
#include <cstdint>

namespace RED4ext
{
namespace quest
{
struct ICharacterConditionType : quest::IConditionType
{
    static constexpr const char* NAME = "questICharacterConditionType";
    static constexpr const char* ALIAS = NAME;

    game::EntityReference objectRef; // 38
    bool isPlayer;                   // 70
#ifndef __APPLE__                    // macOS: derived classes reuse this tail padding (Itanium), as in the game
    uint8_t unk71[0x78 - 0x71];      // 71
#endif
};
RED4EXT_ASSERT_SIZE(ICharacterConditionType, 0x78);
} // namespace quest
using questICharacterConditionType = quest::ICharacterConditionType;
} // namespace RED4ext
