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
struct PrefetchStreaming_NodeTypeV2 : quest::IWorldDataManagerNodeType
{
    static constexpr const char* NAME = "questPrefetchStreaming_NodeTypeV2";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    uint8_t unk34[0x38 - 0x34]; // 34
    NodeRef prefetchPositionRef; // 38
    float maxDistance; // 40
    bool useStreamingOcclusion; // 44
    bool forceEnable; // 45
    uint8_t unk46[0x48 - 0x46]; // 46
#else
    NodeRef prefetchPositionRef; // 38
    float maxDistance; // 40
    bool useStreamingOcclusion; // 44
    bool forceEnable; // 45
    uint8_t unk46[0x48 - 0x46]; // 46
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(PrefetchStreaming_NodeTypeV2, 0x48);
RED4EXT_ASSERT_OFFSET(PrefetchStreaming_NodeTypeV2, prefetchPositionRef, 0x38);
RED4EXT_ASSERT_OFFSET(PrefetchStreaming_NodeTypeV2, maxDistance, 0x40);
RED4EXT_ASSERT_OFFSET(PrefetchStreaming_NodeTypeV2, useStreamingOcclusion, 0x44);
RED4EXT_ASSERT_OFFSET(PrefetchStreaming_NodeTypeV2, forceEnable, 0x45);
#else
RED4EXT_ASSERT_SIZE(PrefetchStreaming_NodeTypeV2, 0x48);
#endif
} // namespace quest
using questPrefetchStreaming_NodeTypeV2 = quest::PrefetchStreaming_NodeTypeV2;
} // namespace RED4ext

// clang-format on
