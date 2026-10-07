#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/CName.hpp>
#include <RED4ext/NativeTypes.hpp>
#include <RED4ext/Scripting/Natives/Generated/game/EntityReference.hpp>
#include <RED4ext/Scripting/Natives/Generated/quest/ISceneConditionType.hpp>
#include <RED4ext/Scripting/Natives/Generated/scn/SceneVersionCheck.hpp>

namespace RED4ext
{
namespace scn { struct SceneResource; }

namespace quest
{
struct SceneTalking_ConditionType : quest::ISceneConditionType
{
    static constexpr const char* NAME = "questSceneTalking_ConditionType";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    uint8_t unk34[0x38 - 0x34]; // 34
    game::EntityReference GlobalEntityRef; // 38
    RaRef<scn::SceneResource> sceneFile; // 70
    scn::SceneVersionCheck SceneVersion; // 78
    uint8_t unk79[0x80 - 0x79]; // 79
    CName SectionName; // 80
    CString ActorName; // 88
    bool isInverted; // A8
    uint8_t unkA9[0xB0 - 0xA9]; // A9
#else
    game::EntityReference GlobalEntityRef; // 38
    RaRef<scn::SceneResource> sceneFile; // 70
    scn::SceneVersionCheck SceneVersion; // 78
    uint8_t unk79[0x80 - 0x79]; // 79
    CName SectionName; // 80
    CString ActorName; // 88
    bool isInverted; // A8
    uint8_t unkA9[0xB0 - 0xA9]; // A9
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(SceneTalking_ConditionType, 0xB0);
RED4EXT_ASSERT_OFFSET(SceneTalking_ConditionType, GlobalEntityRef, 0x38);
RED4EXT_ASSERT_OFFSET(SceneTalking_ConditionType, sceneFile, 0x70);
RED4EXT_ASSERT_OFFSET(SceneTalking_ConditionType, SceneVersion, 0x78);
RED4EXT_ASSERT_OFFSET(SceneTalking_ConditionType, SectionName, 0x80);
RED4EXT_ASSERT_OFFSET(SceneTalking_ConditionType, ActorName, 0x88);
RED4EXT_ASSERT_OFFSET(SceneTalking_ConditionType, isInverted, 0xA8);
#else
RED4EXT_ASSERT_SIZE(SceneTalking_ConditionType, 0xB0);
#endif
} // namespace quest
using questSceneTalking_ConditionType = quest::SceneTalking_ConditionType;
} // namespace RED4ext

// clang-format on
