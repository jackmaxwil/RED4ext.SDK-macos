#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/CName.hpp>
#include <RED4ext/DynArray.hpp>
#include <RED4ext/Scripting/Natives/Generated/anim/AnimNode_FloatValue.hpp>
#include <RED4ext/Scripting/Natives/Generated/anim/EAnimGraphLogicOp.hpp>

namespace RED4ext
{
namespace anim
{
struct AnimNode_WrapperValue : anim::AnimNode_FloatValue
{
    static constexpr const char* NAME = "animAnimNode_WrapperValue";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    uint8_t unk44[0x48 - 0x44]; // 44
    DynArray<CName> wrapperNames; // 48
    anim::EAnimGraphLogicOp logicOp; // 58
    bool oneMinus; // 5C
    uint8_t unk5D[0x70 - 0x5D]; // 5D
#else
    DynArray<CName> wrapperNames; // 48
    anim::EAnimGraphLogicOp logicOp; // 58
    bool oneMinus; // 5C
    uint8_t unk5D[0x70 - 0x5D]; // 5D
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(AnimNode_WrapperValue, 0x70);
RED4EXT_ASSERT_OFFSET(AnimNode_WrapperValue, wrapperNames, 0x48);
RED4EXT_ASSERT_OFFSET(AnimNode_WrapperValue, logicOp, 0x58);
RED4EXT_ASSERT_OFFSET(AnimNode_WrapperValue, oneMinus, 0x5C);
#else
RED4EXT_ASSERT_SIZE(AnimNode_WrapperValue, 0x70);
#endif
} // namespace anim
using animAnimNode_WrapperValue = anim::AnimNode_WrapperValue;
} // namespace RED4ext

// clang-format on
