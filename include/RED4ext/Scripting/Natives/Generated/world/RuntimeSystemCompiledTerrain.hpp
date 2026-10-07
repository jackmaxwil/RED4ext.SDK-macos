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
struct RuntimeSystemCompiledTerrain : world::IRuntimeSystem
{
    static constexpr const char* NAME = "worldRuntimeSystemCompiledTerrain";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    uint8_t unk48[0x90 - 0x48]; // 48
#else
    uint8_t unk48[0x98 - 0x48]; // 48
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(RuntimeSystemCompiledTerrain, 0x90);
#else
RED4EXT_ASSERT_SIZE(RuntimeSystemCompiledTerrain, 0x98);
#endif
} // namespace world
using worldRuntimeSystemCompiledTerrain = world::RuntimeSystemCompiledTerrain;
} // namespace RED4ext

// clang-format on
