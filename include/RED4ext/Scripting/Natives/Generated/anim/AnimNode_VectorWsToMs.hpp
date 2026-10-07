#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/Scripting/Natives/Generated/anim/AnimNode_VectorValue.hpp>
#include <RED4ext/Scripting/Natives/Generated/anim/EVectorWsToMsType.hpp>
#include <RED4ext/Scripting/Natives/Generated/anim/VectorLink.hpp>

namespace RED4ext
{
namespace anim
{
struct AnimNode_VectorWsToMs : anim::AnimNode_VectorValue
{
    static constexpr const char* NAME = "animAnimNode_VectorWsToMs";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    anim::EVectorWsToMsType type; // 44
    anim::VectorLink vectorWs; // 48
#else
    anim::EVectorWsToMsType type; // 48
    uint8_t unk4C[0x50 - 0x4C]; // 4C
    anim::VectorLink vectorWs; // 50
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(AnimNode_VectorWsToMs, 0x68);
RED4EXT_ASSERT_OFFSET(AnimNode_VectorWsToMs, type, 0x44);
RED4EXT_ASSERT_OFFSET(AnimNode_VectorWsToMs, vectorWs, 0x48);
#else
RED4EXT_ASSERT_SIZE(AnimNode_VectorWsToMs, 0x70);
#endif
} // namespace anim
using animAnimNode_VectorWsToMs = anim::AnimNode_VectorWsToMs;
} // namespace RED4ext

// clang-format on
