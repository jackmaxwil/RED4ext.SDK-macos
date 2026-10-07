#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/CName.hpp>
#include <RED4ext/Handle.hpp>
#include <RED4ext/Scripting/Natives/Generated/game/ActionAnimationSlideParams.hpp>
#include <RED4ext/Scripting/Natives/Generated/game/ActionReplicatedState.hpp>

namespace RED4ext
{
namespace anim { struct AnimFeature_AIAction; }
namespace game { struct Object; }

namespace game
{
struct ActionAnimationState : game::ActionReplicatedState
{
    static constexpr const char* NAME = "gameActionAnimationState";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    uint8_t unk24[0x28 - 0x24]; // 24
    CName animFeatureName; // 28
    Handle<anim::AnimFeature_AIAction> animFeature; // 30
    bool useRootMotion; // 40
    bool usePoseMatching; // 41
    bool motionDynamicObjectsCheck; // 42
    uint8_t unk43[0x44 - 0x43]; // 43
    game::ActionAnimationSlideParams slideParams; // 44
    WeakHandle<game::Object> targetObject; // 80
    bool sendLoopEvent; // 90
    uint8_t unk91[0x98 - 0x91]; // 91
#else
    CName animFeatureName; // 28
    Handle<anim::AnimFeature_AIAction> animFeature; // 30
    bool useRootMotion; // 40
    bool usePoseMatching; // 41
    bool motionDynamicObjectsCheck; // 42
    uint8_t unk43[0x44 - 0x43]; // 43
    game::ActionAnimationSlideParams slideParams; // 44
    WeakHandle<game::Object> targetObject; // 80
    bool sendLoopEvent; // 90
    uint8_t unk91[0x98 - 0x91]; // 91
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(ActionAnimationState, 0x98);
RED4EXT_ASSERT_OFFSET(ActionAnimationState, animFeatureName, 0x28);
RED4EXT_ASSERT_OFFSET(ActionAnimationState, animFeature, 0x30);
RED4EXT_ASSERT_OFFSET(ActionAnimationState, useRootMotion, 0x40);
RED4EXT_ASSERT_OFFSET(ActionAnimationState, usePoseMatching, 0x41);
RED4EXT_ASSERT_OFFSET(ActionAnimationState, motionDynamicObjectsCheck, 0x42);
RED4EXT_ASSERT_OFFSET(ActionAnimationState, slideParams, 0x44);
RED4EXT_ASSERT_OFFSET(ActionAnimationState, targetObject, 0x80);
RED4EXT_ASSERT_OFFSET(ActionAnimationState, sendLoopEvent, 0x90);
#else
RED4EXT_ASSERT_SIZE(ActionAnimationState, 0x98);
#endif
} // namespace game
using gameActionAnimationState = game::ActionAnimationState;
} // namespace RED4ext

// clang-format on
