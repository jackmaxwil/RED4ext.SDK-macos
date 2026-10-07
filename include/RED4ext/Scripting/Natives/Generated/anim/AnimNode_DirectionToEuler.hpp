#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/Scripting/Natives/Generated/Vector4.hpp>
#include <RED4ext/Scripting/Natives/Generated/anim/AnimNode_FloatValue.hpp>
#include <RED4ext/Scripting/Natives/Generated/anim/EDirectionToEuler.hpp>
#include <RED4ext/Scripting/Natives/Generated/anim/VectorLink.hpp>

namespace RED4ext
{
namespace anim
{
struct __declspec(align(0x10)) AnimNode_DirectionToEuler : anim::AnimNode_FloatValue
{
    static constexpr const char* NAME = "animAnimNode_DirectionToEuler";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    uint8_t unk44[0x50 - 0x44]; // 44
    Vector4 initialForwardVector; // 50
    anim::VectorLink inputNode; // 60
    anim::EDirectionToEuler conversionType; // 80
    uint8_t unk84[0x90 - 0x84]; // 84
#else
    uint8_t unk48[0x50 - 0x48]; // 48
    Vector4 initialForwardVector; // 50
    anim::VectorLink inputNode; // 60
    anim::EDirectionToEuler conversionType; // 80
    uint8_t unk84[0x90 - 0x84]; // 84
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(AnimNode_DirectionToEuler, 0x90);
RED4EXT_ASSERT_OFFSET(AnimNode_DirectionToEuler, initialForwardVector, 0x50);
RED4EXT_ASSERT_OFFSET(AnimNode_DirectionToEuler, inputNode, 0x60);
RED4EXT_ASSERT_OFFSET(AnimNode_DirectionToEuler, conversionType, 0x80);
#else
RED4EXT_ASSERT_SIZE(AnimNode_DirectionToEuler, 0x90);
#endif
} // namespace anim
using animAnimNode_DirectionToEuler = anim::AnimNode_DirectionToEuler;
} // namespace RED4ext

// clang-format on
