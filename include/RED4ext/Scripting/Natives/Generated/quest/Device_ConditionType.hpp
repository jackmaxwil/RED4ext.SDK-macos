#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/CName.hpp>
#include <RED4ext/Containers/DynArray.hpp>
#include <RED4ext/NativeTypes.hpp>
#include <RED4ext/Scripting/Natives/Generated/quest/Device_ConditionFunctionParameter.hpp>
#include <RED4ext/Scripting/Natives/Generated/quest/IObjectConditionType.hpp>

namespace RED4ext
{
namespace quest
{
struct Device_ConditionType : quest::IObjectConditionType
{
    static constexpr const char* NAME = "questDevice_ConditionType";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    uint8_t unk34[0x38 - 0x34]; // 34
    NodeRef objectRef; // 38
    CName deviceControllerClass; // 40
    CName deviceConditionFunction; // 48
    DynArray<quest::Device_ConditionFunctionParameter> functionParameters; // 50
#else
    NodeRef objectRef; // 38
    CName deviceControllerClass; // 40
    CName deviceConditionFunction; // 48
    DynArray<quest::Device_ConditionFunctionParameter> functionParameters; // 50
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(Device_ConditionType, 0x60);
RED4EXT_ASSERT_OFFSET(Device_ConditionType, objectRef, 0x38);
RED4EXT_ASSERT_OFFSET(Device_ConditionType, deviceControllerClass, 0x40);
RED4EXT_ASSERT_OFFSET(Device_ConditionType, deviceConditionFunction, 0x48);
RED4EXT_ASSERT_OFFSET(Device_ConditionType, functionParameters, 0x50);
#else
RED4EXT_ASSERT_SIZE(Device_ConditionType, 0x60);
#endif
} // namespace quest
using questDevice_ConditionType = quest::Device_ConditionType;
} // namespace RED4ext

// clang-format on
