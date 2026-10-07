#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/CName.hpp>
#include <RED4ext/Scripting/Natives/Generated/anim/AnimNode_Base.hpp>
#include <RED4ext/Scripting/Natives/Generated/anim/PoseLink.hpp>

namespace RED4ext
{
namespace anim
{
struct AnimNode_GraphSlot : anim::AnimNode_Base
{
    static constexpr const char* NAME = "animAnimNode_GraphSlot";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    uint8_t unk44[0x48 - 0x44]; // 44
    CName name; // 48
    anim::PoseLink inputLink; // 50
    uint8_t unk68[0xA8 - 0x68]; // 68
    bool dontDeactivateInput; // A8
    uint8_t unkA9[0xB0 - 0xA9]; // A9
#else
    CName name; // 48
    anim::PoseLink inputLink; // 50
    uint8_t unk68[0xA8 - 0x68]; // 68
    bool dontDeactivateInput; // A8
    uint8_t unkA9[0xB0 - 0xA9]; // A9
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(AnimNode_GraphSlot, 0xB0);
RED4EXT_ASSERT_OFFSET(AnimNode_GraphSlot, name, 0x48);
RED4EXT_ASSERT_OFFSET(AnimNode_GraphSlot, inputLink, 0x50);
RED4EXT_ASSERT_OFFSET(AnimNode_GraphSlot, dontDeactivateInput, 0xA8);
#else
RED4EXT_ASSERT_SIZE(AnimNode_GraphSlot, 0xB0);
#endif
} // namespace anim
using animAnimNode_GraphSlot = anim::AnimNode_GraphSlot;
} // namespace RED4ext

// clang-format on
