#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/NativeTypes.hpp>
#include <RED4ext/Scripting/Natives/Generated/scn/BraindanceLayer.hpp>
#include <RED4ext/Scripting/Natives/Generated/scn/IBraindanceConditionType.hpp>
#include <RED4ext/Scripting/Natives/Generated/scn/SceneVersionCheck.hpp>

namespace RED4ext
{
namespace scn { struct SceneResource; }

namespace scn
{
struct BraindanceLayer_ConditionType : scn::IBraindanceConditionType
{
    static constexpr const char* NAME = "scnBraindanceLayer_ConditionType";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    scn::BraindanceLayer layer; // 34
    uint8_t unk35[0x38 - 0x35]; // 35
    RaRef<scn::SceneResource> sceneFile; // 38
    scn::SceneVersionCheck SceneVersion; // 40
    uint8_t unk41[0x48 - 0x41]; // 41
#else
    scn::BraindanceLayer layer; // 38
    uint8_t unk39[0x40 - 0x39]; // 39
    RaRef<scn::SceneResource> sceneFile; // 40
    scn::SceneVersionCheck SceneVersion; // 48
    uint8_t unk49[0x50 - 0x49]; // 49
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(BraindanceLayer_ConditionType, 0x48);
RED4EXT_ASSERT_OFFSET(BraindanceLayer_ConditionType, layer, 0x34);
RED4EXT_ASSERT_OFFSET(BraindanceLayer_ConditionType, sceneFile, 0x38);
RED4EXT_ASSERT_OFFSET(BraindanceLayer_ConditionType, SceneVersion, 0x40);
#else
RED4EXT_ASSERT_SIZE(BraindanceLayer_ConditionType, 0x50);
#endif
} // namespace scn
using scnBraindanceLayer_ConditionType = scn::BraindanceLayer_ConditionType;
} // namespace RED4ext

// clang-format on
