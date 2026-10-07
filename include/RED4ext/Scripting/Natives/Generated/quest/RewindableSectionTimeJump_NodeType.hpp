#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/NativeTypes.hpp>
#include <RED4ext/Scripting/Natives/Generated/quest/ISceneManagerNodeType.hpp>
#include <RED4ext/Scripting/Natives/Generated/scn/PlayDirection.hpp>
#include <RED4ext/Scripting/Natives/Generated/scn/PlaySpeed.hpp>

namespace RED4ext
{
namespace scn { struct SceneResource; }

namespace quest
{
struct RewindableSectionTimeJump_NodeType : quest::ISceneManagerNodeType
{
    static constexpr const char* NAME = "questRewindableSectionTimeJump_NodeType";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    uint8_t unk34[0x38 - 0x34]; // 34
    RaRef<scn::SceneResource> sceneFile; // 38
    uint32_t jumpTargetTime; // 40
    float jumpSpeed; // 44
    scn::PlayDirection postJumpPlayDirection; // 48
    scn::PlaySpeed postJumpPlaySpeed; // 4C
#else
    RaRef<scn::SceneResource> sceneFile; // 38
    uint32_t jumpTargetTime; // 40
    float jumpSpeed; // 44
    scn::PlayDirection postJumpPlayDirection; // 48
    scn::PlaySpeed postJumpPlaySpeed; // 4C
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(RewindableSectionTimeJump_NodeType, 0x50);
RED4EXT_ASSERT_OFFSET(RewindableSectionTimeJump_NodeType, sceneFile, 0x38);
RED4EXT_ASSERT_OFFSET(RewindableSectionTimeJump_NodeType, jumpTargetTime, 0x40);
RED4EXT_ASSERT_OFFSET(RewindableSectionTimeJump_NodeType, jumpSpeed, 0x44);
RED4EXT_ASSERT_OFFSET(RewindableSectionTimeJump_NodeType, postJumpPlayDirection, 0x48);
RED4EXT_ASSERT_OFFSET(RewindableSectionTimeJump_NodeType, postJumpPlaySpeed, 0x4C);
#else
RED4EXT_ASSERT_SIZE(RewindableSectionTimeJump_NodeType, 0x50);
#endif
} // namespace quest
using questRewindableSectionTimeJump_NodeType = quest::RewindableSectionTimeJump_NodeType;
} // namespace RED4ext

// clang-format on
