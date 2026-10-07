#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/Scripting/Natives/Generated/game/EntityReference.hpp>
#include <RED4ext/Scripting/Natives/Generated/quest/ITutorial_NodeSubType.hpp>

namespace RED4ext
{
namespace quest
{
struct ShowHighlight_NodeSubType : quest::ITutorial_NodeSubType
{
    static constexpr const char* NAME = "questShowHighlight_NodeSubType";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    bool enable; // 34
    uint8_t unk35[0x38 - 0x35]; // 35
    game::EntityReference entityReference; // 38
#else
    bool enable; // 38
    uint8_t unk39[0x40 - 0x39]; // 39
    game::EntityReference entityReference; // 40
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(ShowHighlight_NodeSubType, 0x70);
RED4EXT_ASSERT_OFFSET(ShowHighlight_NodeSubType, enable, 0x34);
RED4EXT_ASSERT_OFFSET(ShowHighlight_NodeSubType, entityReference, 0x38);
#else
RED4EXT_ASSERT_SIZE(ShowHighlight_NodeSubType, 0x78);
#endif
} // namespace quest
using questShowHighlight_NodeSubType = quest::ShowHighlight_NodeSubType;
} // namespace RED4ext

// clang-format on
