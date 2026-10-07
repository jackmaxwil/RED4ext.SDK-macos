#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/Containers/DynArray.hpp>
#include <RED4ext/Handle.hpp>
#include <RED4ext/Scripting/Natives/Generated/anim/AnimNode_Base.hpp>

namespace RED4ext
{
namespace anim { struct AnimNode_State; }
namespace anim { struct AnimNode_StateFrozen; }
namespace anim { struct AnimStateMachineConditionalEntry; }
namespace anim { struct AnimStateTransitionDescription; }
namespace anim { struct IAnimStateTransitionInterpolator; }

namespace anim
{
struct AnimNode_StateMachine : anim::AnimNode_Base
{
    static constexpr const char* NAME = "animAnimNode_StateMachine";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    uint8_t unk44[0x48 - 0x44]; // 44
    DynArray<Handle<anim::AnimNode_State>> states; // 48
    DynArray<Handle<anim::AnimStateMachineConditionalEntry>> conditionalEntries; // 58
    DynArray<Handle<anim::AnimStateTransitionDescription>> transitions; // 68
    DynArray<Handle<anim::AnimStateTransitionDescription>> globalTransitions; // 78
    Handle<anim::IAnimStateTransitionInterpolator> anyStateInterpolator; // 88
    Handle<anim::AnimNode_StateFrozen> frozenState; // 98
    uint32_t defaultStateIndex; // A8
    bool notifyOnEnterState; // AC
    uint8_t unkAD[0x140 - 0xAD]; // AD
#else
    DynArray<Handle<anim::AnimNode_State>> states; // 48
    DynArray<Handle<anim::AnimStateMachineConditionalEntry>> conditionalEntries; // 58
    DynArray<Handle<anim::AnimStateTransitionDescription>> transitions; // 68
    DynArray<Handle<anim::AnimStateTransitionDescription>> globalTransitions; // 78
    Handle<anim::IAnimStateTransitionInterpolator> anyStateInterpolator; // 88
    Handle<anim::AnimNode_StateFrozen> frozenState; // 98
    uint32_t defaultStateIndex; // A8
    bool notifyOnEnterState; // AC
    uint8_t unkAD[0x140 - 0xAD]; // AD
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(AnimNode_StateMachine, 0x140);
RED4EXT_ASSERT_OFFSET(AnimNode_StateMachine, states, 0x48);
RED4EXT_ASSERT_OFFSET(AnimNode_StateMachine, conditionalEntries, 0x58);
RED4EXT_ASSERT_OFFSET(AnimNode_StateMachine, transitions, 0x68);
RED4EXT_ASSERT_OFFSET(AnimNode_StateMachine, globalTransitions, 0x78);
RED4EXT_ASSERT_OFFSET(AnimNode_StateMachine, anyStateInterpolator, 0x88);
RED4EXT_ASSERT_OFFSET(AnimNode_StateMachine, frozenState, 0x98);
RED4EXT_ASSERT_OFFSET(AnimNode_StateMachine, defaultStateIndex, 0xA8);
RED4EXT_ASSERT_OFFSET(AnimNode_StateMachine, notifyOnEnterState, 0xAC);
#else
RED4EXT_ASSERT_SIZE(AnimNode_StateMachine, 0x140);
#endif
} // namespace anim
using animAnimNode_StateMachine = anim::AnimNode_StateMachine;
} // namespace RED4ext

// clang-format on
