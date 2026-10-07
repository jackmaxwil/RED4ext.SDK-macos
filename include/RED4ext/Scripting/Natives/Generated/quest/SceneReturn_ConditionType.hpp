#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/DynArray.hpp>
#include <RED4ext/Handle.hpp>
#include <RED4ext/NativeTypes.hpp>
#include <RED4ext/Scripting/Natives/Generated/quest/ISceneConditionType.hpp>
#include <RED4ext/Scripting/Natives/Generated/scn/SceneVersionCheck.hpp>

namespace RED4ext
{
namespace scn { struct IReturnCondition; }
namespace scn { struct SceneResource; }

namespace quest
{
struct SceneReturn_ConditionType : quest::ISceneConditionType
{
    static constexpr const char* NAME = "questSceneReturn_ConditionType";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    uint8_t unk34[0x38 - 0x34]; // 34
    RaRef<scn::SceneResource> sceneFile; // 38
    scn::SceneVersionCheck SceneVersion; // 40
    uint8_t unk41[0x48 - 0x41]; // 41
    DynArray<Handle<scn::IReturnCondition>> returnConditions; // 48
#else
    RaRef<scn::SceneResource> sceneFile; // 38
    scn::SceneVersionCheck SceneVersion; // 40
    uint8_t unk41[0x48 - 0x41]; // 41
    DynArray<Handle<scn::IReturnCondition>> returnConditions; // 48
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(SceneReturn_ConditionType, 0x58);
RED4EXT_ASSERT_OFFSET(SceneReturn_ConditionType, sceneFile, 0x38);
RED4EXT_ASSERT_OFFSET(SceneReturn_ConditionType, SceneVersion, 0x40);
RED4EXT_ASSERT_OFFSET(SceneReturn_ConditionType, returnConditions, 0x48);
#else
RED4EXT_ASSERT_SIZE(SceneReturn_ConditionType, 0x58);
#endif
} // namespace quest
using questSceneReturn_ConditionType = quest::SceneReturn_ConditionType;
} // namespace RED4ext

// clang-format on
