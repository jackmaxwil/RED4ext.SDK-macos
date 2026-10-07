#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/CName.hpp>
#include <RED4ext/DynArray.hpp>
#include <RED4ext/Scripting/Natives/Generated/anim/AnimNode_Base.hpp>
#include <RED4ext/Scripting/Natives/Generated/anim/EventFilterType.hpp>
#include <RED4ext/Scripting/Natives/Generated/anim/PoseLink.hpp>
#include <RED4ext/Scripting/Natives/Generated/work/WorkEntryId.hpp>

namespace RED4ext
{
namespace anim
{
struct AnimNode_WorkspotHub : anim::AnimNode_Base
{
    static constexpr const char* NAME = "animAnimNode_WorkspotHub";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    uint8_t unk44[0x1C8 - 0x44]; // 44
    DynArray<work::WorkEntryId> additionalLinkIds; // 1C8
    DynArray<anim::PoseLink> additionalLinks; // 1D8
    CName animLoopEventName; // 1E8
    bool isCoverHubHack; // 1F0
    uint8_t unk1F1[0x1F8 - 0x1F1]; // 1F1
    CName mainEmotionalState; // 1F8
    CName emotionalExpression; // 200
    float facialKeyWeight; // 208
    uint8_t unk20C[0x210 - 0x20C]; // 20C
    CName facialIdleMaleAnimation; // 210
    CName facialIdleKey_MaleAnimation; // 218
    CName facialIdleFemaleAnimation; // 220
    CName facialIdleKey_FemaleAnimation; // 228
    anim::EventFilterType eventFilterType; // 230
    uint8_t unk234[0x238 - 0x234]; // 234
#else
    uint8_t unk48[0x1C8 - 0x48]; // 48
    DynArray<work::WorkEntryId> additionalLinkIds; // 1C8
    DynArray<anim::PoseLink> additionalLinks; // 1D8
    CName animLoopEventName; // 1E8
    bool isCoverHubHack; // 1F0
    uint8_t unk1F1[0x1F8 - 0x1F1]; // 1F1
    CName mainEmotionalState; // 1F8
    CName emotionalExpression; // 200
    float facialKeyWeight; // 208
    uint8_t unk20C[0x210 - 0x20C]; // 20C
    CName facialIdleMaleAnimation; // 210
    CName facialIdleKey_MaleAnimation; // 218
    CName facialIdleFemaleAnimation; // 220
    CName facialIdleKey_FemaleAnimation; // 228
    anim::EventFilterType eventFilterType; // 230
    uint8_t unk234[0x238 - 0x234]; // 234
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(AnimNode_WorkspotHub, 0x238);
RED4EXT_ASSERT_OFFSET(AnimNode_WorkspotHub, additionalLinkIds, 0x1C8);
RED4EXT_ASSERT_OFFSET(AnimNode_WorkspotHub, additionalLinks, 0x1D8);
RED4EXT_ASSERT_OFFSET(AnimNode_WorkspotHub, animLoopEventName, 0x1E8);
RED4EXT_ASSERT_OFFSET(AnimNode_WorkspotHub, isCoverHubHack, 0x1F0);
RED4EXT_ASSERT_OFFSET(AnimNode_WorkspotHub, mainEmotionalState, 0x1F8);
RED4EXT_ASSERT_OFFSET(AnimNode_WorkspotHub, emotionalExpression, 0x200);
RED4EXT_ASSERT_OFFSET(AnimNode_WorkspotHub, facialKeyWeight, 0x208);
RED4EXT_ASSERT_OFFSET(AnimNode_WorkspotHub, facialIdleMaleAnimation, 0x210);
RED4EXT_ASSERT_OFFSET(AnimNode_WorkspotHub, facialIdleKey_MaleAnimation, 0x218);
RED4EXT_ASSERT_OFFSET(AnimNode_WorkspotHub, facialIdleFemaleAnimation, 0x220);
RED4EXT_ASSERT_OFFSET(AnimNode_WorkspotHub, facialIdleKey_FemaleAnimation, 0x228);
RED4EXT_ASSERT_OFFSET(AnimNode_WorkspotHub, eventFilterType, 0x230);
#else
RED4EXT_ASSERT_SIZE(AnimNode_WorkspotHub, 0x238);
#endif
} // namespace anim
using animAnimNode_WorkspotHub = anim::AnimNode_WorkspotHub;
} // namespace RED4ext

// clang-format on
