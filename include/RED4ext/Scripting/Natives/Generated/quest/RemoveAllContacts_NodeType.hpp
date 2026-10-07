#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/Containers/DynArray.hpp>
#include <RED4ext/Handle.hpp>
#include <RED4ext/Scripting/Natives/Generated/quest/IPhoneManagerNodeType.hpp>

namespace RED4ext
{
namespace game { struct JournalPath; }

namespace quest
{
struct RemoveAllContacts_NodeType : quest::IPhoneManagerNodeType
{
    static constexpr const char* NAME = "questRemoveAllContacts_NodeType";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    uint8_t unk34[0x38 - 0x34]; // 34
    DynArray<Handle<game::JournalPath>> excludedContacts; // 38
#else
    DynArray<Handle<game::JournalPath>> excludedContacts; // 38
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(RemoveAllContacts_NodeType, 0x48);
RED4EXT_ASSERT_OFFSET(RemoveAllContacts_NodeType, excludedContacts, 0x38);
#else
RED4EXT_ASSERT_SIZE(RemoveAllContacts_NodeType, 0x48);
#endif
} // namespace quest
using questRemoveAllContacts_NodeType = quest::RemoveAllContacts_NodeType;
} // namespace RED4ext

// clang-format on
