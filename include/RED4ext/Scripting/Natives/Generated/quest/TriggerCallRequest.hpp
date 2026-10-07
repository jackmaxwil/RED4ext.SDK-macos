#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/CName.hpp>
#include <RED4ext/Scripting/Natives/Generated/game/ScriptableSystemRequest.hpp>
#include <RED4ext/Scripting/Natives/Generated/quest/PhoneCallMode.hpp>
#include <RED4ext/Scripting/Natives/Generated/quest/PhoneCallPhase.hpp>
#include <RED4ext/Scripting/Natives/Generated/quest/PhoneCallVisuals.hpp>

namespace RED4ext
{
namespace quest
{
struct TriggerCallRequest : game::ScriptableSystemRequest
{
    static constexpr const char* NAME = "questTriggerCallRequest";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    uint8_t unk45[0x48 - 0x45]; // 45
    CName caller; // 48
    CName addressee; // 50
    quest::PhoneCallPhase callPhase; // 58
    quest::PhoneCallMode callMode; // 5C
    bool isPlayerTriggered; // 60
    bool isRejectable; // 61
    bool showAvatar; // 62
    uint8_t unk63[0x64 - 0x63]; // 63
    quest::PhoneCallVisuals visuals; // 64
#else
    CName caller; // 48
    CName addressee; // 50
    quest::PhoneCallPhase callPhase; // 58
    quest::PhoneCallMode callMode; // 5C
    bool isPlayerTriggered; // 60
    bool isRejectable; // 61
    bool showAvatar; // 62
    uint8_t unk63[0x64 - 0x63]; // 63
    quest::PhoneCallVisuals visuals; // 64
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(TriggerCallRequest, 0x68);
RED4EXT_ASSERT_OFFSET(TriggerCallRequest, caller, 0x48);
RED4EXT_ASSERT_OFFSET(TriggerCallRequest, addressee, 0x50);
RED4EXT_ASSERT_OFFSET(TriggerCallRequest, callPhase, 0x58);
RED4EXT_ASSERT_OFFSET(TriggerCallRequest, callMode, 0x5C);
RED4EXT_ASSERT_OFFSET(TriggerCallRequest, isPlayerTriggered, 0x60);
RED4EXT_ASSERT_OFFSET(TriggerCallRequest, isRejectable, 0x61);
RED4EXT_ASSERT_OFFSET(TriggerCallRequest, showAvatar, 0x62);
RED4EXT_ASSERT_OFFSET(TriggerCallRequest, visuals, 0x64);
#else
RED4EXT_ASSERT_SIZE(TriggerCallRequest, 0x68);
#endif
} // namespace quest
using questTriggerCallRequest = quest::TriggerCallRequest;
} // namespace RED4ext

// clang-format on
