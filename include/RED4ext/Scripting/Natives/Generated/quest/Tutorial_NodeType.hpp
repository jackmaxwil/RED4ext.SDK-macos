#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/Handle.hpp>
#include <RED4ext/Scripting/Natives/Generated/quest/IUIManagerNodeType.hpp>

namespace RED4ext
{
namespace quest { struct ITutorial_NodeSubType; }

namespace quest
{
struct Tutorial_NodeType : quest::IUIManagerNodeType
{
    static constexpr const char* NAME = "questTutorial_NodeType";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    uint8_t unk34[0x38 - 0x34]; // 34
    Handle<quest::ITutorial_NodeSubType> subtype; // 38
#else
    Handle<quest::ITutorial_NodeSubType> subtype; // 38
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(Tutorial_NodeType, 0x48);
RED4EXT_ASSERT_OFFSET(Tutorial_NodeType, subtype, 0x38);
#else
RED4EXT_ASSERT_SIZE(Tutorial_NodeType, 0x48);
#endif
} // namespace quest
using questTutorial_NodeType = quest::Tutorial_NodeType;
} // namespace RED4ext

// clang-format on
