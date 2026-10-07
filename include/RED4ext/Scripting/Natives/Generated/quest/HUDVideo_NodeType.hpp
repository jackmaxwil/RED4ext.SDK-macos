#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/CName.hpp>
#include <RED4ext/NativeTypes.hpp>
#include <RED4ext/Scripting/Natives/Generated/Vector2.hpp>
#include <RED4ext/Scripting/Natives/Generated/quest/IUIManagerNodeType.hpp>

namespace RED4ext
{
struct Bink;

namespace quest
{
struct HUDVideo_NodeType : quest::IUIManagerNodeType
{
    static constexpr const char* NAME = "questHUDVideo_NodeType";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    uint8_t unk34[0x38 - 0x34]; // 34
    RaRef<Bink> video; // 38
    Vector2 position; // 40
    Vector2 size; // 48
    CName audioEvent; // 50
    bool syncToAudio; // 58
    bool retriggerAudioOnLoop; // 59
    bool skippable; // 5A
    bool looped; // 5B
    bool forceVideoFrameRate; // 5C
    bool playOnHud; // 5D
    bool fullScreen; // 5E
    bool useFullscreenVideoState; // 5F
    bool keepWidescreenAspectRatio; // 60
    uint8_t unk61[0x68 - 0x61]; // 61
#else
    RaRef<Bink> video; // 38
    Vector2 position; // 40
    Vector2 size; // 48
    CName audioEvent; // 50
    bool syncToAudio; // 58
    bool retriggerAudioOnLoop; // 59
    bool skippable; // 5A
    bool looped; // 5B
    bool forceVideoFrameRate; // 5C
    bool playOnHud; // 5D
    bool fullScreen; // 5E
    bool useFullscreenVideoState; // 5F
    bool keepWidescreenAspectRatio; // 60
    uint8_t unk61[0x68 - 0x61]; // 61
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(HUDVideo_NodeType, 0x68);
RED4EXT_ASSERT_OFFSET(HUDVideo_NodeType, video, 0x38);
RED4EXT_ASSERT_OFFSET(HUDVideo_NodeType, position, 0x40);
RED4EXT_ASSERT_OFFSET(HUDVideo_NodeType, size, 0x48);
RED4EXT_ASSERT_OFFSET(HUDVideo_NodeType, audioEvent, 0x50);
RED4EXT_ASSERT_OFFSET(HUDVideo_NodeType, syncToAudio, 0x58);
RED4EXT_ASSERT_OFFSET(HUDVideo_NodeType, retriggerAudioOnLoop, 0x59);
RED4EXT_ASSERT_OFFSET(HUDVideo_NodeType, skippable, 0x5A);
RED4EXT_ASSERT_OFFSET(HUDVideo_NodeType, looped, 0x5B);
RED4EXT_ASSERT_OFFSET(HUDVideo_NodeType, forceVideoFrameRate, 0x5C);
RED4EXT_ASSERT_OFFSET(HUDVideo_NodeType, playOnHud, 0x5D);
RED4EXT_ASSERT_OFFSET(HUDVideo_NodeType, fullScreen, 0x5E);
RED4EXT_ASSERT_OFFSET(HUDVideo_NodeType, useFullscreenVideoState, 0x5F);
RED4EXT_ASSERT_OFFSET(HUDVideo_NodeType, keepWidescreenAspectRatio, 0x60);
#else
RED4EXT_ASSERT_SIZE(HUDVideo_NodeType, 0x68);
#endif
} // namespace quest
using questHUDVideo_NodeType = quest::HUDVideo_NodeType;
} // namespace RED4ext

// clang-format on
