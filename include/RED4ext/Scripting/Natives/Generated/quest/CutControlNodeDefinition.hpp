#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/Scripting/Natives/Generated/quest/DisableableNodeDefinition.hpp>

namespace RED4ext
{
namespace quest
{
struct CutControlNodeDefinition : quest::DisableableNodeDefinition
{
    static constexpr const char* NAME = "questCutControlNodeDefinition";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    bool permanent; // 42
    uint8_t unk43[0x48 - 0x43]; // 43
#else
    bool permanent; // 48
    uint8_t unk49[0x50 - 0x49]; // 49
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(CutControlNodeDefinition, 0x48);
RED4EXT_ASSERT_OFFSET(CutControlNodeDefinition, permanent, 0x42);
#else
RED4EXT_ASSERT_SIZE(CutControlNodeDefinition, 0x50);
#endif
} // namespace quest
using questCutControlNodeDefinition = quest::CutControlNodeDefinition;
} // namespace RED4ext

// clang-format on
