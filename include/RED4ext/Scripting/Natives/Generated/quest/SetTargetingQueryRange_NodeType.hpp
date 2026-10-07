#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/Scripting/Natives/Generated/quest/ISceneManagerNodeType.hpp>

namespace RED4ext
{
namespace quest
{
struct SetTargetingQueryRange_NodeType : quest::ISceneManagerNodeType
{
    static constexpr const char* NAME = "questSetTargetingQueryRange_NodeType";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    float targetingQueryRange; // 34
    bool resetToDefault; // 38
    uint8_t unk39[0x40 - 0x39]; // 39
#else
    float targetingQueryRange; // 38
    bool resetToDefault; // 3C
    uint8_t unk3D[0x40 - 0x3D]; // 3D
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(SetTargetingQueryRange_NodeType, 0x40);
RED4EXT_ASSERT_OFFSET(SetTargetingQueryRange_NodeType, targetingQueryRange, 0x34);
RED4EXT_ASSERT_OFFSET(SetTargetingQueryRange_NodeType, resetToDefault, 0x38);
#else
RED4EXT_ASSERT_SIZE(SetTargetingQueryRange_NodeType, 0x40);
#endif
} // namespace quest
using questSetTargetingQueryRange_NodeType = quest::SetTargetingQueryRange_NodeType;
} // namespace RED4ext

// clang-format on
