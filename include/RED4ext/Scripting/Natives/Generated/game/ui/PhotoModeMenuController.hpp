#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/Scripting/Natives/Generated/game/ui/ChangeAspectRatioCallback.hpp>
#include <RED4ext/Scripting/Natives/Generated/game/ui/MenuGameController.hpp>
#include <RED4ext/Scripting/Natives/Generated/game/ui/NpcImageCallback.hpp>
#include <RED4ext/Scripting/Natives/Generated/game/ui/SetPhotoModeKeyEnabledCallback.hpp>
#include <RED4ext/Scripting/Natives/Generated/game/ui/StickerImageCallback.hpp>

namespace RED4ext
{
namespace game::ui
{
struct PhotoModeMenuController : game::ui::MenuGameController
{
    static constexpr const char* NAME = "gameuiPhotoModeMenuController";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    uint8_t unkF0[0x1D0 - 0xF0]; // F0
    game::ui::SetPhotoModeKeyEnabledCallback SetAttributeOptionEnabled; // 1D0
    game::ui::SetPhotoModeKeyEnabledCallback SetCategoryEnabled; // 208
    game::ui::StickerImageCallback SetStickerImage; // 240
    game::ui::NpcImageCallback SetNpcImage; // 278
    game::ui::ChangeAspectRatioCallback ChangeAspectRatio; // 2B0
    uint8_t unk2E8[0x320 - 0x2E8]; // 2E8
#else
    uint8_t unkF0[0x2B0 - 0xF0]; // F0
    game::ui::SetPhotoModeKeyEnabledCallback SetAttributeOptionEnabled; // 2B0
    game::ui::SetPhotoModeKeyEnabledCallback SetCategoryEnabled; // 2E8
    game::ui::StickerImageCallback SetStickerImage; // 320
    game::ui::NpcImageCallback SetNpcImage; // 358
    game::ui::ChangeAspectRatioCallback ChangeAspectRatio; // 390
    uint8_t unk3C8[0x400 - 0x3C8]; // 3C8
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(PhotoModeMenuController, 0x320);
RED4EXT_ASSERT_OFFSET(PhotoModeMenuController, SetAttributeOptionEnabled, 0x1D0);
RED4EXT_ASSERT_OFFSET(PhotoModeMenuController, SetCategoryEnabled, 0x208);
RED4EXT_ASSERT_OFFSET(PhotoModeMenuController, SetStickerImage, 0x240);
RED4EXT_ASSERT_OFFSET(PhotoModeMenuController, SetNpcImage, 0x278);
RED4EXT_ASSERT_OFFSET(PhotoModeMenuController, ChangeAspectRatio, 0x2B0);
#else
RED4EXT_ASSERT_SIZE(PhotoModeMenuController, 0x400);
#endif
} // namespace game::ui
using gameuiPhotoModeMenuController = game::ui::PhotoModeMenuController;
} // namespace RED4ext

// clang-format on
