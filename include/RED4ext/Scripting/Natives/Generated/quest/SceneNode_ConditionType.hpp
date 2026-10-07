#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/CName.hpp>
#include <RED4ext/NativeTypes.hpp>
#include <RED4ext/Scripting/Natives/Generated/quest/ISceneConditionType.hpp>
#include <RED4ext/Scripting/Natives/Generated/quest/SceneConditionType.hpp>
#include <RED4ext/Scripting/Natives/Generated/scn/SceneVersionCheck.hpp>

namespace RED4ext
{
namespace scn { struct SceneResource; }

namespace quest
{
struct SceneNode_ConditionType : quest::ISceneConditionType
{
    static constexpr const char* NAME = "questSceneNode_ConditionType";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    uint8_t unk34[0x38 - 0x34]; // 34
    RaRef<scn::SceneResource> sceneFile; // 38
    scn::SceneVersionCheck SceneVersion; // 40
    quest::SceneConditionType type; // 41
    uint8_t unk42[0x48 - 0x42]; // 42
    CName ActorName; // 48
#else
    RaRef<scn::SceneResource> sceneFile; // 38
    scn::SceneVersionCheck SceneVersion; // 40
    quest::SceneConditionType type; // 41
    uint8_t unk42[0x48 - 0x42]; // 42
    CName ActorName; // 48
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(SceneNode_ConditionType, 0x50);
RED4EXT_ASSERT_OFFSET(SceneNode_ConditionType, sceneFile, 0x38);
RED4EXT_ASSERT_OFFSET(SceneNode_ConditionType, SceneVersion, 0x40);
RED4EXT_ASSERT_OFFSET(SceneNode_ConditionType, type, 0x41);
RED4EXT_ASSERT_OFFSET(SceneNode_ConditionType, ActorName, 0x48);
#else
RED4EXT_ASSERT_SIZE(SceneNode_ConditionType, 0x50);
#endif
} // namespace quest
using questSceneNode_ConditionType = quest::SceneNode_ConditionType;
} // namespace RED4ext

// clang-format on
