#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/CName.hpp>
#include <RED4ext/Handle.hpp>
#include <RED4ext/Scripting/Natives/Generated/quest/IUIManagerNodeType.hpp>

namespace RED4ext
{
namespace ink { struct UserData; }

namespace quest
{
struct SwitchToScenario_NodeType : quest::IUIManagerNodeType
{
    static constexpr const char* NAME = "questSwitchToScenario_NodeType";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    uint8_t unk34[0x38 - 0x34]; // 34
    CName startScenarioName; // 38
    CName endScenarioName; // 40
    Handle<ink::UserData> userData; // 48
    bool forceOpenDuringFadeout; // 58
    uint8_t unk59[0x60 - 0x59]; // 59
#else
    CName startScenarioName; // 38
    CName endScenarioName; // 40
    Handle<ink::UserData> userData; // 48
    bool forceOpenDuringFadeout; // 58
    uint8_t unk59[0x60 - 0x59]; // 59
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(SwitchToScenario_NodeType, 0x60);
RED4EXT_ASSERT_OFFSET(SwitchToScenario_NodeType, startScenarioName, 0x38);
RED4EXT_ASSERT_OFFSET(SwitchToScenario_NodeType, endScenarioName, 0x40);
RED4EXT_ASSERT_OFFSET(SwitchToScenario_NodeType, userData, 0x48);
RED4EXT_ASSERT_OFFSET(SwitchToScenario_NodeType, forceOpenDuringFadeout, 0x58);
#else
RED4EXT_ASSERT_SIZE(SwitchToScenario_NodeType, 0x60);
#endif
} // namespace quest
using questSwitchToScenario_NodeType = quest::SwitchToScenario_NodeType;
} // namespace RED4ext

// clang-format on
