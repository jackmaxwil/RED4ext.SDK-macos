#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/Handle.hpp>
#include <RED4ext/Scripting/Natives/Generated/game/ActionRotateBaseState.hpp>

namespace RED4ext
{
namespace game { struct Object; }

namespace game
{
struct ActionRotateToObjectState : game::ActionRotateBaseState
{
    static constexpr const char* NAME = "gameActionRotateToObjectState";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    WeakHandle<game::Object> targetObject; // 38
    bool completeWhenRotated; // 48
    uint8_t unk49[0x50 - 0x49]; // 49
#else
    WeakHandle<game::Object> targetObject; // 40
    bool completeWhenRotated; // 50
    uint8_t unk51[0x58 - 0x51]; // 51
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(ActionRotateToObjectState, 0x50);
RED4EXT_ASSERT_OFFSET(ActionRotateToObjectState, targetObject, 0x38);
RED4EXT_ASSERT_OFFSET(ActionRotateToObjectState, completeWhenRotated, 0x48);
#else
RED4EXT_ASSERT_SIZE(ActionRotateToObjectState, 0x58);
#endif
} // namespace game
using gameActionRotateToObjectState = game::ActionRotateToObjectState;
} // namespace RED4ext

// clang-format on
