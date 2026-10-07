#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/Scripting/Natives/Generated/game/state/MachineActionParameterInt.hpp>

namespace RED4ext
{
namespace game::state
{
struct MachineConsumableParameterInt : game::state::MachineActionParameterInt
{
    static constexpr const char* NAME = "gamestateMachineConsumableParameterInt";
    static constexpr const char* ALIAS = "ConsumableParameterInt";

#ifdef __APPLE__
    bool consumed; // 14
    uint8_t unk15[0x18 - 0x15]; // 15
#else
    bool consumed; // 18
    uint8_t unk19[0x20 - 0x19]; // 19
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(MachineConsumableParameterInt, 0x18);
RED4EXT_ASSERT_OFFSET(MachineConsumableParameterInt, consumed, 0x14);
#else
RED4EXT_ASSERT_SIZE(MachineConsumableParameterInt, 0x20);
#endif
} // namespace game::state
using gamestateMachineConsumableParameterInt = game::state::MachineConsumableParameterInt;
using ConsumableParameterInt = game::state::MachineConsumableParameterInt;
} // namespace RED4ext

// clang-format on
