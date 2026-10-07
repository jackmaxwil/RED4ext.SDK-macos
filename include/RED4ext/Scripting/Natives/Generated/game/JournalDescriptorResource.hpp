#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/DynArray.hpp>
#include <RED4ext/NativeTypes.hpp>
#include <RED4ext/Scripting/Natives/Generated/game/JournalBaseResource.hpp>

namespace RED4ext
{
namespace game
{
struct JournalDescriptorResource : game::JournalBaseResource
{
    static constexpr const char* NAME = "gameJournalDescriptorResource";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    uint8_t unk39[0x40 - 0x39]; // 39
    DynArray<CString> entriesActivatedAtStart; // 40
#else
    DynArray<CString> entriesActivatedAtStart; // 40
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(JournalDescriptorResource, 0x50);
RED4EXT_ASSERT_OFFSET(JournalDescriptorResource, entriesActivatedAtStart, 0x40);
#else
RED4EXT_ASSERT_SIZE(JournalDescriptorResource, 0x50);
#endif
} // namespace game
using gameJournalDescriptorResource = game::JournalDescriptorResource;
} // namespace RED4ext

// clang-format on
