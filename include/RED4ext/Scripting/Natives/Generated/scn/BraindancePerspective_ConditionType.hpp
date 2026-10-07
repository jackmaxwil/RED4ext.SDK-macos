#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/NativeTypes.hpp>
#include <RED4ext/Scripting/Natives/Generated/scn/BraindancePerspective.hpp>
#include <RED4ext/Scripting/Natives/Generated/scn/IBraindanceConditionType.hpp>
#include <RED4ext/Scripting/Natives/Generated/scn/SceneVersionCheck.hpp>

namespace RED4ext
{
namespace scn { struct SceneResource; }

namespace scn
{
struct BraindancePerspective_ConditionType : scn::IBraindanceConditionType
{
    static constexpr const char* NAME = "scnBraindancePerspective_ConditionType";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    scn::BraindancePerspective perspective; // 34
    uint8_t unk35[0x38 - 0x35]; // 35
    RaRef<scn::SceneResource> sceneFile; // 38
    scn::SceneVersionCheck SceneVersion; // 40
    uint8_t unk41[0x48 - 0x41]; // 41
#else
    scn::BraindancePerspective perspective; // 38
    uint8_t unk39[0x40 - 0x39]; // 39
    RaRef<scn::SceneResource> sceneFile; // 40
    scn::SceneVersionCheck SceneVersion; // 48
    uint8_t unk49[0x50 - 0x49]; // 49
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(BraindancePerspective_ConditionType, 0x48);
RED4EXT_ASSERT_OFFSET(BraindancePerspective_ConditionType, perspective, 0x34);
RED4EXT_ASSERT_OFFSET(BraindancePerspective_ConditionType, sceneFile, 0x38);
RED4EXT_ASSERT_OFFSET(BraindancePerspective_ConditionType, SceneVersion, 0x40);
#else
RED4EXT_ASSERT_SIZE(BraindancePerspective_ConditionType, 0x50);
#endif
} // namespace scn
using scnBraindancePerspective_ConditionType = scn::BraindancePerspective_ConditionType;
} // namespace RED4ext

// clang-format on
