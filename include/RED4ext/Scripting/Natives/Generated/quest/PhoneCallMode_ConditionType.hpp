#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/Scripting/Natives/Generated/quest/IPhoneConditionType.hpp>
#include <RED4ext/Scripting/Natives/Generated/quest/PhoneCallMode.hpp>

namespace RED4ext
{
namespace quest
{
struct PhoneCallMode_ConditionType : quest::IPhoneConditionType
{
    static constexpr const char* NAME = "questPhoneCallMode_ConditionType";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    quest::PhoneCallMode callMode; // 38
    uint8_t unk3C[0x40 - 0x3C]; // 3C
#else
    quest::PhoneCallMode callMode; // 40
    uint8_t unk44[0x48 - 0x44]; // 44
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(PhoneCallMode_ConditionType, 0x40);
RED4EXT_ASSERT_OFFSET(PhoneCallMode_ConditionType, callMode, 0x38);
#else
RED4EXT_ASSERT_SIZE(PhoneCallMode_ConditionType, 0x48);
#endif
} // namespace quest
using questPhoneCallMode_ConditionType = quest::PhoneCallMode_ConditionType;
} // namespace RED4ext

// clang-format on
