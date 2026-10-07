#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/Scripting/Natives/Generated/scn/Marker.hpp>
#include <RED4ext/Scripting/Natives/Generated/scn/PlayFPPControlAnimEvent.hpp>
#include <RED4ext/Scripting/Natives/Generated/scn/RidActorPlacement.hpp>
#include <RED4ext/Scripting/Natives/Generated/scn/RidAnimationSRRefId.hpp>

namespace RED4ext
{
namespace scn
{
struct PlayRidAnimEvent : scn::PlayFPPControlAnimEvent
{
    static constexpr const char* NAME = "scnPlayRidAnimEvent";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    uint32_t ridVersinon; // F4
    scn::RidAnimationSRRefId animResRefId; // F8
    uint8_t unkFC[0x100 - 0xFC]; // FC
    scn::Marker animOriginMarker; // 100
    scn::RidActorPlacement actorPlacement; // 160
    bool actorHasCollision; // 164
    uint8_t unk165[0x168 - 0x165]; // 165
    float blendInTrajectoryBone; // 168
    uint8_t unk16C[0x170 - 0x16C]; // 16C
#else
    uint32_t ridVersinon; // F8
    scn::RidAnimationSRRefId animResRefId; // FC
    scn::Marker animOriginMarker; // 100
    scn::RidActorPlacement actorPlacement; // 160
    bool actorHasCollision; // 164
    uint8_t unk165[0x168 - 0x165]; // 165
    float blendInTrajectoryBone; // 168
    uint8_t unk16C[0x170 - 0x16C]; // 16C
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(PlayRidAnimEvent, 0x170);
RED4EXT_ASSERT_OFFSET(PlayRidAnimEvent, ridVersinon, 0xF4);
RED4EXT_ASSERT_OFFSET(PlayRidAnimEvent, animResRefId, 0xF8);
RED4EXT_ASSERT_OFFSET(PlayRidAnimEvent, animOriginMarker, 0x100);
RED4EXT_ASSERT_OFFSET(PlayRidAnimEvent, actorPlacement, 0x160);
RED4EXT_ASSERT_OFFSET(PlayRidAnimEvent, actorHasCollision, 0x164);
RED4EXT_ASSERT_OFFSET(PlayRidAnimEvent, blendInTrajectoryBone, 0x168);
#else
RED4EXT_ASSERT_SIZE(PlayRidAnimEvent, 0x170);
#endif
} // namespace scn
using scnPlayRidAnimEvent = scn::PlayRidAnimEvent;
} // namespace RED4ext

// clang-format on
