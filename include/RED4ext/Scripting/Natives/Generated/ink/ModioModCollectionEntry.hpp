#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/NativeTypes.hpp>
#include <RED4ext/Scripting/Natives/Generated/ink/ModioModInfos.hpp>
#include <RED4ext/Scripting/Natives/Generated/ink/ModioModState.hpp>

namespace RED4ext
{
namespace ink
{
struct ModioModCollectionEntry
{
    static constexpr const char* NAME = "inkModioModCollectionEntry";
    static constexpr const char* ALIAS = "ModioModCollectionEntry";

#ifdef __APPLE__
    int64_t modID; // 00
    ink::ModioModState modState; // 08
    uint8_t unk0C[0x10 - 0xC]; // C
    ink::ModioModInfos modInfo; // 10
    CString pathOnDisk; // 1E8
    uint64_t sizeOnDisk; // 208
#else
    int64_t modID; // 00
    ink::ModioModState modState; // 08
    uint8_t unk0C[0x10 - 0xC]; // C
    ink::ModioModInfos modInfo; // 10
    CString pathOnDisk; // 210
    uint64_t sizeOnDisk; // 230
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(ModioModCollectionEntry, 0x210);
RED4EXT_ASSERT_OFFSET(ModioModCollectionEntry, modID, 0x0);
RED4EXT_ASSERT_OFFSET(ModioModCollectionEntry, modState, 0x8);
RED4EXT_ASSERT_OFFSET(ModioModCollectionEntry, modInfo, 0x10);
RED4EXT_ASSERT_OFFSET(ModioModCollectionEntry, pathOnDisk, 0x1E8);
RED4EXT_ASSERT_OFFSET(ModioModCollectionEntry, sizeOnDisk, 0x208);
#else
RED4EXT_ASSERT_SIZE(ModioModCollectionEntry, 0x238);
#endif
} // namespace ink
using inkModioModCollectionEntry = ink::ModioModCollectionEntry;
using ModioModCollectionEntry = ink::ModioModCollectionEntry;
} // namespace RED4ext

// clang-format on
