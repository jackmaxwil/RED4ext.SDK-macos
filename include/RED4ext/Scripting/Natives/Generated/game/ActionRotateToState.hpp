#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/Scripting/Natives/Generated/game/ActionRotateBaseState.hpp>

namespace RED4ext
{
namespace game
{
struct ActionRotateToState : game::ActionRotateBaseState
{
    static constexpr const char* NAME = "gameActionRotateToState";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
#else
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(ActionRotateToState, 0x38);
#else
RED4EXT_ASSERT_SIZE(ActionRotateToState, 0x40);
#endif
} // namespace game
using gameActionRotateToState = game::ActionRotateToState;
} // namespace RED4ext

// clang-format on
