#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/CName.hpp>
#include <RED4ext/Containers/DynArray.hpp>
#include <RED4ext/Handle.hpp>
#include <RED4ext/Scripting/Natives/Generated/quest/DisableableNodeDefinition.hpp>
#include <RED4ext/Scripting/Natives/Generated/quest/PlaceholderNodeSocketInfo.hpp>

namespace RED4ext
{
struct ISerializable;

namespace quest
{
struct PlaceholderNodeDefinition : quest::DisableableNodeDefinition
{
    static constexpr const char* NAME = "questPlaceholderNodeDefinition";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    uint8_t unk42[0x48 - 0x42]; // 42
    CName replacedNodeClassName; // 48
    DynArray<quest::PlaceholderNodeSocketInfo> copiedSockets; // 50
    Handle<ISerializable> clipboardHolder; // 60
#else
    CName replacedNodeClassName; // 48
    DynArray<quest::PlaceholderNodeSocketInfo> copiedSockets; // 50
    Handle<ISerializable> clipboardHolder; // 60
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(PlaceholderNodeDefinition, 0x70);
RED4EXT_ASSERT_OFFSET(PlaceholderNodeDefinition, replacedNodeClassName, 0x48);
RED4EXT_ASSERT_OFFSET(PlaceholderNodeDefinition, copiedSockets, 0x50);
RED4EXT_ASSERT_OFFSET(PlaceholderNodeDefinition, clipboardHolder, 0x60);
#else
RED4EXT_ASSERT_SIZE(PlaceholderNodeDefinition, 0x70);
#endif
} // namespace quest
using questPlaceholderNodeDefinition = quest::PlaceholderNodeDefinition;
} // namespace RED4ext

// clang-format on
