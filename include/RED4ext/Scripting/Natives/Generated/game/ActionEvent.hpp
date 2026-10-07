#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/CName.hpp>
#include <RED4ext/Handle.hpp>
#include <RED4ext/Scripting/Natives/Generated/AI/AIEvent.hpp>

namespace RED4ext
{
namespace game { struct ActionInternalEvent; }

namespace game
{
struct ActionEvent : AI::AIEvent
{
    static constexpr const char* NAME = "gameActionEvent";
    static constexpr const char* ALIAS = "ActionEvent";

#ifdef __APPLE__
    uint8_t unk4C[0x50 - 0x4C]; // 4C
    CName eventAction; // 50
    Handle<game::ActionInternalEvent> internalEvent; // 58
#else
    CName eventAction; // 50
    Handle<game::ActionInternalEvent> internalEvent; // 58
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(ActionEvent, 0x68);
RED4EXT_ASSERT_OFFSET(ActionEvent, eventAction, 0x50);
RED4EXT_ASSERT_OFFSET(ActionEvent, internalEvent, 0x58);
#else
RED4EXT_ASSERT_SIZE(ActionEvent, 0x68);
#endif
} // namespace game
using gameActionEvent = game::ActionEvent;
using ActionEvent = game::ActionEvent;
} // namespace RED4ext

// clang-format on
