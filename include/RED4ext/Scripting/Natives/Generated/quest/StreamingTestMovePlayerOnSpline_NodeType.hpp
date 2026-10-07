#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/NativeTypes.hpp>
#include <RED4ext/Scripting/Natives/Generated/quest/IWorldDataManagerNodeType.hpp>

namespace RED4ext
{
namespace quest
{
struct StreamingTestMovePlayerOnSpline_NodeType : quest::IWorldDataManagerNodeType
{
    static constexpr const char* NAME = "questStreamingTestMovePlayerOnSpline_NodeType";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    uint8_t unk34[0x38 - 0x34]; // 34
    NodeRef splineRef; // 38
#else
    NodeRef splineRef; // 38
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(StreamingTestMovePlayerOnSpline_NodeType, 0x40);
RED4EXT_ASSERT_OFFSET(StreamingTestMovePlayerOnSpline_NodeType, splineRef, 0x38);
#else
RED4EXT_ASSERT_SIZE(StreamingTestMovePlayerOnSpline_NodeType, 0x40);
#endif
} // namespace quest
using questStreamingTestMovePlayerOnSpline_NodeType = quest::StreamingTestMovePlayerOnSpline_NodeType;
} // namespace RED4ext

// clang-format on
