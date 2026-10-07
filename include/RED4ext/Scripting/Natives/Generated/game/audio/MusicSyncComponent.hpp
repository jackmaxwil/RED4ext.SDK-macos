#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/CName.hpp>
#include <RED4ext/Scripting/Natives/Generated/ent/IComponent.hpp>

namespace RED4ext
{
namespace game::audio
{
struct MusicSyncComponent : ent::IComponent
{
    static constexpr const char* NAME = "gameaudioMusicSyncComponent";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    bool notifyBeats; // 8D
    bool notifyBars; // 8E
    bool notifyGrid; // 8F
    bool notifyBarProgression; // 90
    bool notifyBeatProgression; // 91
    uint8_t unk92[0x98 - 0x92]; // 92
    CName syncTrack; // 98
    uint8_t unkA0[0xE8 - 0xA0]; // A0
#else
    bool notifyBeats; // 90
    bool notifyBars; // 91
    bool notifyGrid; // 92
    bool notifyBarProgression; // 93
    bool notifyBeatProgression; // 94
    uint8_t unk95[0x98 - 0x95]; // 95
    CName syncTrack; // 98
    uint8_t unkA0[0xE8 - 0xA0]; // A0
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(MusicSyncComponent, 0xE8);
RED4EXT_ASSERT_OFFSET(MusicSyncComponent, notifyBeats, 0x8D);
RED4EXT_ASSERT_OFFSET(MusicSyncComponent, notifyBars, 0x8E);
RED4EXT_ASSERT_OFFSET(MusicSyncComponent, notifyGrid, 0x8F);
RED4EXT_ASSERT_OFFSET(MusicSyncComponent, notifyBarProgression, 0x90);
RED4EXT_ASSERT_OFFSET(MusicSyncComponent, notifyBeatProgression, 0x91);
RED4EXT_ASSERT_OFFSET(MusicSyncComponent, syncTrack, 0x98);
#else
RED4EXT_ASSERT_SIZE(MusicSyncComponent, 0xE8);
#endif
} // namespace game::audio
using gameaudioMusicSyncComponent = game::audio::MusicSyncComponent;
} // namespace RED4ext

// clang-format on
