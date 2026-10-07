#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/CName.hpp>

namespace RED4ext
{
namespace net
{
struct IComponentState
{
    static constexpr const char* NAME = "netIComponentState";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    uint8_t unk00[0x10 - 0x0]; // 0
    CName componentName; // 10
    bool enabled; // 18
    uint8_t unk19[0x1C - 0x19]; // 19
    ~IComponentState() {} // non-POD, so clang reuses the tail padding like the game
#else
    uint8_t unk00[0x10 - 0x0]; // 0
    CName componentName; // 10
    bool enabled; // 18
    uint8_t unk19[0x20 - 0x19]; // 19
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(IComponentState, 0x20);
RED4EXT_ASSERT_OFFSET(IComponentState, componentName, 0x10);
RED4EXT_ASSERT_OFFSET(IComponentState, enabled, 0x18);
#else
RED4EXT_ASSERT_SIZE(IComponentState, 0x20);
#endif
} // namespace net
using netIComponentState = net::IComponentState;
} // namespace RED4ext

// clang-format on
