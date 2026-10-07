#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/NativeTypes.hpp>
#include <RED4ext/Scripting/Natives/Generated/game/data/MetaQuest.hpp>
#include <RED4ext/Scripting/Natives/Generated/quest/IUIManagerNodeType.hpp>

namespace RED4ext
{
namespace quest
{
struct SetMetaQuestProgress_NodeType : quest::IUIManagerNodeType
{
    static constexpr const char* NAME = "questSetMetaQuestProgress_NodeType";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    game::data::MetaQuest metaQuestId; // 34
    uint32_t percent; // 38
    uint8_t unk3C[0x40 - 0x3C]; // 3C
    LocalizationString text; // 40
#else
    game::data::MetaQuest metaQuestId; // 38
    uint32_t percent; // 3C
    LocalizationString text; // 40
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(SetMetaQuestProgress_NodeType, 0x68);
RED4EXT_ASSERT_OFFSET(SetMetaQuestProgress_NodeType, metaQuestId, 0x34);
RED4EXT_ASSERT_OFFSET(SetMetaQuestProgress_NodeType, percent, 0x38);
RED4EXT_ASSERT_OFFSET(SetMetaQuestProgress_NodeType, text, 0x40);
#else
RED4EXT_ASSERT_SIZE(SetMetaQuestProgress_NodeType, 0x68);
#endif
} // namespace quest
using questSetMetaQuestProgress_NodeType = quest::SetMetaQuestProgress_NodeType;
} // namespace RED4ext

// clang-format on
