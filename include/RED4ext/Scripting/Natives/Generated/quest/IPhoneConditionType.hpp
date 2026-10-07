#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/Scripting/Natives/Generated/quest/IUIConditionType.hpp>

namespace RED4ext
{
namespace quest
{
struct IPhoneConditionType : quest::IUIConditionType
{
    static constexpr const char* NAME = "questIPhoneConditionType";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    bool inverted; // 34
    uint8_t unk35[0x38 - 0x35]; // 35
#else
    bool inverted; // 38
    uint8_t unk39[0x40 - 0x39]; // 39
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(IPhoneConditionType, 0x38);
RED4EXT_ASSERT_OFFSET(IPhoneConditionType, inverted, 0x34);
#else
RED4EXT_ASSERT_SIZE(IPhoneConditionType, 0x40);
#endif
} // namespace quest
using questIPhoneConditionType = quest::IPhoneConditionType;
} // namespace RED4ext

// clang-format on
