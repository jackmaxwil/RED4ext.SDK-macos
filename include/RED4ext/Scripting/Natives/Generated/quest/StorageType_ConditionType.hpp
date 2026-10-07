#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/Scripting/Natives/Generated/quest/ISystemConditionType.hpp>
#include <RED4ext/Scripting/Natives/Generated/quest/Storage.hpp>

namespace RED4ext
{
namespace quest
{
struct StorageType_ConditionType : quest::ISystemConditionType
{
    static constexpr const char* NAME = "questStorageType_ConditionType";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    quest::Storage storage; // 34
#else
    quest::Storage storage; // 38
    uint8_t unk3C[0x40 - 0x3C]; // 3C
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(StorageType_ConditionType, 0x38);
RED4EXT_ASSERT_OFFSET(StorageType_ConditionType, storage, 0x34);
#else
RED4EXT_ASSERT_SIZE(StorageType_ConditionType, 0x40);
#endif
} // namespace quest
using questStorageType_ConditionType = quest::StorageType_ConditionType;
} // namespace RED4ext

// clang-format on
