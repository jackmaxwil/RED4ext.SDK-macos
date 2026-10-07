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
struct RuntimeSystemBinkUpdate : world::IRuntimeSystem
{
    static constexpr const char* NAME = "worldRuntimeSystemBinkUpdate";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    uint8_t unk48[0x68 - 0x48]; // 48
#else
    uint8_t unk48[0x70 - 0x48]; // 48
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(RuntimeSystemBinkUpdate, 0x68);
#else
RED4EXT_ASSERT_SIZE(RuntimeSystemBinkUpdate, 0x70);
#endif
} // namespace world
using worldRuntimeSystemBinkUpdate = world::RuntimeSystemBinkUpdate;
} // namespace RED4ext

// clang-format on
