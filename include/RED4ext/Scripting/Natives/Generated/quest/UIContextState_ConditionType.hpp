#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/Scripting/Natives/Generated/game/ui/Context.hpp>
#include <RED4ext/Scripting/Natives/Generated/quest/IUIConditionType.hpp>

namespace RED4ext
{
namespace quest
{
struct UIContextState_ConditionType : quest::IUIConditionType
{
    static constexpr const char* NAME = "questUIContextState_ConditionType";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    game::ui::Context state; // 34
    bool active; // 38
    uint8_t unk39[0x40 - 0x39]; // 39
#else
    game::ui::Context state; // 38
    bool active; // 3C
    uint8_t unk3D[0x40 - 0x3D]; // 3D
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(UIContextState_ConditionType, 0x40);
RED4EXT_ASSERT_OFFSET(UIContextState_ConditionType, state, 0x34);
RED4EXT_ASSERT_OFFSET(UIContextState_ConditionType, active, 0x38);
#else
RED4EXT_ASSERT_SIZE(UIContextState_ConditionType, 0x40);
#endif
} // namespace quest
using questUIContextState_ConditionType = quest::UIContextState_ConditionType;
} // namespace RED4ext

// clang-format on
