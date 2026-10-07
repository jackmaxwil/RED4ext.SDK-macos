#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/Handle.hpp>
#include <RED4ext/Scripting/Natives/Generated/anim/AnimSetup.hpp>
#include <RED4ext/Scripting/Natives/Generated/ent/IComponent.hpp>

namespace RED4ext
{
namespace ent { struct AnimationControlBinding; }

namespace ent
{
struct AnimationSetupExtensionComponent : ent::IComponent
{
    static constexpr const char* NAME = "entAnimationSetupExtensionComponent";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    bool isOverrideContainer; // 8D
    uint8_t unk8E[0x90 - 0x8E]; // 8E
    anim::AnimSetup animations; // 90
    Handle<ent::AnimationControlBinding> controlBinding; // B8
#else
    bool isOverrideContainer; // 90
    uint8_t unk91[0x98 - 0x91]; // 91
    anim::AnimSetup animations; // 98
    Handle<ent::AnimationControlBinding> controlBinding; // C0
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(AnimationSetupExtensionComponent, 0xC8);
RED4EXT_ASSERT_OFFSET(AnimationSetupExtensionComponent, isOverrideContainer, 0x8D);
RED4EXT_ASSERT_OFFSET(AnimationSetupExtensionComponent, animations, 0x90);
RED4EXT_ASSERT_OFFSET(AnimationSetupExtensionComponent, controlBinding, 0xB8);
#else
RED4EXT_ASSERT_SIZE(AnimationSetupExtensionComponent, 0xD0);
#endif
} // namespace ent
using entAnimationSetupExtensionComponent = ent::AnimationSetupExtensionComponent;
} // namespace RED4ext

// clang-format on
