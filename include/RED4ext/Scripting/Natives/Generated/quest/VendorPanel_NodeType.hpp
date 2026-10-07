#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/CName.hpp>
#include <RED4ext/NativeTypes.hpp>
#include <RED4ext/Scripting/Natives/Generated/game/EntityReference.hpp>
#include <RED4ext/Scripting/Natives/Generated/quest/IUIManagerNodeType.hpp>

namespace RED4ext
{
namespace quest
{
struct VendorPanel_NodeType : quest::IUIManagerNodeType
{
    static constexpr const char* NAME = "questVendorPanel_NodeType";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    bool openVendorPanel; // 34
    uint8_t unk35[0x38 - 0x35]; // 35
    CString vendorId; // 38
    game::EntityReference objectRef; // 58
    CName scenarioName; // 90
    CString assetsLibrary; // 98
    CName rootItemName; // B8
#else
    bool openVendorPanel; // 38
    uint8_t unk39[0x40 - 0x39]; // 39
    CString vendorId; // 40
    game::EntityReference objectRef; // 60
    CName scenarioName; // 98
    CString assetsLibrary; // A0
    CName rootItemName; // C0
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(VendorPanel_NodeType, 0xC0);
RED4EXT_ASSERT_OFFSET(VendorPanel_NodeType, openVendorPanel, 0x34);
RED4EXT_ASSERT_OFFSET(VendorPanel_NodeType, vendorId, 0x38);
RED4EXT_ASSERT_OFFSET(VendorPanel_NodeType, objectRef, 0x58);
RED4EXT_ASSERT_OFFSET(VendorPanel_NodeType, scenarioName, 0x90);
RED4EXT_ASSERT_OFFSET(VendorPanel_NodeType, assetsLibrary, 0x98);
RED4EXT_ASSERT_OFFSET(VendorPanel_NodeType, rootItemName, 0xB8);
#else
RED4EXT_ASSERT_SIZE(VendorPanel_NodeType, 0xC8);
#endif
} // namespace quest
using questVendorPanel_NodeType = quest::VendorPanel_NodeType;
} // namespace RED4ext

// clang-format on
