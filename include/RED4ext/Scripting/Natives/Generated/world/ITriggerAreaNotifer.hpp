#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/Scripting/IScriptable.hpp>
#include <RED4ext/Scripting/Natives/Generated/TriggerChannel.hpp>

namespace RED4ext
{
namespace world
{
struct ITriggerAreaNotifer : IScriptable
{
    static constexpr const char* NAME = "worldITriggerAreaNotifer";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    bool isEnabled; // 40
    uint8_t unk41[0x44 - 0x41]; // 41
    TriggerChannel includeChannels; // 44
    uint32_t excludeChannels; // 48
    uint8_t unk4C[0xB2 - 0x4C]; // 4C
#else
    bool isEnabled; // 40
    uint8_t unk41[0x44 - 0x41]; // 41
    TriggerChannel includeChannels; // 44
    uint32_t excludeChannels; // 48
    uint8_t unk4C[0xB8 - 0x4C]; // 4C
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(ITriggerAreaNotifer, 0xB8);
RED4EXT_ASSERT_OFFSET(ITriggerAreaNotifer, isEnabled, 0x40);
RED4EXT_ASSERT_OFFSET(ITriggerAreaNotifer, includeChannels, 0x44);
RED4EXT_ASSERT_OFFSET(ITriggerAreaNotifer, excludeChannels, 0x48);
#else
RED4EXT_ASSERT_SIZE(ITriggerAreaNotifer, 0xB8);
#endif
} // namespace world
using worldITriggerAreaNotifer = world::ITriggerAreaNotifer;
} // namespace RED4ext

// clang-format on
