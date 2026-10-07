#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/Scripting/Natives/Generated/red/Event.hpp>

namespace RED4ext
{
namespace game::ui
{
struct PhotoModeRegisaterCallbacksEvent : red::Event
{
    static constexpr const char* NAME = "gameuiPhotoModeRegisaterCallbacksEvent";
    static constexpr const char* ALIAS = "PhotoModeRegisaterCallbacksEvent";

#ifdef __APPLE__
    uint8_t unk40[0x120 - 0x40]; // 40
#else
    uint8_t unk40[0x200 - 0x40]; // 40
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(PhotoModeRegisaterCallbacksEvent, 0x120);
#else
RED4EXT_ASSERT_SIZE(PhotoModeRegisaterCallbacksEvent, 0x200);
#endif
} // namespace game::ui
using gameuiPhotoModeRegisaterCallbacksEvent = game::ui::PhotoModeRegisaterCallbacksEvent;
using PhotoModeRegisaterCallbacksEvent = game::ui::PhotoModeRegisaterCallbacksEvent;
} // namespace RED4ext

// clang-format on
