#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/CName.hpp>
#include <RED4ext/Scripting/Natives/Generated/quest/ISystemConditionType.hpp>

namespace RED4ext
{
namespace quest
{
struct InputAction_ConditionType : quest::ISystemConditionType
{
    static constexpr const char* NAME = "questInputAction_ConditionType";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    bool anyInputAction; // 34
    uint8_t unk35[0x38 - 0x35]; // 35
    CName inputAction; // 38
    bool checkIfButtonAlreadyPressed; // 40
    bool axisAction; // 41
    uint8_t unk42[0x44 - 0x42]; // 42
    float valueLessThan; // 44
    float valueMoreThan; // 48
    uint8_t unk4C[0x50 - 0x4C]; // 4C
#else
    bool anyInputAction; // 38
    uint8_t unk39[0x40 - 0x39]; // 39
    CName inputAction; // 40
    bool checkIfButtonAlreadyPressed; // 48
    bool axisAction; // 49
    uint8_t unk4A[0x4C - 0x4A]; // 4A
    float valueLessThan; // 4C
    float valueMoreThan; // 50
    uint8_t unk54[0x58 - 0x54]; // 54
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(InputAction_ConditionType, 0x50);
RED4EXT_ASSERT_OFFSET(InputAction_ConditionType, anyInputAction, 0x34);
RED4EXT_ASSERT_OFFSET(InputAction_ConditionType, inputAction, 0x38);
RED4EXT_ASSERT_OFFSET(InputAction_ConditionType, checkIfButtonAlreadyPressed, 0x40);
RED4EXT_ASSERT_OFFSET(InputAction_ConditionType, axisAction, 0x41);
RED4EXT_ASSERT_OFFSET(InputAction_ConditionType, valueLessThan, 0x44);
RED4EXT_ASSERT_OFFSET(InputAction_ConditionType, valueMoreThan, 0x48);
#else
RED4EXT_ASSERT_SIZE(InputAction_ConditionType, 0x58);
#endif
} // namespace quest
using questInputAction_ConditionType = quest::InputAction_ConditionType;
} // namespace RED4ext

// clang-format on
