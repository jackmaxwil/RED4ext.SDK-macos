#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/CName.hpp>
#include <RED4ext/Handle.hpp>
#include <RED4ext/Scripting/Natives/Generated/game/EffectExecutor.hpp>
#include <RED4ext/Scripting/Natives/Generated/game/EffectExecutor_AnimFeatureApplyTo.hpp>

namespace RED4ext
{
namespace anim { struct AnimFeature; }

namespace game
{
struct EffectExecutor_AnimFeature : game::EffectExecutor
{
    static constexpr const char* NAME = "gameEffectExecutor_AnimFeature";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    uint8_t unk41[0x48 - 0x41]; // 41
    CName key; // 48
    Handle<anim::AnimFeature> animFeature; // 50
    game::EffectExecutor_AnimFeatureApplyTo applyTo; // 60
    bool ignoreWaterImpacts; // 64
    uint8_t unk65[0x68 - 0x65]; // 65
#else
    CName key; // 48
    Handle<anim::AnimFeature> animFeature; // 50
    game::EffectExecutor_AnimFeatureApplyTo applyTo; // 60
    bool ignoreWaterImpacts; // 64
    uint8_t unk65[0x68 - 0x65]; // 65
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(EffectExecutor_AnimFeature, 0x68);
RED4EXT_ASSERT_OFFSET(EffectExecutor_AnimFeature, key, 0x48);
RED4EXT_ASSERT_OFFSET(EffectExecutor_AnimFeature, animFeature, 0x50);
RED4EXT_ASSERT_OFFSET(EffectExecutor_AnimFeature, applyTo, 0x60);
RED4EXT_ASSERT_OFFSET(EffectExecutor_AnimFeature, ignoreWaterImpacts, 0x64);
#else
RED4EXT_ASSERT_SIZE(EffectExecutor_AnimFeature, 0x68);
#endif
} // namespace game
using gameEffectExecutor_AnimFeature = game::EffectExecutor_AnimFeature;
} // namespace RED4ext

// clang-format on
