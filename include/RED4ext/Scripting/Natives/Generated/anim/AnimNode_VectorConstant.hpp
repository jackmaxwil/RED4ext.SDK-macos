#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/Scripting/Natives/Generated/Vector4.hpp>
#include <RED4ext/Scripting/Natives/Generated/anim/AnimNode_VectorValue.hpp>

namespace RED4ext
{
namespace anim
{
struct __declspec(align(0x10)) AnimNode_VectorConstant : anim::AnimNode_VectorValue
{
    static constexpr const char* NAME = "animAnimNode_VectorConstant";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    uint8_t unk44[0x50 - 0x44]; // 44
    Vector4 value; // 50
#else
    uint8_t unk48[0x50 - 0x48]; // 48
    Vector4 value; // 50
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(AnimNode_VectorConstant, 0x60);
RED4EXT_ASSERT_OFFSET(AnimNode_VectorConstant, value, 0x50);
#else
RED4EXT_ASSERT_SIZE(AnimNode_VectorConstant, 0x60);
#endif
} // namespace anim
using animAnimNode_VectorConstant = anim::AnimNode_VectorConstant;
} // namespace RED4ext

// clang-format on
