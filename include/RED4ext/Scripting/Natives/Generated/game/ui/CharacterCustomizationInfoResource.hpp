#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/CName.hpp>
#include <RED4ext/DynArray.hpp>
#include <RED4ext/Handle.hpp>
#include <RED4ext/Scripting/Natives/Generated/CResource.hpp>
#include <RED4ext/Scripting/Natives/Generated/game/ui/CharacterCustomizationUiPresetInfo.hpp>
#include <RED4ext/Scripting/Natives/Generated/game/ui/CharacterCustomizationVersionUpdateInfo.hpp>
#include <RED4ext/Scripting/Natives/Generated/game/ui/OptionsGroup.hpp>
#include <RED4ext/Scripting/Natives/Generated/game/ui/PerspectiveInfo.hpp>

namespace RED4ext
{
namespace game::ui { struct CharacterCustomizationInfo; }

namespace game::ui
{
struct CharacterCustomizationInfoResource : CResource
{
    static constexpr const char* NAME = "gameuiCharacterCustomizationInfoResource";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    uint8_t unk39[0x40 - 0x39]; // 39
    DynArray<Handle<game::ui::CharacterCustomizationInfo>> headCustomizationOptions; // 40
    DynArray<Handle<game::ui::CharacterCustomizationInfo>> bodyCustomizationOptions; // 50
    DynArray<Handle<game::ui::CharacterCustomizationInfo>> armsCustomizationOptions; // 60
    DynArray<game::ui::OptionsGroup> headGroups; // 70
    DynArray<game::ui::OptionsGroup> bodyGroups; // 80
    DynArray<game::ui::OptionsGroup> armsGroups; // 90
    DynArray<game::ui::PerspectiveInfo> perspectiveInfo; // A0
    DynArray<game::ui::CharacterCustomizationUiPresetInfo> uiPresets; // B0
    DynArray<CName> excludedFromRandomize; // C0
    uint32_t version; // D0
    uint8_t unkD4[0xD8 - 0xD4]; // D4
    DynArray<game::ui::CharacterCustomizationVersionUpdateInfo> versionUpdateInfo; // D8
#else
    DynArray<Handle<game::ui::CharacterCustomizationInfo>> headCustomizationOptions; // 40
    DynArray<Handle<game::ui::CharacterCustomizationInfo>> bodyCustomizationOptions; // 50
    DynArray<Handle<game::ui::CharacterCustomizationInfo>> armsCustomizationOptions; // 60
    DynArray<game::ui::OptionsGroup> headGroups; // 70
    DynArray<game::ui::OptionsGroup> bodyGroups; // 80
    DynArray<game::ui::OptionsGroup> armsGroups; // 90
    DynArray<game::ui::PerspectiveInfo> perspectiveInfo; // A0
    DynArray<game::ui::CharacterCustomizationUiPresetInfo> uiPresets; // B0
    DynArray<CName> excludedFromRandomize; // C0
    uint32_t version; // D0
    uint8_t unkD4[0xD8 - 0xD4]; // D4
    DynArray<game::ui::CharacterCustomizationVersionUpdateInfo> versionUpdateInfo; // D8
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(CharacterCustomizationInfoResource, 0xE8);
RED4EXT_ASSERT_OFFSET(CharacterCustomizationInfoResource, headCustomizationOptions, 0x40);
RED4EXT_ASSERT_OFFSET(CharacterCustomizationInfoResource, bodyCustomizationOptions, 0x50);
RED4EXT_ASSERT_OFFSET(CharacterCustomizationInfoResource, armsCustomizationOptions, 0x60);
RED4EXT_ASSERT_OFFSET(CharacterCustomizationInfoResource, headGroups, 0x70);
RED4EXT_ASSERT_OFFSET(CharacterCustomizationInfoResource, bodyGroups, 0x80);
RED4EXT_ASSERT_OFFSET(CharacterCustomizationInfoResource, armsGroups, 0x90);
RED4EXT_ASSERT_OFFSET(CharacterCustomizationInfoResource, perspectiveInfo, 0xA0);
RED4EXT_ASSERT_OFFSET(CharacterCustomizationInfoResource, uiPresets, 0xB0);
RED4EXT_ASSERT_OFFSET(CharacterCustomizationInfoResource, excludedFromRandomize, 0xC0);
RED4EXT_ASSERT_OFFSET(CharacterCustomizationInfoResource, version, 0xD0);
RED4EXT_ASSERT_OFFSET(CharacterCustomizationInfoResource, versionUpdateInfo, 0xD8);
#else
RED4EXT_ASSERT_SIZE(CharacterCustomizationInfoResource, 0xE8);
#endif
} // namespace game::ui
using gameuiCharacterCustomizationInfoResource = game::ui::CharacterCustomizationInfoResource;
} // namespace RED4ext

// clang-format on
