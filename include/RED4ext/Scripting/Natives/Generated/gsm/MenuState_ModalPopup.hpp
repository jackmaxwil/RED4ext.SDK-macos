#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/Scripting/Natives/Generated/gsm/PopupState.hpp>

namespace RED4ext
{
namespace gsm
{
struct MenuState_ModalPopup : gsm::PopupState
{
    static constexpr const char* NAME = "gsmMenuState_ModalPopup";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    uint8_t unk288[0x2C8 - 0x288]; // 288
#else
    uint8_t unk308[0x350 - 0x308]; // 308
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(MenuState_ModalPopup, 0x2C8);
#else
RED4EXT_ASSERT_SIZE(MenuState_ModalPopup, 0x350);
#endif
} // namespace gsm
using gsmMenuState_ModalPopup = gsm::MenuState_ModalPopup;
} // namespace RED4ext

// clang-format on
