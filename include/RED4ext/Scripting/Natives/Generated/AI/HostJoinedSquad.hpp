#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/CName.hpp>
#include <RED4ext/Scripting/Natives/Generated/AI/AIEvent.hpp>

namespace RED4ext
{
namespace AI
{
struct HostJoinedSquad : AI::AIEvent
{
    static constexpr const char* NAME = "AIHostJoinedSquad";
    static constexpr const char* ALIAS = "HostJoinedSquad";

#ifdef __APPLE__
    uint8_t unk4C[0x50 - 0x4C]; // 4C
    CName squad; // 50
#else
    CName squad; // 50
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(HostJoinedSquad, 0x58);
RED4EXT_ASSERT_OFFSET(HostJoinedSquad, squad, 0x50);
#else
RED4EXT_ASSERT_SIZE(HostJoinedSquad, 0x58);
#endif
} // namespace AI
using AIHostJoinedSquad = AI::HostJoinedSquad;
using HostJoinedSquad = AI::HostJoinedSquad;
} // namespace RED4ext

// clang-format on
