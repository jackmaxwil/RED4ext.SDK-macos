#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/CName.hpp>
#include <RED4ext/NativeTypes.hpp>
#include <RED4ext/Scripting/Natives/Generated/ink/anim/Event.hpp>

namespace RED4ext
{
namespace ink::anim
{
struct ExecuteControllerFunctionEvent : ink::anim::Event
{
    static constexpr const char* NAME = "inkanimExecuteControllerFunctionEvent";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    uint8_t unk44[0x48 - 0x44]; // 44
    CName controllerType; // 48
    CName eventName; // 50
    CString params; // 58
#else
    CName controllerType; // 48
    CName eventName; // 50
    CString params; // 58
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(ExecuteControllerFunctionEvent, 0x78);
RED4EXT_ASSERT_OFFSET(ExecuteControllerFunctionEvent, controllerType, 0x48);
RED4EXT_ASSERT_OFFSET(ExecuteControllerFunctionEvent, eventName, 0x50);
RED4EXT_ASSERT_OFFSET(ExecuteControllerFunctionEvent, params, 0x58);
#else
RED4EXT_ASSERT_SIZE(ExecuteControllerFunctionEvent, 0x78);
#endif
} // namespace ink::anim
using inkanimExecuteControllerFunctionEvent = ink::anim::ExecuteControllerFunctionEvent;
} // namespace RED4ext

// clang-format on
