#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/DynArray.hpp>
#include <RED4ext/Scripting/Natives/Generated/quest/SignalStoppingNodeDefinition.hpp>

namespace RED4ext
{
namespace quest
{
struct DeletionMarkerNodeDefinition : quest::SignalStoppingNodeDefinition
{
    static constexpr const char* NAME = "questDeletionMarkerNodeDefinition";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    uint8_t unk42[0x48 - 0x42]; // 42
    DynArray<uint16_t> deletedNodeIds; // 48
#else
    DynArray<uint16_t> deletedNodeIds; // 48
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(DeletionMarkerNodeDefinition, 0x58);
RED4EXT_ASSERT_OFFSET(DeletionMarkerNodeDefinition, deletedNodeIds, 0x48);
#else
RED4EXT_ASSERT_SIZE(DeletionMarkerNodeDefinition, 0x58);
#endif
} // namespace quest
using questDeletionMarkerNodeDefinition = quest::DeletionMarkerNodeDefinition;
} // namespace RED4ext

// clang-format on
