#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/Scripting/Natives/Generated/game/state/MachineeventPostponedParameterBase.hpp>

namespace RED4ext
{
namespace game::state
{
struct MachineeventPostponedParameterFloat : game::state::MachineeventPostponedParameterBase
{
    static constexpr const char* NAME = "gamestateMachineeventPostponedParameterFloat";
    static constexpr const char* ALIAS = "PSMPostponedParameterFloat";

#ifdef __APPLE__
    float value; // 4C
#else
    float value; // 50
    uint8_t unk54[0x58 - 0x54]; // 54
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(MachineeventPostponedParameterFloat, 0x50);
RED4EXT_ASSERT_OFFSET(MachineeventPostponedParameterFloat, value, 0x4C);
#else
RED4EXT_ASSERT_SIZE(MachineeventPostponedParameterFloat, 0x58);
#endif
} // namespace game::state
using gamestateMachineeventPostponedParameterFloat = game::state::MachineeventPostponedParameterFloat;
using PSMPostponedParameterFloat = game::state::MachineeventPostponedParameterFloat;
} // namespace RED4ext

// clang-format on
