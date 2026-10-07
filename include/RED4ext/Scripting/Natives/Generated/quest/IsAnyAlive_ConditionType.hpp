#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/CName.hpp>
#include <RED4ext/Scripting/Natives/Generated/quest/IDynamicSpawnSystemConditionType.hpp>

namespace RED4ext
{
namespace quest
{
struct IsAnyAlive_ConditionType : quest::IDynamicSpawnSystemConditionType
{
    static constexpr const char* NAME = "questIsAnyAlive_ConditionType";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    uint8_t unk34[0x38 - 0x34]; // 34
    CName waveTag; // 38
    bool inverted; // 40
    uint8_t unk41[0x48 - 0x41]; // 41
#else
    CName waveTag; // 38
    bool inverted; // 40
    uint8_t unk41[0x48 - 0x41]; // 41
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(IsAnyAlive_ConditionType, 0x48);
RED4EXT_ASSERT_OFFSET(IsAnyAlive_ConditionType, waveTag, 0x38);
RED4EXT_ASSERT_OFFSET(IsAnyAlive_ConditionType, inverted, 0x40);
#else
RED4EXT_ASSERT_SIZE(IsAnyAlive_ConditionType, 0x48);
#endif
} // namespace quest
using questIsAnyAlive_ConditionType = quest::IsAnyAlive_ConditionType;
} // namespace RED4ext

// clang-format on
