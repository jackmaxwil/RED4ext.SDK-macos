#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/CName.hpp>
#include <RED4ext/Handle.hpp>
#include <RED4ext/NativeTypes.hpp>
#include <RED4ext/Scripting/Natives/Generated/ink/anim/LoopType.hpp>
#include <RED4ext/Scripting/Natives/Generated/quest/BriefingPlayerType.hpp>
#include <RED4ext/Scripting/Natives/Generated/quest/BriefingSequencePlayerFunction.hpp>
#include <RED4ext/Scripting/Natives/Generated/quest/BriefingType.hpp>
#include <RED4ext/Scripting/Natives/Generated/quest/IUIManagerNodeType.hpp>

namespace RED4ext
{
namespace ink { struct UserData; }
namespace ink { struct WidgetLibraryResource; }

namespace quest
{
struct BriefingSequencePlayer_NodeType : quest::IUIManagerNodeType
{
    static constexpr const char* NAME = "questBriefingSequencePlayer_NodeType";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    quest::BriefingSequencePlayerFunction function; // 34
    RaRef<ink::WidgetLibraryResource> briefingResource; // 38
    Handle<ink::UserData> userData; // 40
    CName audioEvent; // 50
    CName animationName; // 58
    CName startMarkerName; // 60
    CName endMarkerName; // 68
    ink::anim::LoopType loopType; // 70
    uint8_t unk71[0x74 - 0x71]; // 71
    quest::BriefingPlayerType briefingPlayerType; // 74
    quest::BriefingType briefingType; // 78
    bool enableScanner; // 7C
    uint8_t unk7D[0x80 - 0x7D]; // 7D
#else
    quest::BriefingSequencePlayerFunction function; // 38
    uint8_t unk3C[0x40 - 0x3C]; // 3C
    RaRef<ink::WidgetLibraryResource> briefingResource; // 40
    Handle<ink::UserData> userData; // 48
    CName audioEvent; // 58
    CName animationName; // 60
    CName startMarkerName; // 68
    CName endMarkerName; // 70
    ink::anim::LoopType loopType; // 78
    uint8_t unk79[0x7C - 0x79]; // 79
    quest::BriefingPlayerType briefingPlayerType; // 7C
    quest::BriefingType briefingType; // 80
    bool enableScanner; // 84
    uint8_t unk85[0x88 - 0x85]; // 85
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(BriefingSequencePlayer_NodeType, 0x80);
RED4EXT_ASSERT_OFFSET(BriefingSequencePlayer_NodeType, function, 0x34);
RED4EXT_ASSERT_OFFSET(BriefingSequencePlayer_NodeType, briefingResource, 0x38);
RED4EXT_ASSERT_OFFSET(BriefingSequencePlayer_NodeType, userData, 0x40);
RED4EXT_ASSERT_OFFSET(BriefingSequencePlayer_NodeType, audioEvent, 0x50);
RED4EXT_ASSERT_OFFSET(BriefingSequencePlayer_NodeType, animationName, 0x58);
RED4EXT_ASSERT_OFFSET(BriefingSequencePlayer_NodeType, startMarkerName, 0x60);
RED4EXT_ASSERT_OFFSET(BriefingSequencePlayer_NodeType, endMarkerName, 0x68);
RED4EXT_ASSERT_OFFSET(BriefingSequencePlayer_NodeType, loopType, 0x70);
RED4EXT_ASSERT_OFFSET(BriefingSequencePlayer_NodeType, briefingPlayerType, 0x74);
RED4EXT_ASSERT_OFFSET(BriefingSequencePlayer_NodeType, briefingType, 0x78);
RED4EXT_ASSERT_OFFSET(BriefingSequencePlayer_NodeType, enableScanner, 0x7C);
#else
RED4EXT_ASSERT_SIZE(BriefingSequencePlayer_NodeType, 0x88);
#endif
} // namespace quest
using questBriefingSequencePlayer_NodeType = quest::BriefingSequencePlayer_NodeType;
} // namespace RED4ext

// clang-format on
