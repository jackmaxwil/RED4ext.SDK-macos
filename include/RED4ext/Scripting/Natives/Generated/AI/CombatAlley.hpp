#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/Scripting/IScriptable.hpp>

namespace RED4ext
{
namespace AI
{
struct __declspec(align(0x10)) CombatAlley : IScriptable
{
    static constexpr const char* NAME = "AICombatAlley";
    static constexpr const char* ALIAS = "CombatAlley";

#ifdef __APPLE__
    uint8_t unk40[0xE0 - 0x40]; // 40
#else
    uint8_t unk40[0xD0 - 0x40]; // 40
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(CombatAlley, 0xE0);
#else
RED4EXT_ASSERT_SIZE(CombatAlley, 0xD0);
#endif
} // namespace AI
using AICombatAlley = AI::CombatAlley;
using CombatAlley = AI::CombatAlley;
} // namespace RED4ext

// clang-format on
