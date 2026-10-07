#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/Scripting/Natives/Generated/game/data/AITicketFilter_Record.hpp>

namespace RED4ext
{
namespace game::data
{
struct AISquadFilterOwnTargetSpotted_Record : game::data::AITicketFilter_Record
{
    static constexpr const char* NAME = "gamedataAISquadFilterOwnTargetSpotted_Record";
    static constexpr const char* ALIAS = "AISquadFilterOwnTargetSpotted_Record";

#ifdef __APPLE__
    uint8_t unk78[0x88 - 0x78]; // 78
#else
    uint8_t unk80[0x90 - 0x80]; // 80
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(AISquadFilterOwnTargetSpotted_Record, 0x88);
#else
RED4EXT_ASSERT_SIZE(AISquadFilterOwnTargetSpotted_Record, 0x90);
#endif
} // namespace game::data
using gamedataAISquadFilterOwnTargetSpotted_Record = game::data::AISquadFilterOwnTargetSpotted_Record;
using AISquadFilterOwnTargetSpotted_Record = game::data::AISquadFilterOwnTargetSpotted_Record;
} // namespace RED4ext

// clang-format on
