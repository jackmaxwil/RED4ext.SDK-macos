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
struct MachineActionParameterBool
{
    static constexpr const char* NAME = "gamestateMachineActionParameterBool";
    static constexpr const char* ALIAS = "ActionParameterBool";

#ifdef __APPLE__
    uint8_t unk00[0x8 - 0x0]; // 0
    CName name; // 08
    bool value; // 10
    ~MachineActionParameterBool() {} // non-POD, so clang reuses the tail padding like the game
#else
    uint8_t unk00[0x8 - 0x0]; // 0
    CName name; // 08
    bool value; // 10
    uint8_t unk11[0x18 - 0x11]; // 11
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(MachineActionParameterBool, 0x18);
RED4EXT_ASSERT_OFFSET(MachineActionParameterBool, name, 0x8);
RED4EXT_ASSERT_OFFSET(MachineActionParameterBool, value, 0x10);
#else
RED4EXT_ASSERT_SIZE(MachineActionParameterBool, 0x18);
#endif
} // namespace game::state
using gamestateMachineActionParameterBool = game::state::MachineActionParameterBool;
using ActionParameterBool = game::state::MachineActionParameterBool;
} // namespace RED4ext

// clang-format on
