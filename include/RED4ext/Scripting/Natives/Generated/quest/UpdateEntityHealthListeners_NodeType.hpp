#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/Scripting/Natives/Generated/game/EntityReference.hpp>
#include <RED4ext/Scripting/Natives/Generated/quest/IUIManagerNodeType.hpp>

namespace RED4ext
{
namespace quest
{
struct UpdateEntityHealthListeners_NodeType : quest::IUIManagerNodeType
{
    static constexpr const char* NAME = "questUpdateEntityHealthListeners_NodeType";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    uint8_t unk34[0x38 - 0x34]; // 34
    game::EntityReference entityRef; // 38
#else
    game::EntityReference entityRef; // 38
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(UpdateEntityHealthListeners_NodeType, 0x70);
RED4EXT_ASSERT_OFFSET(UpdateEntityHealthListeners_NodeType, entityRef, 0x38);
#else
RED4EXT_ASSERT_SIZE(UpdateEntityHealthListeners_NodeType, 0x70);
#endif
} // namespace quest
using questUpdateEntityHealthListeners_NodeType = quest::UpdateEntityHealthListeners_NodeType;
} // namespace RED4ext

// clang-format on
