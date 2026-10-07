#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/Scripting/Natives/Generated/game/EntityReference.hpp>
#include <RED4ext/Scripting/Natives/Generated/quest/IObjectConditionType.hpp>
#include <RED4ext/Scripting/Natives/Generated/quest/ObjectScanEventType.hpp>

namespace RED4ext
{
namespace quest
{
struct Scan_ConditionType : quest::IObjectConditionType
{
    static constexpr const char* NAME = "questScan_ConditionType";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    uint8_t unk34[0x38 - 0x34]; // 34
    game::EntityReference objectRef; // 38
    quest::ObjectScanEventType eventType; // 70
    uint8_t unk71[0x80 - 0x71]; // 71
#else
    game::EntityReference objectRef; // 38
    quest::ObjectScanEventType eventType; // 70
    uint8_t unk71[0x80 - 0x71]; // 71
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(Scan_ConditionType, 0x80);
RED4EXT_ASSERT_OFFSET(Scan_ConditionType, objectRef, 0x38);
RED4EXT_ASSERT_OFFSET(Scan_ConditionType, eventType, 0x70);
#else
RED4EXT_ASSERT_SIZE(Scan_ConditionType, 0x80);
#endif
} // namespace quest
using questScan_ConditionType = quest::Scan_ConditionType;
} // namespace RED4ext

// clang-format on
