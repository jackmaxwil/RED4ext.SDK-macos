#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/Scripting/Natives/Generated/Vector2.hpp>

namespace RED4ext
{
namespace game::ui
{
struct HUDVideoStartEvent
{
    static constexpr const char* NAME = "gameuiHUDVideoStartEvent";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    uint8_t unk00[0x8 - 0x0]; // 0
    uint64_t videoPathHash; // 08
    uint8_t unk10[0x1A - 0x10]; // 10
    bool fullScreen; // 1A
    bool useFullscreenVideoState; // 1B
    bool keepWidescreenAspectRatio; // 1C
    uint8_t unk1D[0x20 - 0x1D]; // 1D
    Vector2 position; // 20
    Vector2 size; // 28
    bool skippable; // 30
    bool isLooped; // 31
    bool forceVideoFrameRate; // 32
    bool playOnHud; // 33
    uint8_t unk34[0x58 - 0x34]; // 34
#else
    uint8_t unk00[0x8 - 0x0]; // 0
    uint64_t videoPathHash; // 08
    uint8_t unk10[0x1A - 0x10]; // 10
    bool fullScreen; // 1A
    bool useFullscreenVideoState; // 1B
    bool keepWidescreenAspectRatio; // 1C
    uint8_t unk1D[0x20 - 0x1D]; // 1D
    Vector2 position; // 20
    Vector2 size; // 28
    bool skippable; // 30
    bool isLooped; // 31
    bool forceVideoFrameRate; // 32
    bool playOnHud; // 33
    uint8_t unk34[0x78 - 0x34]; // 34
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(HUDVideoStartEvent, 0x58);
RED4EXT_ASSERT_OFFSET(HUDVideoStartEvent, videoPathHash, 0x8);
RED4EXT_ASSERT_OFFSET(HUDVideoStartEvent, fullScreen, 0x1A);
RED4EXT_ASSERT_OFFSET(HUDVideoStartEvent, useFullscreenVideoState, 0x1B);
RED4EXT_ASSERT_OFFSET(HUDVideoStartEvent, keepWidescreenAspectRatio, 0x1C);
RED4EXT_ASSERT_OFFSET(HUDVideoStartEvent, position, 0x20);
RED4EXT_ASSERT_OFFSET(HUDVideoStartEvent, size, 0x28);
RED4EXT_ASSERT_OFFSET(HUDVideoStartEvent, skippable, 0x30);
RED4EXT_ASSERT_OFFSET(HUDVideoStartEvent, isLooped, 0x31);
RED4EXT_ASSERT_OFFSET(HUDVideoStartEvent, forceVideoFrameRate, 0x32);
RED4EXT_ASSERT_OFFSET(HUDVideoStartEvent, playOnHud, 0x33);
#else
RED4EXT_ASSERT_SIZE(HUDVideoStartEvent, 0x78);
#endif
} // namespace game::ui
using gameuiHUDVideoStartEvent = game::ui::HUDVideoStartEvent;
} // namespace RED4ext

// clang-format on
