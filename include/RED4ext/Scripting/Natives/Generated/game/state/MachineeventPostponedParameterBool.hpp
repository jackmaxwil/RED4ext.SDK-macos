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
struct MachineeventPostponedParameterBool : game::state::MachineeventPostponedParameterBase
{
    static constexpr const char* NAME = "gamestateMachineeventPostponedParameterBool";
    static constexpr const char* ALIAS = "PSMPostponedParameterBool";

#ifdef __APPLE__
    bool value; // 4C
    uint8_t unk4D[0x50 - 0x4D]; // 4D
#else
    bool value; // 50
    uint8_t unk51[0x58 - 0x51]; // 51
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(MachineeventPostponedParameterBool, 0x50);
RED4EXT_ASSERT_OFFSET(MachineeventPostponedParameterBool, value, 0x4C);
#else
RED4EXT_ASSERT_SIZE(MachineeventPostponedParameterBool, 0x58);
#endif
} // namespace game::state
using gamestateMachineeventPostponedParameterBool = game::state::MachineeventPostponedParameterBool;
using PSMPostponedParameterBool = game::state::MachineeventPostponedParameterBool;
} // namespace RED4ext

// clang-format on
