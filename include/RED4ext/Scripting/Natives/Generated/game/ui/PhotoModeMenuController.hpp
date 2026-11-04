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
    uint8_t unk100[0x1E0 - 0x100]; // 100
    game::ui::SetPhotoModeKeyEnabledCallback SetAttributeOptionEnabled; // 1E0
    game::ui::SetPhotoModeKeyEnabledCallback SetCategoryEnabled; // 218
    game::ui::StickerImageCallback SetStickerImage; // 250
    game::ui::NpcImageCallback SetNpcImage; // 288
    game::ui::ChangeAspectRatioCallback ChangeAspectRatio; // 2C0
    uint8_t unk2F8[0x330 - 0x2F8]; // 2F8
#else
    uint8_t unk100[0x2C0 - 0x100]; // 100
    game::ui::SetPhotoModeKeyEnabledCallback SetAttributeOptionEnabled; // 2C0
    game::ui::SetPhotoModeKeyEnabledCallback SetCategoryEnabled; // 2F8
    game::ui::StickerImageCallback SetStickerImage; // 330
    game::ui::NpcImageCallback SetNpcImage; // 368
    game::ui::ChangeAspectRatioCallback ChangeAspectRatio; // 3A0
    uint8_t unk3D8[0x410 - 0x3D8]; // 3D8
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(PhotoModeMenuController, 0x330);
RED4EXT_ASSERT_OFFSET(PhotoModeMenuController, SetAttributeOptionEnabled, 0x1E0);
RED4EXT_ASSERT_OFFSET(PhotoModeMenuController, SetCategoryEnabled, 0x218);
RED4EXT_ASSERT_OFFSET(PhotoModeMenuController, SetStickerImage, 0x250);
RED4EXT_ASSERT_OFFSET(PhotoModeMenuController, SetNpcImage, 0x288);
RED4EXT_ASSERT_OFFSET(PhotoModeMenuController, ChangeAspectRatio, 0x2C0);
#else
RED4EXT_ASSERT_SIZE(PhotoModeMenuController, 0x410);
#endif
} // namespace game::ui
using gameuiPhotoModeMenuController = game::ui::PhotoModeMenuController;
} // namespace RED4ext

// clang-format on
