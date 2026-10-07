#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/Scripting/Natives/Generated/game/data/AITicketCheck_Record.hpp>

namespace RED4ext
{
namespace game::data
{
struct AISquadDistanceRelationToSectorCheck_Record : game::data::AITicketCheck_Record
{
    static constexpr const char* NAME = "gamedataAISquadDistanceRelationToSectorCheck_Record";
    static constexpr const char* ALIAS = "AISquadDistanceRelationToSectorCheck_Record";

#ifdef __APPLE__
    uint8_t unk60[0x70 - 0x60]; // 60
#else
    uint8_t unk68[0x78 - 0x68]; // 68
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(AISquadDistanceRelationToSectorCheck_Record, 0x70);
#else
RED4EXT_ASSERT_SIZE(AISquadDistanceRelationToSectorCheck_Record, 0x78);
#endif
} // namespace game::data
using gamedataAISquadDistanceRelationToSectorCheck_Record = game::data::AISquadDistanceRelationToSectorCheck_Record;
using AISquadDistanceRelationToSectorCheck_Record = game::data::AISquadDistanceRelationToSectorCheck_Record;
} // namespace RED4ext

// clang-format on
