#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/Scripting/Natives/Generated/anim/AnimNode_FloatValue.hpp>
#include <RED4ext/Scripting/Natives/Generated/red/TagList.hpp>

namespace RED4ext
{
namespace anim
{
struct AnimNode_AnimSetTagValue : anim::AnimNode_FloatValue
{
    static constexpr const char* NAME = "animAnimNode_AnimSetTagValue";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    uint8_t unk44[0x48 - 0x44]; // 44
    red::TagList tags; // 48
    uint8_t unk58[0x68 - 0x58]; // 58
#else
    red::TagList tags; // 48
    uint8_t unk58[0x68 - 0x58]; // 58
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(AnimNode_AnimSetTagValue, 0x68);
RED4EXT_ASSERT_OFFSET(AnimNode_AnimSetTagValue, tags, 0x48);
#else
RED4EXT_ASSERT_SIZE(AnimNode_AnimSetTagValue, 0x68);
#endif
} // namespace anim
using animAnimNode_AnimSetTagValue = anim::AnimNode_AnimSetTagValue;
} // namespace RED4ext

// clang-format on
