#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/DynArray.hpp>
#include <RED4ext/Scripting/Natives/Generated/CResource.hpp>
#include <RED4ext/Scripting/Natives/Generated/ent/dismemberment/DebrisResourceItem.hpp>

namespace RED4ext
{
namespace ent::dismemberment
{
struct Debris : CResource
{
    static constexpr const char* NAME = "entdismembermentDebris";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    uint8_t unk39[0x40 - 0x39]; // 39
    DynArray<ent::dismemberment::DebrisResourceItem> items; // 40
#else
    DynArray<ent::dismemberment::DebrisResourceItem> items; // 40
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(Debris, 0x50);
RED4EXT_ASSERT_OFFSET(Debris, items, 0x40);
#else
RED4EXT_ASSERT_SIZE(Debris, 0x50);
#endif
} // namespace ent::dismemberment
using entdismembermentDebris = ent::dismemberment::Debris;
} // namespace RED4ext

// clang-format on
