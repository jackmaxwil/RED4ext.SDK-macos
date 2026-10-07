#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/Handle.hpp>
#include <RED4ext/Scripting/Natives/Generated/game/EntityReference.hpp>
#include <RED4ext/Scripting/Natives/Generated/quest/ISystemConditionType.hpp>

namespace RED4ext
{
namespace game { struct IPrereq; }

namespace quest
{
struct Prereq_ConditionType : quest::ISystemConditionType
{
    static constexpr const char* NAME = "questPrereq_ConditionType";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    uint8_t unk34[0x38 - 0x34]; // 34
    game::EntityReference objectRef; // 38
    bool isObjectPlayer; // 70
    uint8_t unk71[0x78 - 0x71]; // 71
    Handle<game::IPrereq> prereq; // 78
#else
    game::EntityReference objectRef; // 38
    bool isObjectPlayer; // 70
    uint8_t unk71[0x78 - 0x71]; // 71
    Handle<game::IPrereq> prereq; // 78
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(Prereq_ConditionType, 0x88);
RED4EXT_ASSERT_OFFSET(Prereq_ConditionType, objectRef, 0x38);
RED4EXT_ASSERT_OFFSET(Prereq_ConditionType, isObjectPlayer, 0x70);
RED4EXT_ASSERT_OFFSET(Prereq_ConditionType, prereq, 0x78);
#else
RED4EXT_ASSERT_SIZE(Prereq_ConditionType, 0x88);
#endif
} // namespace quest
using questPrereq_ConditionType = quest::Prereq_ConditionType;
} // namespace RED4ext

// clang-format on
