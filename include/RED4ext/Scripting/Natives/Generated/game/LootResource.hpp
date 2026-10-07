#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/Handle.hpp>
#include <RED4ext/Scripting/Natives/Generated/CResource.hpp>

namespace RED4ext
{
namespace game { struct LootResourceData; }

namespace game
{
struct LootResource : CResource
{
    static constexpr const char* NAME = "gameLootResource";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    uint8_t unk39[0x40 - 0x39]; // 39
    Handle<game::LootResourceData> data; // 40
#else
    Handle<game::LootResourceData> data; // 40
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(LootResource, 0x50);
RED4EXT_ASSERT_OFFSET(LootResource, data, 0x40);
#else
RED4EXT_ASSERT_SIZE(LootResource, 0x50);
#endif
} // namespace game
using gameLootResource = game::LootResource;
} // namespace RED4ext

// clang-format on
