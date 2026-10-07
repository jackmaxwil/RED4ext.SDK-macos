#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/CName.hpp>

namespace RED4ext
{
namespace game::state
{
struct MachineActionParameterFloat
{
    static constexpr const char* NAME = "gamestateMachineActionParameterFloat";
    static constexpr const char* ALIAS = "ActionParameterFloat";

#ifdef __APPLE__
    uint8_t unk00[0x8 - 0x0]; // 0
    CName name; // 08
    float value; // 10
    ~MachineActionParameterFloat() {} // non-POD, so clang reuses the tail padding like the game
#else
    uint8_t unk00[0x8 - 0x0]; // 0
    CName name; // 08
    float value; // 10
    uint8_t unk14[0x18 - 0x14]; // 14
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(MachineActionParameterFloat, 0x18);
RED4EXT_ASSERT_OFFSET(MachineActionParameterFloat, name, 0x8);
RED4EXT_ASSERT_OFFSET(MachineActionParameterFloat, value, 0x10);
#else
RED4EXT_ASSERT_SIZE(MachineActionParameterFloat, 0x18);
#endif
} // namespace game::state
using gamestateMachineActionParameterFloat = game::state::MachineActionParameterFloat;
using ActionParameterFloat = game::state::MachineActionParameterFloat;
} // namespace RED4ext

// clang-format on
