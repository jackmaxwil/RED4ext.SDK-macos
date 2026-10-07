#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/Containers/DynArray.hpp>
#include <RED4ext/Handle.hpp>
#include <RED4ext/Scripting/Natives/Generated/quest/Condition.hpp>
#include <RED4ext/Scripting/Natives/Generated/quest/LogicalOperation.hpp>

namespace RED4ext
{
namespace quest { struct IBaseCondition; }

namespace quest
{
struct LogicalCondition : quest::Condition
{
    static constexpr const char* NAME = "questLogicalCondition";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    quest::LogicalOperation operation; // 34
    uint8_t unk35[0x38 - 0x35]; // 35
    DynArray<Handle<quest::IBaseCondition>> conditions; // 38
#else
    quest::LogicalOperation operation; // 38
    uint8_t unk39[0x40 - 0x39]; // 39
    DynArray<Handle<quest::IBaseCondition>> conditions; // 40
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(LogicalCondition, 0x48);
RED4EXT_ASSERT_OFFSET(LogicalCondition, operation, 0x34);
RED4EXT_ASSERT_OFFSET(LogicalCondition, conditions, 0x38);
#else
RED4EXT_ASSERT_SIZE(LogicalCondition, 0x50);
#endif
} // namespace quest
using questLogicalCondition = quest::LogicalCondition;
} // namespace RED4ext

// clang-format on
