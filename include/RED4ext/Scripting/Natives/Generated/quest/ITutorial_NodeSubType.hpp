#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/Scripting/Natives/Generated/quest/IRetNodeType.hpp>

namespace RED4ext
{
namespace quest
{
struct ITutorial_NodeSubType : quest::IRetNodeType
{
    static constexpr const char* NAME = "questITutorial_NodeSubType";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    uint8_t unk30[0x34 - 0x30]; // 30
#else
    uint8_t unk30[0x38 - 0x30]; // 30
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(ITutorial_NodeSubType, 0x38);
#else
RED4EXT_ASSERT_SIZE(ITutorial_NodeSubType, 0x38);
#endif
} // namespace quest
using questITutorial_NodeSubType = quest::ITutorial_NodeSubType;
} // namespace RED4ext

// clang-format on
