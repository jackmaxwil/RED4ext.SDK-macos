#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/Scripting/Natives/Generated/world/IRuntimeSystem.hpp>

namespace RED4ext
{
namespace world
{
struct __declspec(align(0x10)) RuntimeSystemTraffic : world::IRuntimeSystem
{
    static constexpr const char* NAME = "worldRuntimeSystemTraffic";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    uint8_t unk48[0x8360 - 0x48]; // 48
#else
    uint8_t unk48[0x92D0 - 0x48]; // 48
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(RuntimeSystemTraffic, 0x8360);
#else
RED4EXT_ASSERT_SIZE(RuntimeSystemTraffic, 0x92D0);
#endif
} // namespace world
using worldRuntimeSystemTraffic = world::RuntimeSystemTraffic;
} // namespace RED4ext

// clang-format on
