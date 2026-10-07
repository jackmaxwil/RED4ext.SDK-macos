#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/CName.hpp>
#include <RED4ext/NativeTypes.hpp>
#include <RED4ext/Scripting/Natives/Generated/quest/ISceneManagerNodeType.hpp>

namespace RED4ext
{
namespace scn { struct SceneResource; }

namespace quest
{
struct ToggleEventExecutionTag_NodeType : quest::ISceneManagerNodeType
{
    static constexpr const char* NAME = "questToggleEventExecutionTag_NodeType";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    uint8_t unk34[0x38 - 0x34]; // 34
    RaRef<scn::SceneResource> sceneFile; // 38
    CName eventExecutionTag; // 40
    bool mute; // 48
    uint8_t unk49[0x50 - 0x49]; // 49
#else
    RaRef<scn::SceneResource> sceneFile; // 38
    CName eventExecutionTag; // 40
    bool mute; // 48
    uint8_t unk49[0x50 - 0x49]; // 49
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(ToggleEventExecutionTag_NodeType, 0x50);
RED4EXT_ASSERT_OFFSET(ToggleEventExecutionTag_NodeType, sceneFile, 0x38);
RED4EXT_ASSERT_OFFSET(ToggleEventExecutionTag_NodeType, eventExecutionTag, 0x40);
RED4EXT_ASSERT_OFFSET(ToggleEventExecutionTag_NodeType, mute, 0x48);
#else
RED4EXT_ASSERT_SIZE(ToggleEventExecutionTag_NodeType, 0x50);
#endif
} // namespace quest
using questToggleEventExecutionTag_NodeType = quest::ToggleEventExecutionTag_NodeType;
} // namespace RED4ext

// clang-format on
