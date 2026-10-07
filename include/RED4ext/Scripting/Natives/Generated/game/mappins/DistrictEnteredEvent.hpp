#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/NativeTypes.hpp>
#include <RED4ext/Scripting/Natives/Generated/game/ScriptableSystemRequest.hpp>

namespace RED4ext
{
namespace game::mappins
{
struct DistrictEnteredEvent : game::ScriptableSystemRequest
{
    static constexpr const char* NAME = "gamemappinsDistrictEnteredEvent";
    static constexpr const char* ALIAS = "DistrictEnteredEvent";

#ifdef __APPLE__
    bool entered; // 45
    bool sendNewLocationNotification; // 46
    uint8_t unk47[0x48 - 0x47]; // 47
    TweakDBID district; // 48
#else
    bool entered; // 48
    bool sendNewLocationNotification; // 49
    uint8_t unk4A[0x4C - 0x4A]; // 4A
    TweakDBID district; // 4C
    uint8_t unk54[0x58 - 0x54]; // 54
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(DistrictEnteredEvent, 0x50);
RED4EXT_ASSERT_OFFSET(DistrictEnteredEvent, entered, 0x45);
RED4EXT_ASSERT_OFFSET(DistrictEnteredEvent, sendNewLocationNotification, 0x46);
RED4EXT_ASSERT_OFFSET(DistrictEnteredEvent, district, 0x48);
#else
RED4EXT_ASSERT_SIZE(DistrictEnteredEvent, 0x58);
#endif
} // namespace game::mappins
using gamemappinsDistrictEnteredEvent = game::mappins::DistrictEnteredEvent;
using DistrictEnteredEvent = game::mappins::DistrictEnteredEvent;
} // namespace RED4ext

// clang-format on
