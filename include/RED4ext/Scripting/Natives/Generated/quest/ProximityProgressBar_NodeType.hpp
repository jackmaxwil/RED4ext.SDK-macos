#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/CName.hpp>
#include <RED4ext/Scripting/Natives/Generated/EComparisonType.hpp>
#include <RED4ext/Scripting/Natives/Generated/game/EntityReference.hpp>
#include <RED4ext/Scripting/Natives/Generated/quest/IUIManagerNodeType.hpp>

namespace RED4ext
{
namespace quest
{
struct ProximityProgressBar_NodeType : quest::IUIManagerNodeType
{
    static constexpr const char* NAME = "questProximityProgressBar_NodeType";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    bool show; // 34
    uint8_t unk35[0x38 - 0x35]; // 35
    float duration; // 38
    bool reset; // 3C
    uint8_t unk3D[0x40 - 0x3D]; // 3D
    float distance; // 40
    EComparisonType distanceComparisonType; // 44
    game::EntityReference target; // 48
    bool isPlayerActivator; // 80
    uint8_t unk81[0x88 - 0x81]; // 81
    game::EntityReference activator; // 88
    CName appearance; // C0
#else
    bool show; // 38
    uint8_t unk39[0x3C - 0x39]; // 39
    float duration; // 3C
    bool reset; // 40
    uint8_t unk41[0x44 - 0x41]; // 41
    float distance; // 44
    EComparisonType distanceComparisonType; // 48
    uint8_t unk4C[0x50 - 0x4C]; // 4C
    game::EntityReference target; // 50
    bool isPlayerActivator; // 88
    uint8_t unk89[0x90 - 0x89]; // 89
    game::EntityReference activator; // 90
    CName appearance; // C8
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(ProximityProgressBar_NodeType, 0xC8);
RED4EXT_ASSERT_OFFSET(ProximityProgressBar_NodeType, show, 0x34);
RED4EXT_ASSERT_OFFSET(ProximityProgressBar_NodeType, duration, 0x38);
RED4EXT_ASSERT_OFFSET(ProximityProgressBar_NodeType, reset, 0x3C);
RED4EXT_ASSERT_OFFSET(ProximityProgressBar_NodeType, distance, 0x40);
RED4EXT_ASSERT_OFFSET(ProximityProgressBar_NodeType, distanceComparisonType, 0x44);
RED4EXT_ASSERT_OFFSET(ProximityProgressBar_NodeType, target, 0x48);
RED4EXT_ASSERT_OFFSET(ProximityProgressBar_NodeType, isPlayerActivator, 0x80);
RED4EXT_ASSERT_OFFSET(ProximityProgressBar_NodeType, activator, 0x88);
RED4EXT_ASSERT_OFFSET(ProximityProgressBar_NodeType, appearance, 0xC0);
#else
RED4EXT_ASSERT_SIZE(ProximityProgressBar_NodeType, 0xD0);
#endif
} // namespace quest
using questProximityProgressBar_NodeType = quest::ProximityProgressBar_NodeType;
} // namespace RED4ext

// clang-format on
