#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/Scripting/Natives/Generated/game/data/PlayerPossesion.hpp>
#include <RED4ext/Scripting/Natives/Generated/quest/ISceneManagerNodeType.hpp>

namespace RED4ext
{
namespace quest
{
struct SetPossesion_NodeType : quest::ISceneManagerNodeType
{
    static constexpr const char* NAME = "questSetPossesion_NodeType";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    game::data::PlayerPossesion playerPossesion; // 34
#else
    game::data::PlayerPossesion playerPossesion; // 38
    uint8_t unk3C[0x40 - 0x3C]; // 3C
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(SetPossesion_NodeType, 0x38);
RED4EXT_ASSERT_OFFSET(SetPossesion_NodeType, playerPossesion, 0x34);
#else
RED4EXT_ASSERT_SIZE(SetPossesion_NodeType, 0x40);
#endif
} // namespace quest
using questSetPossesion_NodeType = quest::SetPossesion_NodeType;
} // namespace RED4ext

// clang-format on
