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
struct EntitySpotted : AI::AIEvent
{
    static constexpr const char* NAME = "AIEntitySpotted";
    static constexpr const char* ALIAS = "EntitySpotted";

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
RED4EXT_ASSERT_SIZE(EntitySpotted, 0x78);
RED4EXT_ASSERT_OFFSET(EntitySpotted, spotter, 0x50);
RED4EXT_ASSERT_OFFSET(EntitySpotted, spotted, 0x60);
RED4EXT_ASSERT_OFFSET(EntitySpotted, isHostile, 0x70);
#else
RED4EXT_ASSERT_SIZE(EntitySpotted, 0x78);
#endif
} // namespace AI
using AIEntitySpotted = AI::EntitySpotted;
using EntitySpotted = AI::EntitySpotted;
} // namespace RED4ext

// clang-format on
