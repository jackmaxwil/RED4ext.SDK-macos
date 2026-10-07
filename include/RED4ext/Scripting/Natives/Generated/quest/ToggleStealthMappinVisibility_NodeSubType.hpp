#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/Scripting/Natives/Generated/game/EntityReference.hpp>
#include <RED4ext/Scripting/Natives/Generated/quest/IUIManagerNodeType.hpp>

namespace RED4ext
{
namespace quest
{
struct ToggleStealthMappinVisibility_NodeSubType : quest::IUIManagerNodeType
{
    static constexpr const char* NAME = "questToggleStealthMappinVisibility_NodeSubType";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    uint8_t unk34[0x38 - 0x34]; // 34
    game::EntityReference entityReference; // 38
    bool show; // 70
    uint8_t unk71[0x78 - 0x71]; // 71
#else
    game::EntityReference entityReference; // 38
    bool show; // 70
    uint8_t unk71[0x78 - 0x71]; // 71
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(ToggleStealthMappinVisibility_NodeSubType, 0x78);
RED4EXT_ASSERT_OFFSET(ToggleStealthMappinVisibility_NodeSubType, entityReference, 0x38);
RED4EXT_ASSERT_OFFSET(ToggleStealthMappinVisibility_NodeSubType, show, 0x70);
#else
RED4EXT_ASSERT_SIZE(ToggleStealthMappinVisibility_NodeSubType, 0x78);
#endif
} // namespace quest
using questToggleStealthMappinVisibility_NodeSubType = quest::ToggleStealthMappinVisibility_NodeSubType;
} // namespace RED4ext

// clang-format on
