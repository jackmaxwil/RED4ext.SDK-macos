#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/CName.hpp>
#include <RED4ext/DynArray.hpp>
#include <RED4ext/Scripting/Natives/Generated/CResource.hpp>
#include <RED4ext/Scripting/Natives/Generated/ink/MenuEntry.hpp>

namespace RED4ext
{
namespace ink
{
struct MenuResource : CResource
{
    static constexpr const char* NAME = "inkMenuResource";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    uint8_t unk39[0x40 - 0x39]; // 39
    DynArray<ink::MenuEntry> menusEntries; // 40
    DynArray<CName> scenariosNames; // 50
    CName initialScenarioName; // 60
#else
    uint8_t unk40[0x48 - 0x40]; // 40
    DynArray<ink::MenuEntry> menusEntries; // 48
    DynArray<CName> scenariosNames; // 58
    CName initialScenarioName; // 68
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(MenuResource, 0x68);
RED4EXT_ASSERT_OFFSET(MenuResource, menusEntries, 0x40);
RED4EXT_ASSERT_OFFSET(MenuResource, scenariosNames, 0x50);
RED4EXT_ASSERT_OFFSET(MenuResource, initialScenarioName, 0x60);
#else
RED4EXT_ASSERT_SIZE(MenuResource, 0x70);
#endif
} // namespace ink
using inkMenuResource = ink::MenuResource;
} // namespace RED4ext

// clang-format on
