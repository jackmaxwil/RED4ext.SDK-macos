#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/NativeTypes.hpp>
#include <RED4ext/Scripting/Natives/Generated/game/ui/StickerBackgroundCallback.hpp>
#include <RED4ext/Scripting/Natives/Generated/game/ui/StickerCallback.hpp>
#include <RED4ext/Scripting/Natives/Generated/game/ui/StickerFrameCallback.hpp>
#include <RED4ext/Scripting/Natives/Generated/game/ui/StickerImageCallback.hpp>
#include <RED4ext/Scripting/Natives/Generated/game/ui/WidgetGameController.hpp>
#include <RED4ext/Scripting/Natives/Generated/ink/EmptyCallback.hpp>

namespace RED4ext
{
namespace game::ui
{
struct PhotoModeStickersController : game::ui::WidgetGameController
{
    static constexpr const char* NAME = "gameuiPhotoModeStickersController";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    uint8_t unkDC[0xE0 - 0xDC]; // DC
    ink::EmptyCallback ResetStickers; // E0
    game::ui::StickerImageCallback SetStickerImage; // 118
    game::ui::StickerCallback SetSetSelectedSticker; // 150
    game::ui::StickerFrameCallback SetFrameImage; // 188
    game::ui::StickerBackgroundCallback SetBackground; // 1C0
    uint8_t unk1F8[0x238 - 0x1F8]; // 1F8
    NodeRef backgroundPrefabRef; // 238
    uint8_t unk240[0x288 - 0x240]; // 240
#else
    ink::EmptyCallback ResetStickers; // E0
    game::ui::StickerImageCallback SetStickerImage; // 118
    game::ui::StickerCallback SetSetSelectedSticker; // 150
    game::ui::StickerFrameCallback SetFrameImage; // 188
    game::ui::StickerBackgroundCallback SetBackground; // 1C0
    uint8_t unk1F8[0x278 - 0x1F8]; // 1F8
    NodeRef backgroundPrefabRef; // 278
    uint8_t unk280[0x2B0 - 0x280]; // 280
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(PhotoModeStickersController, 0x288);
RED4EXT_ASSERT_OFFSET(PhotoModeStickersController, ResetStickers, 0xE0);
RED4EXT_ASSERT_OFFSET(PhotoModeStickersController, SetStickerImage, 0x118);
RED4EXT_ASSERT_OFFSET(PhotoModeStickersController, SetSetSelectedSticker, 0x150);
RED4EXT_ASSERT_OFFSET(PhotoModeStickersController, SetFrameImage, 0x188);
RED4EXT_ASSERT_OFFSET(PhotoModeStickersController, SetBackground, 0x1C0);
RED4EXT_ASSERT_OFFSET(PhotoModeStickersController, backgroundPrefabRef, 0x238);
#else
RED4EXT_ASSERT_SIZE(PhotoModeStickersController, 0x2B0);
#endif
} // namespace game::ui
using gameuiPhotoModeStickersController = game::ui::PhotoModeStickersController;
} // namespace RED4ext

// clang-format on
