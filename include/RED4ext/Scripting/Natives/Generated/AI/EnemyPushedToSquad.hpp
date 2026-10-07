#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/Handle.hpp>
#include <RED4ext/Scripting/Natives/Generated/AI/AIEvent.hpp>

namespace RED4ext
{
namespace ent { struct Entity; }

namespace AI
{
struct EnemyPushedToSquad : AI::AIEvent
{
    static constexpr const char* NAME = "AIEnemyPushedToSquad";
    static constexpr const char* ALIAS = "EnemyPushedToSquad";

#ifdef __APPLE__
    uint8_t unk4C[0x50 - 0x4C]; // 4C
    WeakHandle<ent::Entity> threat; // 50
#else
    WeakHandle<ent::Entity> threat; // 50
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(EnemyPushedToSquad, 0x60);
RED4EXT_ASSERT_OFFSET(EnemyPushedToSquad, threat, 0x50);
#else
RED4EXT_ASSERT_SIZE(EnemyPushedToSquad, 0x60);
#endif
} // namespace AI
using AIEnemyPushedToSquad = AI::EnemyPushedToSquad;
using EnemyPushedToSquad = AI::EnemyPushedToSquad;
} // namespace RED4ext

// clang-format on
