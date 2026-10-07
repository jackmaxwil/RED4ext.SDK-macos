#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/CName.hpp>
#include <RED4ext/Scripting/Natives/Generated/quest/DisableableNodeDefinition.hpp>

namespace RED4ext
{
namespace quest
{
struct InstancedCrowdControlNodeDefinition : quest::DisableableNodeDefinition
{
    static constexpr const char* NAME = "questInstancedCrowdControlNodeDefinition";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    uint8_t unk42[0x48 - 0x42]; // 42
    CName crowdVariantTag; // 48
    bool enable; // 50
    uint8_t unk51[0x58 - 0x51]; // 51
#else
    CName crowdVariantTag; // 48
    bool enable; // 50
    uint8_t unk51[0x58 - 0x51]; // 51
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(InstancedCrowdControlNodeDefinition, 0x58);
RED4EXT_ASSERT_OFFSET(InstancedCrowdControlNodeDefinition, crowdVariantTag, 0x48);
RED4EXT_ASSERT_OFFSET(InstancedCrowdControlNodeDefinition, enable, 0x50);
#else
RED4EXT_ASSERT_SIZE(InstancedCrowdControlNodeDefinition, 0x58);
#endif
} // namespace quest
using questInstancedCrowdControlNodeDefinition = quest::InstancedCrowdControlNodeDefinition;
} // namespace RED4ext

// clang-format on
