#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/Handle.hpp>
#include <RED4ext/Scripting/Natives/Generated/scn/PlayFPPControlAnimEvent.hpp>
#include <RED4ext/Scripting/Natives/Generated/scn/PlaySkAnimRootMotionData.hpp>
#include <RED4ext/Scripting/Natives/Generated/scn/PlayerAnimData.hpp>

namespace RED4ext
{
namespace scn { struct AnimName; }
namespace scn { struct EventBlendWorkspotSetupParameters; }

namespace scn
{
struct __declspec(align(0x10)) PlaySkAnimEvent : scn::PlayFPPControlAnimEvent
{
    static constexpr const char* NAME = "scnPlaySkAnimEvent";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    uint8_t unkF4[0xF8 - 0xF4]; // F4
    Handle<scn::AnimName> animName; // F8
    Handle<scn::EventBlendWorkspotSetupParameters> poseBlendOutWorkspot; // 108
    uint8_t unk118[0x120 - 0x118]; // 118
    scn::PlaySkAnimRootMotionData rootMotionData; // 120
    scn::PlayerAnimData playerData; // 1E0
    uint8_t unk1F8[0x200 - 0x1F8]; // 1F8
#else
    Handle<scn::AnimName> animName; // F8
    Handle<scn::EventBlendWorkspotSetupParameters> poseBlendOutWorkspot; // 108
    uint8_t unk118[0x120 - 0x118]; // 118
    scn::PlaySkAnimRootMotionData rootMotionData; // 120
    scn::PlayerAnimData playerData; // 1E0
    uint8_t unk1F8[0x200 - 0x1F8]; // 1F8
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(PlaySkAnimEvent, 0x200);
RED4EXT_ASSERT_OFFSET(PlaySkAnimEvent, animName, 0xF8);
RED4EXT_ASSERT_OFFSET(PlaySkAnimEvent, poseBlendOutWorkspot, 0x108);
RED4EXT_ASSERT_OFFSET(PlaySkAnimEvent, rootMotionData, 0x120);
RED4EXT_ASSERT_OFFSET(PlaySkAnimEvent, playerData, 0x1E0);
#else
RED4EXT_ASSERT_SIZE(PlaySkAnimEvent, 0x200);
#endif
} // namespace scn
using scnPlaySkAnimEvent = scn::PlaySkAnimEvent;
} // namespace RED4ext

// clang-format on
