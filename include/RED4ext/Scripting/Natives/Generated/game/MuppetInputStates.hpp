#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/Scripting/Natives/Generated/game/MuppetComponent.hpp>
#include <RED4ext/Scripting/Natives/Generated/net/Time.hpp>

namespace RED4ext
{
namespace game
{
struct MuppetInputStates : game::MuppetComponent
{
    static constexpr const char* NAME = "gameMuppetInputStates";
    static constexpr const char* ALIAS = "MuppetInputStates";

#ifdef __APPLE__
    uint8_t unk8D[0xA0 - 0x8D]; // 8D
    net::Time replicationTime; // A0
    uint8_t unkA8[0xB0 - 0xA8]; // A8
#else
    uint8_t unk90[0xA0 - 0x90]; // 90
    net::Time replicationTime; // A0
    uint8_t unkA8[0xB0 - 0xA8]; // A8
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(MuppetInputStates, 0xB0);
RED4EXT_ASSERT_OFFSET(MuppetInputStates, replicationTime, 0xA0);
#else
RED4EXT_ASSERT_SIZE(MuppetInputStates, 0xB0);
#endif
} // namespace game
using gameMuppetInputStates = game::MuppetInputStates;
using MuppetInputStates = game::MuppetInputStates;
} // namespace RED4ext

// clang-format on
