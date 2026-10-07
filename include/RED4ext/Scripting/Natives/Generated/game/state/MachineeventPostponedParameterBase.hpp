#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/Scripting/Natives/Generated/game/state/MachineParameterAspect.hpp>
#include <RED4ext/Scripting/Natives/Generated/game/state/MachineeventBaseEvent.hpp>

namespace RED4ext
{
namespace game::state
{
struct MachineeventPostponedParameterBase : game::state::MachineeventBaseEvent
{
    static constexpr const char* NAME = "gamestateMachineeventPostponedParameterBase";
    static constexpr const char* ALIAS = "PSMPostponedParameterBase";

#ifdef __APPLE__
    game::state::MachineParameterAspect aspect; // 48
#else
    game::state::MachineParameterAspect aspect; // 48
    uint8_t unk4C[0x50 - 0x4C]; // 4C
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(MachineeventPostponedParameterBase, 0x50);
RED4EXT_ASSERT_OFFSET(MachineeventPostponedParameterBase, aspect, 0x48);
#else
RED4EXT_ASSERT_SIZE(MachineeventPostponedParameterBase, 0x50);
#endif
} // namespace game::state
using gamestateMachineeventPostponedParameterBase = game::state::MachineeventPostponedParameterBase;
using PSMPostponedParameterBase = game::state::MachineeventPostponedParameterBase;
} // namespace RED4ext

// clang-format on
