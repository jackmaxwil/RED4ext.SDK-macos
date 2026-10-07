#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/Scripting/Natives/Generated/game/EntityReference.hpp>
#include <RED4ext/Scripting/Natives/Generated/game/data/StimType.hpp>
#include <RED4ext/Scripting/Natives/Generated/quest/ISensesConditionType.hpp>

namespace RED4ext
{
namespace quest
{
struct Stimuli_ConditionType : quest::ISensesConditionType
{
    static constexpr const char* NAME = "questStimuli_ConditionType";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    uint8_t unk34[0x38 - 0x34]; // 34
    game::EntityReference instigatorRef; // 38
    bool isPlayerInstigator; // 70
    uint8_t unk71[0x78 - 0x71]; // 71
    game::EntityReference targetRef; // 78
    game::data::StimType type; // B0
    uint8_t unkB4[0xC0 - 0xB4]; // B4
#else
    game::EntityReference instigatorRef; // 38
    bool isPlayerInstigator; // 70
    uint8_t unk71[0x78 - 0x71]; // 71
    game::EntityReference targetRef; // 78
    game::data::StimType type; // B0
    uint8_t unkB4[0xC0 - 0xB4]; // B4
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(Stimuli_ConditionType, 0xC0);
RED4EXT_ASSERT_OFFSET(Stimuli_ConditionType, instigatorRef, 0x38);
RED4EXT_ASSERT_OFFSET(Stimuli_ConditionType, isPlayerInstigator, 0x70);
RED4EXT_ASSERT_OFFSET(Stimuli_ConditionType, targetRef, 0x78);
RED4EXT_ASSERT_OFFSET(Stimuli_ConditionType, type, 0xB0);
#else
RED4EXT_ASSERT_SIZE(Stimuli_ConditionType, 0xC0);
#endif
} // namespace quest
using questStimuli_ConditionType = quest::Stimuli_ConditionType;
} // namespace RED4ext

// clang-format on
