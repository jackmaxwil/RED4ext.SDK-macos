#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/Containers/DynArray.hpp>
#include <RED4ext/Handle.hpp>
#include <RED4ext/Scripting/Natives/Generated/scn/PlayAnimEvent.hpp>
#include <RED4ext/Scripting/Natives/Generated/scn/fpp/BlendOverride.hpp>
#include <RED4ext/Scripting/Natives/Generated/scn/fpp/GenderSpecificParams.hpp>
#include <RED4ext/Scripting/Natives/Generated/scn/fpp/ParallaxSpace.hpp>

namespace RED4ext
{
namespace scn { struct AnimName; }

namespace scn
{
struct PlayFPPControlAnimEvent : scn::PlayAnimEvent
{
    static constexpr const char* NAME = "scnPlayFPPControlAnimEvent";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    DynArray<scn::fpp::GenderSpecificParams> genderSpecificParams; // A0
    Handle<scn::AnimName> gameplayAnimName; // B0
    bool FPPControlActive; // C0
    uint8_t unkC1[0xC4 - 0xC1]; // C1
    scn::fpp::BlendOverride blendOverride; // C4
    bool cameraUseTrajectorySpace; // C8
    bool idleIsMountedWorkspot; // C9
    bool enableWorldSpaceSmoothing; // CA
    bool isSceneCarrying; // CB
    float cameraBlendInDuration; // CC
    float cameraBlendOutDuration; // D0
    bool stayInScene; // D4
    uint8_t unkD5[0xD8 - 0xD5]; // D5
    float vehicleProceduralCameraWeight; // D8
    float cameraParallaxWeight; // DC
    scn::fpp::ParallaxSpace cameraParallaxSpace; // E0
    float yawLimitLeft; // E4
    float yawLimitRight; // E8
    float pitchLimitTop; // EC
    float pitchLimitBottom; // F0
#else
    DynArray<scn::fpp::GenderSpecificParams> genderSpecificParams; // A0
    Handle<scn::AnimName> gameplayAnimName; // B0
    bool FPPControlActive; // C0
    uint8_t unkC1[0xC4 - 0xC1]; // C1
    scn::fpp::BlendOverride blendOverride; // C4
    bool cameraUseTrajectorySpace; // C8
    bool idleIsMountedWorkspot; // C9
    bool enableWorldSpaceSmoothing; // CA
    bool isSceneCarrying; // CB
    float cameraBlendInDuration; // CC
    float cameraBlendOutDuration; // D0
    bool stayInScene; // D4
    uint8_t unkD5[0xD8 - 0xD5]; // D5
    float vehicleProceduralCameraWeight; // D8
    float cameraParallaxWeight; // DC
    scn::fpp::ParallaxSpace cameraParallaxSpace; // E0
    float yawLimitLeft; // E4
    float yawLimitRight; // E8
    float pitchLimitTop; // EC
    float pitchLimitBottom; // F0
    uint8_t unkF4[0xF8 - 0xF4]; // F4
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(PlayFPPControlAnimEvent, 0xF8);
RED4EXT_ASSERT_OFFSET(PlayFPPControlAnimEvent, genderSpecificParams, 0xA0);
RED4EXT_ASSERT_OFFSET(PlayFPPControlAnimEvent, gameplayAnimName, 0xB0);
RED4EXT_ASSERT_OFFSET(PlayFPPControlAnimEvent, FPPControlActive, 0xC0);
RED4EXT_ASSERT_OFFSET(PlayFPPControlAnimEvent, blendOverride, 0xC4);
RED4EXT_ASSERT_OFFSET(PlayFPPControlAnimEvent, cameraUseTrajectorySpace, 0xC8);
RED4EXT_ASSERT_OFFSET(PlayFPPControlAnimEvent, idleIsMountedWorkspot, 0xC9);
RED4EXT_ASSERT_OFFSET(PlayFPPControlAnimEvent, enableWorldSpaceSmoothing, 0xCA);
RED4EXT_ASSERT_OFFSET(PlayFPPControlAnimEvent, isSceneCarrying, 0xCB);
RED4EXT_ASSERT_OFFSET(PlayFPPControlAnimEvent, cameraBlendInDuration, 0xCC);
RED4EXT_ASSERT_OFFSET(PlayFPPControlAnimEvent, cameraBlendOutDuration, 0xD0);
RED4EXT_ASSERT_OFFSET(PlayFPPControlAnimEvent, stayInScene, 0xD4);
RED4EXT_ASSERT_OFFSET(PlayFPPControlAnimEvent, vehicleProceduralCameraWeight, 0xD8);
RED4EXT_ASSERT_OFFSET(PlayFPPControlAnimEvent, cameraParallaxWeight, 0xDC);
RED4EXT_ASSERT_OFFSET(PlayFPPControlAnimEvent, cameraParallaxSpace, 0xE0);
RED4EXT_ASSERT_OFFSET(PlayFPPControlAnimEvent, yawLimitLeft, 0xE4);
RED4EXT_ASSERT_OFFSET(PlayFPPControlAnimEvent, yawLimitRight, 0xE8);
RED4EXT_ASSERT_OFFSET(PlayFPPControlAnimEvent, pitchLimitTop, 0xEC);
RED4EXT_ASSERT_OFFSET(PlayFPPControlAnimEvent, pitchLimitBottom, 0xF0);
#else
RED4EXT_ASSERT_SIZE(PlayFPPControlAnimEvent, 0xF8);
#endif
} // namespace scn
using scnPlayFPPControlAnimEvent = scn::PlayFPPControlAnimEvent;
} // namespace RED4ext

// clang-format on
