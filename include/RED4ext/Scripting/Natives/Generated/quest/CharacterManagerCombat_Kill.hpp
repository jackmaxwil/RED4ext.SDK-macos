#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/Scripting/Natives/Generated/ent/dismemberment/WoundTypeE.hpp>
#include <RED4ext/Scripting/Natives/Generated/physics/RagdollBodyPartE.hpp>
#include <RED4ext/Scripting/Natives/Generated/quest/ICharacterManagerCombat_NodeSubType.hpp>

namespace RED4ext
{
namespace quest
{
struct CharacterManagerCombat_Kill : quest::ICharacterManagerCombat_NodeSubType
{
    static constexpr const char* NAME = "questCharacterManagerCombat_Kill";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    bool noAnimation; // 69
    bool noRagdoll; // 6A
    bool skipDefeatedState; // 6B
    bool doDismemberment; // 6C
    uint8_t unk6D[0x70 - 0x6D]; // 6D
    float dismembermentStrenght; // 70
    physics::RagdollBodyPartE bodyPart; // 74
    ent::dismemberment::WoundTypeE woundType; // 78
    uint8_t unk7A[0x80 - 0x7A]; // 7A
#else
    bool noAnimation; // 70
    bool noRagdoll; // 71
    bool skipDefeatedState; // 72
    bool doDismemberment; // 73
    float dismembermentStrenght; // 74
    physics::RagdollBodyPartE bodyPart; // 78
    ent::dismemberment::WoundTypeE woundType; // 7C
    uint8_t unk7E[0x80 - 0x7E]; // 7E
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(CharacterManagerCombat_Kill, 0x80);
RED4EXT_ASSERT_OFFSET(CharacterManagerCombat_Kill, noAnimation, 0x69);
RED4EXT_ASSERT_OFFSET(CharacterManagerCombat_Kill, noRagdoll, 0x6A);
RED4EXT_ASSERT_OFFSET(CharacterManagerCombat_Kill, skipDefeatedState, 0x6B);
RED4EXT_ASSERT_OFFSET(CharacterManagerCombat_Kill, doDismemberment, 0x6C);
RED4EXT_ASSERT_OFFSET(CharacterManagerCombat_Kill, dismembermentStrenght, 0x70);
RED4EXT_ASSERT_OFFSET(CharacterManagerCombat_Kill, bodyPart, 0x74);
RED4EXT_ASSERT_OFFSET(CharacterManagerCombat_Kill, woundType, 0x78);
#else
RED4EXT_ASSERT_SIZE(CharacterManagerCombat_Kill, 0x80);
#endif
} // namespace quest
using questCharacterManagerCombat_Kill = quest::CharacterManagerCombat_Kill;
} // namespace RED4ext

// clang-format on
