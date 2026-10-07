#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/NativeTypes.hpp>
#include <RED4ext/Scripting/Natives/Generated/CResource.hpp>

namespace RED4ext
{
namespace game
{
struct PersistentStateDataResource : CResource
{
    static constexpr const char* NAME = "gamePersistentStateDataResource";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    uint8_t unk39[0x40 - 0x39]; // 39
    DataBuffer buffer; // 40
#else
    DataBuffer buffer; // 40
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(PersistentStateDataResource, 0x68);
RED4EXT_ASSERT_OFFSET(PersistentStateDataResource, buffer, 0x40);
#else
RED4EXT_ASSERT_SIZE(PersistentStateDataResource, 0x68);
#endif
} // namespace game
using gamePersistentStateDataResource = game::PersistentStateDataResource;
} // namespace RED4ext

// clang-format on
