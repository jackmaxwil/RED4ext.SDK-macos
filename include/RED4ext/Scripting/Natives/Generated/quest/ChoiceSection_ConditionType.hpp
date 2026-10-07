#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/CName.hpp>
#include <RED4ext/NativeTypes.hpp>
#include <RED4ext/Scripting/Natives/Generated/quest/ChoiceSection_ConditionTypeMode.hpp>
#include <RED4ext/Scripting/Natives/Generated/quest/ISceneConditionType.hpp>
#include <RED4ext/Scripting/Natives/Generated/scn/NodeId.hpp>
#include <RED4ext/Scripting/Natives/Generated/scn/SceneVersionCheck.hpp>

namespace RED4ext
{
namespace scn { struct SceneResource; }

namespace quest
{
struct ChoiceSection_ConditionType : quest::ISceneConditionType
{
    static constexpr const char* NAME = "questChoiceSection_ConditionType";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    uint8_t unk34[0x38 - 0x34]; // 34
    RaRef<scn::SceneResource> sceneFile; // 38
    scn::SceneVersionCheck SceneVersion; // 40
    uint8_t unk41[0x44 - 0x41]; // 41
    scn::NodeId choiceSectionId; // 44
    CName choiceSectionName; // 48
    CName optionName; // 50
    quest::ChoiceSection_ConditionTypeMode mode; // 58
    uint8_t unk59[0x60 - 0x59]; // 59
#else
    RaRef<scn::SceneResource> sceneFile; // 38
    scn::SceneVersionCheck SceneVersion; // 40
    uint8_t unk41[0x44 - 0x41]; // 41
    scn::NodeId choiceSectionId; // 44
    CName choiceSectionName; // 48
    CName optionName; // 50
    quest::ChoiceSection_ConditionTypeMode mode; // 58
    uint8_t unk59[0x60 - 0x59]; // 59
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(ChoiceSection_ConditionType, 0x60);
RED4EXT_ASSERT_OFFSET(ChoiceSection_ConditionType, sceneFile, 0x38);
RED4EXT_ASSERT_OFFSET(ChoiceSection_ConditionType, SceneVersion, 0x40);
RED4EXT_ASSERT_OFFSET(ChoiceSection_ConditionType, choiceSectionId, 0x44);
RED4EXT_ASSERT_OFFSET(ChoiceSection_ConditionType, choiceSectionName, 0x48);
RED4EXT_ASSERT_OFFSET(ChoiceSection_ConditionType, optionName, 0x50);
RED4EXT_ASSERT_OFFSET(ChoiceSection_ConditionType, mode, 0x58);
#else
RED4EXT_ASSERT_SIZE(ChoiceSection_ConditionType, 0x60);
#endif
} // namespace quest
using questChoiceSection_ConditionType = quest::ChoiceSection_ConditionType;
} // namespace RED4ext

// clang-format on
