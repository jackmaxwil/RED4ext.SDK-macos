#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/CName.hpp>
#include <RED4ext/NativeTypes.hpp>
#include <RED4ext/Scripting/Natives/Generated/Vector3.hpp>
#include <RED4ext/Scripting/Natives/Generated/game/EntityReference.hpp>
#include <RED4ext/Scripting/Natives/Generated/quest/DisableableNodeDefinition.hpp>
#include <RED4ext/Scripting/Natives/Generated/tempshit/MapPinOperation.hpp>

namespace RED4ext
{
namespace tempshit
{
struct MapPinManagerNodeDefinition : quest::DisableableNodeDefinition
{
    static constexpr const char* NAME = "tempshitMapPinManagerNodeDefinition";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    uint8_t unk42[0x48 - 0x42]; // 42
    CName mapPinName; // 48
    tempshit::MapPinOperation operation; // 50
    uint8_t unk51[0x58 - 0x51]; // 51
    game::EntityReference nodeRef; // 58
    Vector3 position; // 90
    uint8_t unk9C[0xA0 - 0x9C]; // 9C
    LocalizationString forceCaption; // A0
#else
    CName mapPinName; // 48
    tempshit::MapPinOperation operation; // 50
    uint8_t unk51[0x58 - 0x51]; // 51
    game::EntityReference nodeRef; // 58
    Vector3 position; // 90
    uint8_t unk9C[0xA0 - 0x9C]; // 9C
    LocalizationString forceCaption; // A0
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(MapPinManagerNodeDefinition, 0xC8);
RED4EXT_ASSERT_OFFSET(MapPinManagerNodeDefinition, mapPinName, 0x48);
RED4EXT_ASSERT_OFFSET(MapPinManagerNodeDefinition, operation, 0x50);
RED4EXT_ASSERT_OFFSET(MapPinManagerNodeDefinition, nodeRef, 0x58);
RED4EXT_ASSERT_OFFSET(MapPinManagerNodeDefinition, position, 0x90);
RED4EXT_ASSERT_OFFSET(MapPinManagerNodeDefinition, forceCaption, 0xA0);
#else
RED4EXT_ASSERT_SIZE(MapPinManagerNodeDefinition, 0xC8);
#endif
} // namespace tempshit
using tempshitMapPinManagerNodeDefinition = tempshit::MapPinManagerNodeDefinition;
} // namespace RED4ext

// clang-format on
