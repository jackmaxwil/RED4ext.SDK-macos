#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/NativeTypes.hpp>
#include <RED4ext/Scripting/Natives/Generated/quest/IUIManagerNodeType.hpp>

namespace RED4ext
{
namespace quest
{
struct FinalBoardsOpenSpeakerScreen_NodeType : quest::IUIManagerNodeType
{
    static constexpr const char* NAME = "questFinalBoardsOpenSpeakerScreen_NodeType";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    bool openSpeakerScreen; // 34
    uint8_t unk35[0x38 - 0x35]; // 35
    CString speakerName; // 38
#else
    bool openSpeakerScreen; // 38
    uint8_t unk39[0x40 - 0x39]; // 39
    CString speakerName; // 40
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(FinalBoardsOpenSpeakerScreen_NodeType, 0x58);
RED4EXT_ASSERT_OFFSET(FinalBoardsOpenSpeakerScreen_NodeType, openSpeakerScreen, 0x34);
RED4EXT_ASSERT_OFFSET(FinalBoardsOpenSpeakerScreen_NodeType, speakerName, 0x38);
#else
RED4EXT_ASSERT_SIZE(FinalBoardsOpenSpeakerScreen_NodeType, 0x60);
#endif
} // namespace quest
using questFinalBoardsOpenSpeakerScreen_NodeType = quest::FinalBoardsOpenSpeakerScreen_NodeType;
} // namespace RED4ext

// clang-format on
