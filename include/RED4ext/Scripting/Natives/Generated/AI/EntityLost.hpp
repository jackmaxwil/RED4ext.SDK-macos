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
struct EntityLost : AI::AIEvent
{
    static constexpr const char* NAME = "AIEntityLost";
    static constexpr const char* ALIAS = "EntityLost";

#ifdef __APPLE__
    uint8_t unk4C[0x50 - 0x4C]; // 4C
    WeakHandle<ent::Entity> spotter; // 50
    WeakHandle<ent::Entity> spotted; // 60
    bool isHostile; // 70
    uint8_t unk71[0x78 - 0x71]; // 71
#else
    WeakHandle<ent::Entity> spotter; // 50
    WeakHandle<ent::Entity> spotted; // 60
    bool isHostile; // 70
    uint8_t unk71[0x78 - 0x71]; // 71
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(EntityLost, 0x78);
RED4EXT_ASSERT_OFFSET(EntityLost, spotter, 0x50);
RED4EXT_ASSERT_OFFSET(EntityLost, spotted, 0x60);
RED4EXT_ASSERT_OFFSET(EntityLost, isHostile, 0x70);
#else
RED4EXT_ASSERT_SIZE(EntityLost, 0x78);
#endif
} // namespace AI
using AIEntityLost = AI::EntityLost;
using EntityLost = AI::EntityLost;
} // namespace RED4ext

// clang-format on
