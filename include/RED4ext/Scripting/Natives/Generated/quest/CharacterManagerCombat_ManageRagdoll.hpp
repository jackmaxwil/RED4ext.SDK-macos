#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/Scripting/Natives/Generated/quest/ICharacterManagerCombat_NodeSubType.hpp>

namespace RED4ext
{
namespace quest
{
struct CharacterManagerCombat_ManageRagdoll : quest::ICharacterManagerCombat_NodeSubType
{
    static constexpr const char* NAME = "questCharacterManagerCombat_ManageRagdoll";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    bool enableRagdoll; // 69
    uint8_t unk6A[0x70 - 0x6A]; // 6A
#else
    bool enableRagdoll; // 70
    uint8_t unk71[0x78 - 0x71]; // 71
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(CharacterManagerCombat_ManageRagdoll, 0x70);
RED4EXT_ASSERT_OFFSET(CharacterManagerCombat_ManageRagdoll, enableRagdoll, 0x69);
#else
RED4EXT_ASSERT_SIZE(CharacterManagerCombat_ManageRagdoll, 0x78);
#endif
} // namespace quest
using questCharacterManagerCombat_ManageRagdoll = quest::CharacterManagerCombat_ManageRagdoll;
} // namespace RED4ext

// clang-format on
