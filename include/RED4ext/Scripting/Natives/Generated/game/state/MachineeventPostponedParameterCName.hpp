#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/CName.hpp>
#include <RED4ext/Scripting/Natives/Generated/game/state/MachineeventPostponedParameterBase.hpp>

namespace RED4ext
{
namespace game::state
{
struct MachineeventPostponedParameterCName : game::state::MachineeventPostponedParameterBase
{
    static constexpr const char* NAME = "gamestateMachineeventPostponedParameterCName";
    static constexpr const char* ALIAS = "PSMPostponedParameterCName";

#ifdef __APPLE__
    uint8_t unk4C[0x50 - 0x4C]; // 4C
    CName value; // 50
#else
    CName value; // 50
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(MachineeventPostponedParameterCName, 0x58);
RED4EXT_ASSERT_OFFSET(MachineeventPostponedParameterCName, value, 0x50);
#else
RED4EXT_ASSERT_SIZE(MachineeventPostponedParameterCName, 0x58);
#endif
} // namespace game::state
using gamestateMachineeventPostponedParameterCName = game::state::MachineeventPostponedParameterCName;
using PSMPostponedParameterCName = game::state::MachineeventPostponedParameterCName;
} // namespace RED4ext

// clang-format on
