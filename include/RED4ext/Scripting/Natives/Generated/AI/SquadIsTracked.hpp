#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/Scripting/Natives/Generated/AI/AIEvent.hpp>

namespace RED4ext
{
namespace AI
{
struct SquadIsTracked : AI::AIEvent
{
    static constexpr const char* NAME = "AISquadIsTracked";
    static constexpr const char* ALIAS = "SquadIsTracked";

#ifdef __APPLE__
    bool isSquadTracked; // 4C
    uint8_t unk4D[0x50 - 0x4D]; // 4D
#else
    bool isSquadTracked; // 50
    uint8_t unk51[0x58 - 0x51]; // 51
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(SquadIsTracked, 0x50);
RED4EXT_ASSERT_OFFSET(SquadIsTracked, isSquadTracked, 0x4C);
#else
RED4EXT_ASSERT_SIZE(SquadIsTracked, 0x58);
#endif
} // namespace AI
using AISquadIsTracked = AI::SquadIsTracked;
using SquadIsTracked = AI::SquadIsTracked;
} // namespace RED4ext

// clang-format on
