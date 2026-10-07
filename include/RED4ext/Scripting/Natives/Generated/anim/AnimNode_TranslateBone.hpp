#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/Scripting/Natives/Generated/Vector4.hpp>
#include <RED4ext/Scripting/Natives/Generated/anim/AnimNode_Base.hpp>
#include <RED4ext/Scripting/Natives/Generated/anim/PoseLink.hpp>
#include <RED4ext/Scripting/Natives/Generated/anim/TransformIndex.hpp>
#include <RED4ext/Scripting/Natives/Generated/anim/VectorLink.hpp>

namespace RED4ext
{
namespace anim
{
struct __declspec(align(0x10)) AnimNode_TranslateBone : anim::AnimNode_Base
{
    static constexpr const char* NAME = "animAnimNode_TranslateBone";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    uint8_t unk44[0x50 - 0x44]; // 44
    Vector4 scale; // 50
    Vector4 biasValue; // 60
    anim::TransformIndex bone; // 70
    bool useIncrementalMode; // 88
    bool resetOnActivation; // 89
    uint8_t unk8A[0xA0 - 0x8A]; // 8A
    anim::PoseLink inputNode; // A0
    anim::VectorLink inputTranslation; // B8
    uint8_t unkD8[0xE0 - 0xD8]; // D8
#else
    uint8_t unk48[0x50 - 0x48]; // 48
    Vector4 scale; // 50
    Vector4 biasValue; // 60
    anim::TransformIndex bone; // 70
    bool useIncrementalMode; // 88
    bool resetOnActivation; // 89
    uint8_t unk8A[0xA0 - 0x8A]; // 8A
    anim::PoseLink inputNode; // A0
    anim::VectorLink inputTranslation; // B8
    uint8_t unkD8[0xE0 - 0xD8]; // D8
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(AnimNode_TranslateBone, 0xE0);
RED4EXT_ASSERT_OFFSET(AnimNode_TranslateBone, scale, 0x50);
RED4EXT_ASSERT_OFFSET(AnimNode_TranslateBone, biasValue, 0x60);
RED4EXT_ASSERT_OFFSET(AnimNode_TranslateBone, bone, 0x70);
RED4EXT_ASSERT_OFFSET(AnimNode_TranslateBone, useIncrementalMode, 0x88);
RED4EXT_ASSERT_OFFSET(AnimNode_TranslateBone, resetOnActivation, 0x89);
RED4EXT_ASSERT_OFFSET(AnimNode_TranslateBone, inputNode, 0xA0);
RED4EXT_ASSERT_OFFSET(AnimNode_TranslateBone, inputTranslation, 0xB8);
#else
RED4EXT_ASSERT_SIZE(AnimNode_TranslateBone, 0xE0);
#endif
} // namespace anim
using animAnimNode_TranslateBone = anim::AnimNode_TranslateBone;
} // namespace RED4ext

// clang-format on
