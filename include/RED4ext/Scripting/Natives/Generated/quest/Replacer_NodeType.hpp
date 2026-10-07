#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/CName.hpp>
#include <RED4ext/Scripting/Natives/Generated/game/EntityReference.hpp>
#include <RED4ext/Scripting/Natives/Generated/quest/IGameManagerNonSignalStoppingNodeType.hpp>

namespace RED4ext
{
namespace quest
{
struct Replacer_NodeType : quest::IGameManagerNonSignalStoppingNodeType
{
    static constexpr const char* NAME = "questReplacer_NodeType";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    bool enable; // 34
    uint8_t unk35[0x38 - 0x35]; // 35
    game::EntityReference objectRef; // 38
    CName audioOverrideAppearanceName; // 70
#else
    bool enable; // 38
    uint8_t unk39[0x40 - 0x39]; // 39
    game::EntityReference objectRef; // 40
    CName audioOverrideAppearanceName; // 78
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(Replacer_NodeType, 0x78);
RED4EXT_ASSERT_OFFSET(Replacer_NodeType, enable, 0x34);
RED4EXT_ASSERT_OFFSET(Replacer_NodeType, objectRef, 0x38);
RED4EXT_ASSERT_OFFSET(Replacer_NodeType, audioOverrideAppearanceName, 0x70);
#else
RED4EXT_ASSERT_SIZE(Replacer_NodeType, 0x80);
#endif
} // namespace quest
using questReplacer_NodeType = quest::Replacer_NodeType;
} // namespace RED4ext

// clang-format on
