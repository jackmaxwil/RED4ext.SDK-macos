#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/Scripting/Natives/Generated/quest/IUIManagerNodeType.hpp>

namespace RED4ext
{
namespace quest
{
struct FinalBoardsLoadPonRSave_NodeType : quest::IUIManagerNodeType
{
    static constexpr const char* NAME = "questFinalBoardsLoadPonRSave_NodeType";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    bool loadPointOfNoReturnSave; // 34
    uint8_t unk35[0x38 - 0x35]; // 35
#else
    bool loadPointOfNoReturnSave; // 38
    uint8_t unk39[0x40 - 0x39]; // 39
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(FinalBoardsLoadPonRSave_NodeType, 0x38);
RED4EXT_ASSERT_OFFSET(FinalBoardsLoadPonRSave_NodeType, loadPointOfNoReturnSave, 0x34);
#else
RED4EXT_ASSERT_SIZE(FinalBoardsLoadPonRSave_NodeType, 0x40);
#endif
} // namespace quest
using questFinalBoardsLoadPonRSave_NodeType = quest::FinalBoardsLoadPonRSave_NodeType;
} // namespace RED4ext

// clang-format on
