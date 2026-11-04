#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/NativeTypes.hpp>
#include <RED4ext/Scripting/Natives/Generated/game/EntityReference.hpp>
#include <RED4ext/Scripting/Natives/Generated/quest/IObjectConditionType.hpp>

namespace RED4ext
{
namespace quest
{
struct InventoryDuplicate_ConditionType : quest::IObjectConditionType
{
    static constexpr const char* NAME = "questInventoryDuplicate_ConditionType";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    uint8_t unk34[0x38 - 0x34]; // 34
    game::EntityReference objectRef; // 38
    bool isPlayer; // 70
    uint8_t unk71[0x74 - 0x71]; // 71
    TweakDBID itemID; // 74
    uint8_t unk7C[0x90 - 0x7C]; // 7C
#else
    game::EntityReference objectRef; // 38
    bool isPlayer; // 70
    uint8_t unk71[0x74 - 0x71]; // 71
    TweakDBID itemID; // 74
    uint8_t unk7C[0x90 - 0x7C]; // 7C
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(InventoryDuplicate_ConditionType, 0x90);
RED4EXT_ASSERT_OFFSET(InventoryDuplicate_ConditionType, objectRef, 0x38);
RED4EXT_ASSERT_OFFSET(InventoryDuplicate_ConditionType, isPlayer, 0x70);
RED4EXT_ASSERT_OFFSET(InventoryDuplicate_ConditionType, itemID, 0x74);
#else
RED4EXT_ASSERT_SIZE(InventoryDuplicate_ConditionType, 0x90);
#endif
} // namespace quest
using questInventoryDuplicate_ConditionType = quest::InventoryDuplicate_ConditionType;
} // namespace RED4ext

// clang-format on
