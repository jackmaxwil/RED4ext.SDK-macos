#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/CName.hpp>
#include <RED4ext/Scripting/Natives/Generated/quest/ISystemConditionType.hpp>

namespace RED4ext
{
namespace quest
{
struct PlaylistTrackChanged_ConditionType : quest::ISystemConditionType
{
    static constexpr const char* NAME = "questPlaylistTrackChanged_ConditionType";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    uint8_t unk34[0x38 - 0x34]; // 34
    CName playlistName; // 38
#else
    CName playlistName; // 38
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(PlaylistTrackChanged_ConditionType, 0x40);
RED4EXT_ASSERT_OFFSET(PlaylistTrackChanged_ConditionType, playlistName, 0x38);
#else
RED4EXT_ASSERT_SIZE(PlaylistTrackChanged_ConditionType, 0x40);
#endif
} // namespace quest
using questPlaylistTrackChanged_ConditionType = quest::PlaylistTrackChanged_ConditionType;
} // namespace RED4ext

// clang-format on
