#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/Scripting/Natives/Generated/game/state/MachineActionParameterVector.hpp>

namespace RED4ext
{
namespace game::state
{
struct __declspec(align(0x10)) MachineConsumableParameterVector : game::state::MachineActionParameterVector
{
    static constexpr const char* NAME = "gamestateMachineConsumableParameterVector";
    static constexpr const char* ALIAS = "ConsumableParameterVector";

#ifdef __APPLE__
    bool consumed; // 20
    uint8_t unk21[0x30 - 0x21]; // 21
#else
    bool consumed; // 30
    uint8_t unk31[0x40 - 0x31]; // 31
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(MachineConsumableParameterVector, 0x30);
RED4EXT_ASSERT_OFFSET(MachineConsumableParameterVector, consumed, 0x20);
#else
RED4EXT_ASSERT_SIZE(MachineConsumableParameterVector, 0x40);
#endif
} // namespace game::state
using gamestateMachineConsumableParameterVector = game::state::MachineConsumableParameterVector;
using ConsumableParameterVector = game::state::MachineConsumableParameterVector;
} // namespace RED4ext

// clang-format on
