#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/Scripting/Natives/Generated/audio/RadioSpeakerType.hpp>
#include <RED4ext/Scripting/Natives/Generated/quest/ISystemConditionType.hpp>

namespace RED4ext
{
namespace quest
{
struct Radio_ConditionType : quest::ISystemConditionType
{
    static constexpr const char* NAME = "questRadio_ConditionType";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    bool inverted; // 34
    bool limitToSpecifiedSpeakersStations; // 35
    uint8_t unk36[0x38 - 0x36]; // 36
    audio::RadioSpeakerType speakerType; // 38
    uint8_t unk3C[0x40 - 0x3C]; // 3C
#else
    bool inverted; // 38
    bool limitToSpecifiedSpeakersStations; // 39
    uint8_t unk3A[0x3C - 0x3A]; // 3A
    audio::RadioSpeakerType speakerType; // 3C
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(Radio_ConditionType, 0x40);
RED4EXT_ASSERT_OFFSET(Radio_ConditionType, inverted, 0x34);
RED4EXT_ASSERT_OFFSET(Radio_ConditionType, limitToSpecifiedSpeakersStations, 0x35);
RED4EXT_ASSERT_OFFSET(Radio_ConditionType, speakerType, 0x38);
#else
RED4EXT_ASSERT_SIZE(Radio_ConditionType, 0x40);
#endif
} // namespace quest
using questRadio_ConditionType = quest::Radio_ConditionType;
} // namespace RED4ext

// clang-format on
