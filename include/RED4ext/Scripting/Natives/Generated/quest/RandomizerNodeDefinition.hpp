#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/DynArray.hpp>
#include <RED4ext/Scripting/Natives/Generated/quest/DisableableNodeDefinition.hpp>
#include <RED4ext/Scripting/Natives/Generated/quest/RandomizerMode.hpp>

namespace RED4ext
{
namespace quest
{
struct RandomizerNodeDefinition : quest::DisableableNodeDefinition
{
    static constexpr const char* NAME = "questRandomizerNodeDefinition";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    quest::RandomizerMode mode; // 42
    uint8_t unk43[0x48 - 0x43]; // 43
    DynArray<uint8_t> outputWeights; // 48
#else
    quest::RandomizerMode mode; // 48
    uint8_t unk49[0x50 - 0x49]; // 49
    DynArray<uint8_t> outputWeights; // 50
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(RandomizerNodeDefinition, 0x58);
RED4EXT_ASSERT_OFFSET(RandomizerNodeDefinition, mode, 0x42);
RED4EXT_ASSERT_OFFSET(RandomizerNodeDefinition, outputWeights, 0x48);
#else
RED4EXT_ASSERT_SIZE(RandomizerNodeDefinition, 0x60);
#endif
} // namespace quest
using questRandomizerNodeDefinition = quest::RandomizerNodeDefinition;
} // namespace RED4ext

// clang-format on
