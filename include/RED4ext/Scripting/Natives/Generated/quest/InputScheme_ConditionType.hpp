#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/Scripting/Natives/Generated/quest/ISystemConditionType.hpp>
#include <RED4ext/Scripting/Natives/Generated/quest/InputScheme.hpp>

namespace RED4ext
{
namespace quest
{
struct InputScheme_ConditionType : quest::ISystemConditionType
{
    static constexpr const char* NAME = "questInputScheme_ConditionType";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    quest::InputScheme scheme; // 34
#else
    quest::InputScheme scheme; // 38
    uint8_t unk3C[0x40 - 0x3C]; // 3C
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(InputScheme_ConditionType, 0x38);
RED4EXT_ASSERT_OFFSET(InputScheme_ConditionType, scheme, 0x34);
#else
RED4EXT_ASSERT_SIZE(InputScheme_ConditionType, 0x40);
#endif
} // namespace quest
using questInputScheme_ConditionType = quest::InputScheme_ConditionType;
} // namespace RED4ext

// clang-format on
