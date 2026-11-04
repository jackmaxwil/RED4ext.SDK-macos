#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/Scripting/IScriptable.hpp>

namespace RED4ext
{
namespace ink
{
struct SystemNotificationToken : IScriptable
{
    static constexpr const char* NAME = "inkSystemNotificationToken";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    uint8_t unk40[0x170 - 0x40]; // 40
#else
    uint8_t unk40[0x130 - 0x40]; // 40
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(SystemNotificationToken, 0x170);
#else
RED4EXT_ASSERT_SIZE(SystemNotificationToken, 0x130);
#endif
} // namespace ink
using inkSystemNotificationToken = ink::SystemNotificationToken;
} // namespace RED4ext

// clang-format on
