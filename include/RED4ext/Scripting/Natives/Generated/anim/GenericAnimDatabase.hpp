#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/Containers/DynArray.hpp>
#include <RED4ext/Scripting/Natives/Generated/CResource.hpp>
#include <RED4ext/Scripting/Natives/Generated/anim/GenericAnimDatabase_DatabaseRow.hpp>

namespace RED4ext
{
namespace anim
{
struct GenericAnimDatabase : CResource
{
    static constexpr const char* NAME = "animGenericAnimDatabase";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    uint8_t unk39[0x40 - 0x39]; // 39
    DynArray<anim::GenericAnimDatabase_DatabaseRow> rows; // 40
    uint8_t unk50[0x80 - 0x50]; // 50
#else
    DynArray<anim::GenericAnimDatabase_DatabaseRow> rows; // 40
    uint8_t unk50[0x80 - 0x50]; // 50
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(GenericAnimDatabase, 0x80);
RED4EXT_ASSERT_OFFSET(GenericAnimDatabase, rows, 0x40);
#else
RED4EXT_ASSERT_SIZE(GenericAnimDatabase, 0x80);
#endif
} // namespace anim
using animGenericAnimDatabase = anim::GenericAnimDatabase;
} // namespace RED4ext

// clang-format on
