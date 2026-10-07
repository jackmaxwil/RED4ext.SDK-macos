#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/Containers/DynArray.hpp>
#include <RED4ext/Handle.hpp>
#include <RED4ext/NativeTypes.hpp>
#include <RED4ext/Scripting/Natives/Generated/CResource.hpp>
#include <RED4ext/Scripting/Natives/Generated/anim/AnimDatabaseCollectionEntry.hpp>
#include <RED4ext/Scripting/Natives/Generated/anim/AnimFeatureEntry.hpp>

namespace RED4ext
{
namespace anim { struct AnimNode_Base; }
namespace anim { struct AnimNode_Root; }
namespace anim { struct AnimVariableContainer; }
namespace anim { struct Rig; }

namespace anim
{
struct AnimGraph : CResource
{
    static constexpr const char* NAME = "animAnimGraph";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    uint8_t unk39[0x40 - 0x39]; // 39
    Handle<anim::AnimNode_Root> rootNode; // 40
    uint8_t unk50[0x58 - 0x50]; // 50
    Handle<anim::AnimVariableContainer> variables; // 58
    uint8_t unk68[0x78 - 0x68]; // 68
    DynArray<Handle<anim::AnimNode_Base>> nodesToInit; // 78
    uint8_t unk88[0xA0 - 0x88]; // 88
    bool useAnimCommands; // A0
    bool useAnimCommandsForCrowd; // A1
    bool useAnimStaticCommands; // A2
    bool useLunaticMode; // A3
    uint8_t unkA4[0xA8 - 0xA4]; // A4
    Ref<anim::Rig> staticCommandsRig; // A8
    bool hackAlwaysSample; // C0
    uint8_t unkC1[0xD8 - 0xC1]; // C1
    DynArray<anim::AnimFeatureEntry> animFeatures; // D8
    float timeDeltaMultiplier; // E8
    bool isPaused; // EC
    bool oneFrameToggle; // ED
    bool hasMixerSlot; // EE
    uint8_t unkEF[0xF8 - 0xEF]; // EF
    DynArray<anim::AnimDatabaseCollectionEntry> additionalAnimDatabases; // F8
    uint8_t unk108[0x120 - 0x108]; // 108
#else
    Handle<anim::AnimNode_Root> rootNode; // 40
    uint8_t unk50[0x58 - 0x50]; // 50
    Handle<anim::AnimVariableContainer> variables; // 58
    uint8_t unk68[0x78 - 0x68]; // 68
    DynArray<Handle<anim::AnimNode_Base>> nodesToInit; // 78
    uint8_t unk88[0xA0 - 0x88]; // 88
    bool useAnimCommands; // A0
    bool useAnimCommandsForCrowd; // A1
    bool useAnimStaticCommands; // A2
    bool useLunaticMode; // A3
    uint8_t unkA4[0xA8 - 0xA4]; // A4
    Ref<anim::Rig> staticCommandsRig; // A8
    bool hackAlwaysSample; // C0
    uint8_t unkC1[0xD8 - 0xC1]; // C1
    DynArray<anim::AnimFeatureEntry> animFeatures; // D8
    float timeDeltaMultiplier; // E8
    bool isPaused; // EC
    bool oneFrameToggle; // ED
    bool hasMixerSlot; // EE
    uint8_t unkEF[0xF8 - 0xEF]; // EF
    DynArray<anim::AnimDatabaseCollectionEntry> additionalAnimDatabases; // F8
    uint8_t unk108[0x120 - 0x108]; // 108
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(AnimGraph, 0x120);
RED4EXT_ASSERT_OFFSET(AnimGraph, rootNode, 0x40);
RED4EXT_ASSERT_OFFSET(AnimGraph, variables, 0x58);
RED4EXT_ASSERT_OFFSET(AnimGraph, nodesToInit, 0x78);
RED4EXT_ASSERT_OFFSET(AnimGraph, useAnimCommands, 0xA0);
RED4EXT_ASSERT_OFFSET(AnimGraph, useAnimCommandsForCrowd, 0xA1);
RED4EXT_ASSERT_OFFSET(AnimGraph, useAnimStaticCommands, 0xA2);
RED4EXT_ASSERT_OFFSET(AnimGraph, useLunaticMode, 0xA3);
RED4EXT_ASSERT_OFFSET(AnimGraph, staticCommandsRig, 0xA8);
RED4EXT_ASSERT_OFFSET(AnimGraph, hackAlwaysSample, 0xC0);
RED4EXT_ASSERT_OFFSET(AnimGraph, animFeatures, 0xD8);
RED4EXT_ASSERT_OFFSET(AnimGraph, timeDeltaMultiplier, 0xE8);
RED4EXT_ASSERT_OFFSET(AnimGraph, isPaused, 0xEC);
RED4EXT_ASSERT_OFFSET(AnimGraph, oneFrameToggle, 0xED);
RED4EXT_ASSERT_OFFSET(AnimGraph, hasMixerSlot, 0xEE);
RED4EXT_ASSERT_OFFSET(AnimGraph, additionalAnimDatabases, 0xF8);
#else
RED4EXT_ASSERT_SIZE(AnimGraph, 0x120);
#endif
} // namespace anim
using animAnimGraph = anim::AnimGraph;
} // namespace RED4ext

// clang-format on
