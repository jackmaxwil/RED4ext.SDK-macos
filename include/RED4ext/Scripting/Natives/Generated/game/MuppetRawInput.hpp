#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/Scripting/Natives/Generated/game/MuppetComponent.hpp>

namespace RED4ext
{
namespace game
{
struct MuppetRawInput : game::MuppetComponent
{
    static constexpr const char* NAME = "gameMuppetRawInput";
    static constexpr const char* ALIAS = "MuppetRawInput";

#ifdef __APPLE__
    uint8_t unk8D[0x98 - 0x8D]; // 8D
#else
    uint8_t unk90[0x98 - 0x90]; // 90
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(MuppetRawInput, 0x98);
#else
RED4EXT_ASSERT_SIZE(MuppetRawInput, 0x98);
#endif
} // namespace game
using gameMuppetRawInput = game::MuppetRawInput;
using MuppetRawInput = game::MuppetRawInput;
} // namespace RED4ext

// clang-format on
