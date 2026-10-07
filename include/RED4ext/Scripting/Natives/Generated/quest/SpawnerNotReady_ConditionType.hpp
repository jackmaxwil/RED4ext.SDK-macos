#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/CName.hpp>
#include <RED4ext/Containers/DynArray.hpp>
#include <RED4ext/NativeTypes.hpp>
#include <RED4ext/Scripting/Natives/Generated/quest/ISpawnerConditionType.hpp>

namespace RED4ext
{
namespace quest
{
struct SpawnerNotReady_ConditionType : quest::ISpawnerConditionType
{
    static constexpr const char* NAME = "questSpawnerNotReady_ConditionType";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    uint8_t unk34[0x38 - 0x34]; // 34
    NodeRef spawnerReference; // 38
    DynArray<CName> communityEntryNames; // 40
#else
    NodeRef spawnerReference; // 38
    DynArray<CName> communityEntryNames; // 40
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(SpawnerNotReady_ConditionType, 0x50);
RED4EXT_ASSERT_OFFSET(SpawnerNotReady_ConditionType, spawnerReference, 0x38);
RED4EXT_ASSERT_OFFSET(SpawnerNotReady_ConditionType, communityEntryNames, 0x40);
#else
RED4EXT_ASSERT_SIZE(SpawnerNotReady_ConditionType, 0x50);
#endif
} // namespace quest
using questSpawnerNotReady_ConditionType = quest::SpawnerNotReady_ConditionType;
} // namespace RED4ext

// clang-format on
