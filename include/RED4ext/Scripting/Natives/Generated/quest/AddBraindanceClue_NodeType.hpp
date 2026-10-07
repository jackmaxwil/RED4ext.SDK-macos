#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/CName.hpp>
#include <RED4ext/Scripting/Natives/Generated/game/ui/EBraindanceLayer.hpp>
#include <RED4ext/Scripting/Natives/Generated/quest/IUIManagerNodeType.hpp>

namespace RED4ext
{
namespace quest
{
struct AddBraindanceClue_NodeType : quest::IUIManagerNodeType
{
    static constexpr const char* NAME = "questAddBraindanceClue_NodeType";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    uint8_t unk34[0x38 - 0x34]; // 34
    CName clueName; // 38
    float startTime; // 40
    float endTime; // 44
    game::ui::EBraindanceLayer layer; // 48
    uint8_t unk4C[0x50 - 0x4C]; // 4C
#else
    CName clueName; // 38
    float startTime; // 40
    float endTime; // 44
    game::ui::EBraindanceLayer layer; // 48
    uint8_t unk4C[0x50 - 0x4C]; // 4C
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(AddBraindanceClue_NodeType, 0x50);
RED4EXT_ASSERT_OFFSET(AddBraindanceClue_NodeType, clueName, 0x38);
RED4EXT_ASSERT_OFFSET(AddBraindanceClue_NodeType, startTime, 0x40);
RED4EXT_ASSERT_OFFSET(AddBraindanceClue_NodeType, endTime, 0x44);
RED4EXT_ASSERT_OFFSET(AddBraindanceClue_NodeType, layer, 0x48);
#else
RED4EXT_ASSERT_SIZE(AddBraindanceClue_NodeType, 0x50);
#endif
} // namespace quest
using questAddBraindanceClue_NodeType = quest::AddBraindanceClue_NodeType;
} // namespace RED4ext

// clang-format on
