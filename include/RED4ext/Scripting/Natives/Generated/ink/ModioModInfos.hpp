#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/Containers/DynArray.hpp>
#include <RED4ext/NativeTypes.hpp>
#include <RED4ext/Scripting/Natives/Generated/ink/ModioModState.hpp>

namespace RED4ext
{
namespace ink
{
struct ModioModInfos
{
    static constexpr const char* NAME = "inkModioModInfos";
    static constexpr const char* ALIAS = "ModioModInfos";

#ifdef __APPLE__
    CString name; // 00
    CString authorName; // 20
    CString authorLinkedAccountName; // 40
    int64_t authorID; // 60
    CString version; // 68
    CString changelog; // 88
    CString description; // A8
    CString summary; // C8
    int64_t rating; // E8
    uint64_t size; // F0
    int64_t downloadsTotal; // F8
    int64_t dateAdded; // 100
    int64_t dateUpdated; // 108
    int64_t id; // 110
    bool bIsUserSubscribedToMod; // 118
    bool bIsModInstalled; // 119
    bool bIsUserLikingMod; // 11A
    bool bIsModEnabledForUser; // 11B
    bool bIsModNewForUser; // 11C
    bool bIsModWaitingEndOfInstallation; // 11D
    uint8_t unk11E[0x120 - 0x11E]; // 11E
    int64_t gallerySize; // 120
    ink::ModioModState modState; // 128
    uint8_t unk12C[0x1B8 - 0x12C]; // 12C
    DynArray<CString> tags; // 1B8
    DynArray<CString> localizedTags; // 1C8
#else
    CString name; // 00
    CString authorName; // 20
    CString authorLinkedAccountName; // 40
    int64_t authorID; // 60
    CString version; // 68
    CString changelog; // 88
    CString description; // A8
    CString summary; // C8
    int64_t rating; // E8
    uint64_t size; // F0
    int64_t downloadsTotal; // F8
    int64_t dateAdded; // 100
    int64_t dateUpdated; // 108
    int64_t id; // 110
    bool bIsUserSubscribedToMod; // 118
    bool bIsModInstalled; // 119
    bool bIsUserLikingMod; // 11A
    bool bIsModEnabledForUser; // 11B
    bool bIsModNewForUser; // 11C
    bool bIsModWaitingEndOfInstallation; // 11D
    uint8_t unk11E[0x120 - 0x11E]; // 11E
    int64_t gallerySize; // 120
    ink::ModioModState modState; // 128
    uint8_t unk12C[0x1E0 - 0x12C]; // 12C
    DynArray<CString> tags; // 1E0
    DynArray<CString> localizedTags; // 1F0
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(ModioModInfos, 0x1D8);
RED4EXT_ASSERT_OFFSET(ModioModInfos, name, 0x0);
RED4EXT_ASSERT_OFFSET(ModioModInfos, authorName, 0x20);
RED4EXT_ASSERT_OFFSET(ModioModInfos, authorLinkedAccountName, 0x40);
RED4EXT_ASSERT_OFFSET(ModioModInfos, authorID, 0x60);
RED4EXT_ASSERT_OFFSET(ModioModInfos, version, 0x68);
RED4EXT_ASSERT_OFFSET(ModioModInfos, changelog, 0x88);
RED4EXT_ASSERT_OFFSET(ModioModInfos, description, 0xA8);
RED4EXT_ASSERT_OFFSET(ModioModInfos, summary, 0xC8);
RED4EXT_ASSERT_OFFSET(ModioModInfos, rating, 0xE8);
RED4EXT_ASSERT_OFFSET(ModioModInfos, size, 0xF0);
RED4EXT_ASSERT_OFFSET(ModioModInfos, downloadsTotal, 0xF8);
RED4EXT_ASSERT_OFFSET(ModioModInfos, dateAdded, 0x100);
RED4EXT_ASSERT_OFFSET(ModioModInfos, dateUpdated, 0x108);
RED4EXT_ASSERT_OFFSET(ModioModInfos, id, 0x110);
RED4EXT_ASSERT_OFFSET(ModioModInfos, bIsUserSubscribedToMod, 0x118);
RED4EXT_ASSERT_OFFSET(ModioModInfos, bIsModInstalled, 0x119);
RED4EXT_ASSERT_OFFSET(ModioModInfos, bIsUserLikingMod, 0x11A);
RED4EXT_ASSERT_OFFSET(ModioModInfos, bIsModEnabledForUser, 0x11B);
RED4EXT_ASSERT_OFFSET(ModioModInfos, bIsModNewForUser, 0x11C);
RED4EXT_ASSERT_OFFSET(ModioModInfos, bIsModWaitingEndOfInstallation, 0x11D);
RED4EXT_ASSERT_OFFSET(ModioModInfos, gallerySize, 0x120);
RED4EXT_ASSERT_OFFSET(ModioModInfos, modState, 0x128);
RED4EXT_ASSERT_OFFSET(ModioModInfos, tags, 0x1B8);
RED4EXT_ASSERT_OFFSET(ModioModInfos, localizedTags, 0x1C8);
#else
RED4EXT_ASSERT_SIZE(ModioModInfos, 0x200);
#endif
} // namespace ink
using inkModioModInfos = ink::ModioModInfos;
using ModioModInfos = ink::ModioModInfos;
} // namespace RED4ext

// clang-format on
