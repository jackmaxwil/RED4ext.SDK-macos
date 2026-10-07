#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/NativeTypes.hpp>
#include <RED4ext/Scripting/Natives/Generated/game/BlackboardPropertyBindingDefinition.hpp>
#include <RED4ext/Scripting/Natives/Generated/game/IComparisonPrereq.hpp>

namespace RED4ext
{
namespace game
{
struct BlackboardPrereq : game::IComparisonPrereq
{
    static constexpr const char* NAME = "gameBlackboardPrereq";
    static constexpr const char* ALIAS = "BlackboardPrereq";

#ifdef __APPLE__
    uint8_t unk44[0x48 - 0x44]; // 44
    game::BlackboardPropertyBindingDefinition blackboardValue; // 48
    Variant value; // 80
    uint8_t unk98[0xA0 - 0x98]; // 98
#else
    game::BlackboardPropertyBindingDefinition blackboardValue; // 48
    Variant value; // 80
    uint8_t unk98[0xA0 - 0x98]; // 98
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(BlackboardPrereq, 0xA0);
RED4EXT_ASSERT_OFFSET(BlackboardPrereq, blackboardValue, 0x48);
RED4EXT_ASSERT_OFFSET(BlackboardPrereq, value, 0x80);
#else
RED4EXT_ASSERT_SIZE(BlackboardPrereq, 0xA0);
#endif
} // namespace game
using gameBlackboardPrereq = game::BlackboardPrereq;
using BlackboardPrereq = game::BlackboardPrereq;
} // namespace RED4ext

// clang-format on
