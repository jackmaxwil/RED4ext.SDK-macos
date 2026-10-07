#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/NativeTypes.hpp>
#include <RED4ext/Scripting/Natives/Generated/quest/IObjectConditionType.hpp>

namespace RED4ext
{
namespace quest
{
struct Inspect_ConditionType : quest::IObjectConditionType
{
    static constexpr const char* NAME = "questInspect_ConditionType";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    uint8_t unk34[0x38 - 0x34]; // 34
    CString objectID; // 38
    bool inverted; // 58
    uint8_t unk59[0x60 - 0x59]; // 59
#else
    CString objectID; // 38
    bool inverted; // 58
    uint8_t unk59[0x60 - 0x59]; // 59
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(Inspect_ConditionType, 0x60);
RED4EXT_ASSERT_OFFSET(Inspect_ConditionType, objectID, 0x38);
RED4EXT_ASSERT_OFFSET(Inspect_ConditionType, inverted, 0x58);
#else
RED4EXT_ASSERT_SIZE(Inspect_ConditionType, 0x60);
#endif
} // namespace quest
using questInspect_ConditionType = quest::Inspect_ConditionType;
} // namespace RED4ext

// clang-format on
