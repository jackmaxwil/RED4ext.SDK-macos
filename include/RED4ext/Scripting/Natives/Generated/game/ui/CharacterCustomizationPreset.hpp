#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/Containers/DynArray.hpp>
#include <RED4ext/Scripting/Natives/Generated/CResource.hpp>
#include <RED4ext/Scripting/Natives/Generated/game/ui/CustomizationGroup.hpp>
#include <RED4ext/Scripting/Natives/Generated/game/ui/PerspectiveInfo.hpp>
#include <RED4ext/Scripting/Natives/Generated/red/TagList.hpp>

namespace RED4ext
{
namespace game::ui
{
struct CharacterCustomizationPreset : CResource
{
    static constexpr const char* NAME = "gameuiCharacterCustomizationPreset";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    bool isMale; // 39
    uint8_t unk3A[0x40 - 0x3A]; // 3A
    DynArray<game::ui::CustomizationGroup> bodyGroups; // 40
    DynArray<game::ui::CustomizationGroup> headGroups; // 50
    DynArray<game::ui::CustomizationGroup> armsGroups; // 60
    DynArray<game::ui::PerspectiveInfo> perspectiveInfo; // 70
    red::TagList tags; // 80
    uint32_t version; // 90
    uint8_t unk94[0x98 - 0x94]; // 94
#else
    bool isMale; // 40
    uint8_t unk41[0x48 - 0x41]; // 41
    DynArray<game::ui::CustomizationGroup> bodyGroups; // 48
    DynArray<game::ui::CustomizationGroup> headGroups; // 58
    DynArray<game::ui::CustomizationGroup> armsGroups; // 68
    DynArray<game::ui::PerspectiveInfo> perspectiveInfo; // 78
    red::TagList tags; // 88
    uint32_t version; // 98
    uint8_t unk9C[0xA0 - 0x9C]; // 9C
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(CharacterCustomizationPreset, 0x98);
RED4EXT_ASSERT_OFFSET(CharacterCustomizationPreset, isMale, 0x39);
RED4EXT_ASSERT_OFFSET(CharacterCustomizationPreset, bodyGroups, 0x40);
RED4EXT_ASSERT_OFFSET(CharacterCustomizationPreset, headGroups, 0x50);
RED4EXT_ASSERT_OFFSET(CharacterCustomizationPreset, armsGroups, 0x60);
RED4EXT_ASSERT_OFFSET(CharacterCustomizationPreset, perspectiveInfo, 0x70);
RED4EXT_ASSERT_OFFSET(CharacterCustomizationPreset, tags, 0x80);
RED4EXT_ASSERT_OFFSET(CharacterCustomizationPreset, version, 0x90);
#else
RED4EXT_ASSERT_SIZE(CharacterCustomizationPreset, 0xA0);
#endif
} // namespace game::ui
using gameuiCharacterCustomizationPreset = game::ui::CharacterCustomizationPreset;
} // namespace RED4ext

// clang-format on
