#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/DynArray.hpp>
#include <RED4ext/Scripting/Natives/Generated/CResource.hpp>
#include <RED4ext/Scripting/Natives/Generated/anim/ActionAnimDatabase_DatabaseRow.hpp>

namespace RED4ext
{
namespace anim
{
struct ActionAnimDatabase : CResource
{
    static constexpr const char* NAME = "animActionAnimDatabase";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    uint8_t unk39[0x40 - 0x39]; // 39
    DynArray<anim::ActionAnimDatabase_DatabaseRow> rows; // 40
    uint8_t unk50[0x70 - 0x50]; // 50
#else
    DynArray<anim::ActionAnimDatabase_DatabaseRow> rows; // 40
    uint8_t unk50[0x70 - 0x50]; // 50
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(ActionAnimDatabase, 0x70);
RED4EXT_ASSERT_OFFSET(ActionAnimDatabase, rows, 0x40);
#else
RED4EXT_ASSERT_SIZE(ActionAnimDatabase, 0x70);
#endif
} // namespace anim
using animActionAnimDatabase = anim::ActionAnimDatabase;
} // namespace RED4ext

// clang-format on
