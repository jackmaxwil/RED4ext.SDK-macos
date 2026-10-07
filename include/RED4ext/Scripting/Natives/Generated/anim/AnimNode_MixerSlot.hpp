#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/Scripting/Natives/Generated/anim/AnimNode_OnePoseInput.hpp>

namespace RED4ext
{
namespace anim
{
struct AnimNode_MixerSlot : anim::AnimNode_OnePoseInput
{
    static constexpr const char* NAME = "animAnimNode_MixerSlot";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    uint16_t maxNormalAnimEntriesCount; // 60
    uint16_t maxAdditiveAnimEntriesCount; // 62
    uint16_t maxOverrideAnimEntriesCount; // 64
    uint8_t unk66[0x138 - 0x66]; // 66
#else
    uint16_t maxNormalAnimEntriesCount; // 60
    uint16_t maxAdditiveAnimEntriesCount; // 62
    uint16_t maxOverrideAnimEntriesCount; // 64
    uint8_t unk66[0x150 - 0x66]; // 66
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(AnimNode_MixerSlot, 0x138);
RED4EXT_ASSERT_OFFSET(AnimNode_MixerSlot, maxNormalAnimEntriesCount, 0x60);
RED4EXT_ASSERT_OFFSET(AnimNode_MixerSlot, maxAdditiveAnimEntriesCount, 0x62);
RED4EXT_ASSERT_OFFSET(AnimNode_MixerSlot, maxOverrideAnimEntriesCount, 0x64);
#else
RED4EXT_ASSERT_SIZE(AnimNode_MixerSlot, 0x150);
#endif
} // namespace anim
using animAnimNode_MixerSlot = anim::AnimNode_MixerSlot;
} // namespace RED4ext

// clang-format on
