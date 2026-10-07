#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/CName.hpp>
#include <RED4ext/DynArray.hpp>
#include <RED4ext/Handle.hpp>
#include <RED4ext/NativeTypes.hpp>
#include <RED4ext/Scripting/Natives/Generated/appearance/AlternateAppearanceEntry.hpp>
#include <RED4ext/Scripting/Natives/Generated/appearance/CensorshipEntry.hpp>
#include <RED4ext/Scripting/Natives/Generated/ent/dismemberment/WoundsConfigSet.hpp>
#include <RED4ext/Scripting/Natives/Generated/res/StreamedResource.hpp>

namespace RED4ext
{
namespace appearance { struct AppearanceDefinition; }
namespace appearance { struct CookedAppearanceData; }
namespace ent { struct EntityTemplate; }
namespace ent::dismemberment { struct EffectResource; }
namespace ent::dismemberment { struct WoundResource; }

namespace appearance
{
struct AppearanceResource : res::StreamedResource
{
    static constexpr const char* NAME = "appearanceAppearanceResource";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    uint8_t unk39[0x40 - 0x39]; // 39
    CName baseType; // 40
    CName baseEntityType; // 48
    CName partType; // 50
    CName preset; // 58
    CName alternateAppearanceSettingName; // 60
    DynArray<CName> alternateAppearanceSuffixes; // 68
    DynArray<appearance::AlternateAppearanceEntry> alternateAppearanceMapping; // 78
    int32_t proxyPolyCount; // 88
    bool forceCompileProxy; // 8C
    bool generatePlayerBlockingCollisionForProxy; // 8D
    uint8_t unk8E[0x90 - 0x8E]; // 8E
    RaRef<ent::EntityTemplate> baseEntity; // 90
    DynArray<Handle<appearance::AppearanceDefinition>> appearances; // 98
    DynArray<appearance::CensorshipEntry> censorshipMapping; // A8
    RaRef<appearance::CookedAppearanceData> commonCookData; // B8
    DynArray<Handle<ent::dismemberment::WoundResource>> Wounds; // C0
    DynArray<Handle<ent::dismemberment::EffectResource>> DismEffects; // D0
    ent::dismemberment::WoundsConfigSet DismWoundConfig; // E0
    uint8_t unkF0[0xF8 - 0xF0]; // F0
#else
    CName baseType; // 40
    CName baseEntityType; // 48
    CName partType; // 50
    CName preset; // 58
    CName alternateAppearanceSettingName; // 60
    DynArray<CName> alternateAppearanceSuffixes; // 68
    DynArray<appearance::AlternateAppearanceEntry> alternateAppearanceMapping; // 78
    int32_t proxyPolyCount; // 88
    bool forceCompileProxy; // 8C
    bool generatePlayerBlockingCollisionForProxy; // 8D
    uint8_t unk8E[0x90 - 0x8E]; // 8E
    RaRef<ent::EntityTemplate> baseEntity; // 90
    DynArray<Handle<appearance::AppearanceDefinition>> appearances; // 98
    DynArray<appearance::CensorshipEntry> censorshipMapping; // A8
    RaRef<appearance::CookedAppearanceData> commonCookData; // B8
    DynArray<Handle<ent::dismemberment::WoundResource>> Wounds; // C0
    DynArray<Handle<ent::dismemberment::EffectResource>> DismEffects; // D0
    ent::dismemberment::WoundsConfigSet DismWoundConfig; // E0
    uint8_t unkF0[0xF8 - 0xF0]; // F0
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(AppearanceResource, 0xF8);
RED4EXT_ASSERT_OFFSET(AppearanceResource, baseType, 0x40);
RED4EXT_ASSERT_OFFSET(AppearanceResource, baseEntityType, 0x48);
RED4EXT_ASSERT_OFFSET(AppearanceResource, partType, 0x50);
RED4EXT_ASSERT_OFFSET(AppearanceResource, preset, 0x58);
RED4EXT_ASSERT_OFFSET(AppearanceResource, alternateAppearanceSettingName, 0x60);
RED4EXT_ASSERT_OFFSET(AppearanceResource, alternateAppearanceSuffixes, 0x68);
RED4EXT_ASSERT_OFFSET(AppearanceResource, alternateAppearanceMapping, 0x78);
RED4EXT_ASSERT_OFFSET(AppearanceResource, proxyPolyCount, 0x88);
RED4EXT_ASSERT_OFFSET(AppearanceResource, forceCompileProxy, 0x8C);
RED4EXT_ASSERT_OFFSET(AppearanceResource, generatePlayerBlockingCollisionForProxy, 0x8D);
RED4EXT_ASSERT_OFFSET(AppearanceResource, baseEntity, 0x90);
RED4EXT_ASSERT_OFFSET(AppearanceResource, appearances, 0x98);
RED4EXT_ASSERT_OFFSET(AppearanceResource, censorshipMapping, 0xA8);
RED4EXT_ASSERT_OFFSET(AppearanceResource, commonCookData, 0xB8);
RED4EXT_ASSERT_OFFSET(AppearanceResource, Wounds, 0xC0);
RED4EXT_ASSERT_OFFSET(AppearanceResource, DismEffects, 0xD0);
RED4EXT_ASSERT_OFFSET(AppearanceResource, DismWoundConfig, 0xE0);
#else
RED4EXT_ASSERT_SIZE(AppearanceResource, 0xF8);
#endif
} // namespace appearance
using appearanceAppearanceResource = appearance::AppearanceResource;
} // namespace RED4ext

// clang-format on
