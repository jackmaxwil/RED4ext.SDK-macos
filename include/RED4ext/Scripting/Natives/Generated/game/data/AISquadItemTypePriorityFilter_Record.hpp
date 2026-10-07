#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/Scripting/Natives/Generated/game/data/AISquadItemPriorityFilter_Record.hpp>

namespace RED4ext
{
namespace game::data
{
struct AISquadItemTypePriorityFilter_Record : game::data::AISquadItemPriorityFilter_Record
{
    static constexpr const char* NAME = "gamedataAISquadItemTypePriorityFilter_Record";
    static constexpr const char* ALIAS = "AISquadItemTypePriorityFilter_Record";

#ifdef __APPLE__
    uint8_t unk88[0x90 - 0x88]; // 88
#else
    uint8_t unk90[0xA0 - 0x90]; // 90
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(AISquadItemTypePriorityFilter_Record, 0x90);
#else
RED4EXT_ASSERT_SIZE(AISquadItemTypePriorityFilter_Record, 0xA0);
#endif
} // namespace game::data
using gamedataAISquadItemTypePriorityFilter_Record = game::data::AISquadItemTypePriorityFilter_Record;
using AISquadItemTypePriorityFilter_Record = game::data::AISquadItemTypePriorityFilter_Record;
} // namespace RED4ext

// clang-format on
