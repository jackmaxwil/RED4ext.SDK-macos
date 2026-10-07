#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/CName.hpp>
#include <RED4ext/Scripting/Natives/Generated/quest/IUIManagerNodeType.hpp>

namespace RED4ext
{
namespace quest
{
struct DiscoverBraindanceClue_NodeType : quest::IUIManagerNodeType
{
    static constexpr const char* NAME = "questDiscoverBraindanceClue_NodeType";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    uint8_t unk34[0x38 - 0x34]; // 34
    CName clueName; // 38
#else
    CName clueName; // 38
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(DiscoverBraindanceClue_NodeType, 0x40);
RED4EXT_ASSERT_OFFSET(DiscoverBraindanceClue_NodeType, clueName, 0x38);
#else
RED4EXT_ASSERT_SIZE(DiscoverBraindanceClue_NodeType, 0x40);
#endif
} // namespace quest
using questDiscoverBraindanceClue_NodeType = quest::DiscoverBraindanceClue_NodeType;
} // namespace RED4ext

// clang-format on
