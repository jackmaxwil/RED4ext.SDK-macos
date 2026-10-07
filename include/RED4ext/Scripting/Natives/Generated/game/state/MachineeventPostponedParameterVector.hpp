#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/Scripting/Natives/Generated/Vector4.hpp>
#include <RED4ext/Scripting/Natives/Generated/game/state/MachineeventPostponedParameterBase.hpp>

namespace RED4ext
{
namespace game::state
{
struct __declspec(align(0x10)) MachineeventPostponedParameterVector : game::state::MachineeventPostponedParameterBase
{
    static constexpr const char* NAME = "gamestateMachineeventPostponedParameterVector";
    static constexpr const char* ALIAS = "PSMPostponedParameterVector";

#ifdef __APPLE__
    uint8_t unk4C[0x50 - 0x4C]; // 4C
    Vector4 value; // 50
#else
    Vector4 value; // 50
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(MachineeventPostponedParameterVector, 0x60);
RED4EXT_ASSERT_OFFSET(MachineeventPostponedParameterVector, value, 0x50);
#else
RED4EXT_ASSERT_SIZE(MachineeventPostponedParameterVector, 0x60);
#endif
} // namespace game::state
using gamestateMachineeventPostponedParameterVector = game::state::MachineeventPostponedParameterVector;
using PSMPostponedParameterVector = game::state::MachineeventPostponedParameterVector;
} // namespace RED4ext

// clang-format on
