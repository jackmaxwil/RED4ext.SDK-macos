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
struct SetFOV_NodeType : quest::ISceneManagerNodeType
{
    static constexpr const char* NAME = "questSetFOV_NodeType";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    float FOV; // 34
#else
    float FOV; // 38
    uint8_t unk3C[0x40 - 0x3C]; // 3C
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(SetFOV_NodeType, 0x38);
RED4EXT_ASSERT_OFFSET(SetFOV_NodeType, FOV, 0x34);
#else
RED4EXT_ASSERT_SIZE(SetFOV_NodeType, 0x40);
#endif
} // namespace quest
using questSetFOV_NodeType = quest::SetFOV_NodeType;
} // namespace RED4ext

// clang-format on
