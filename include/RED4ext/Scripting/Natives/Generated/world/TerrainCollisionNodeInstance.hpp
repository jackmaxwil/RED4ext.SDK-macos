#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/Scripting/Natives/Generated/world/INodeInstance.hpp>

namespace RED4ext
{
namespace world
{
struct __declspec(align(0x10)) TerrainCollisionNodeInstance : world::INodeInstance
{
    static constexpr const char* NAME = "worldTerrainCollisionNodeInstance";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    uint8_t unk90[0xA0 - 0x90]; // 90
#else
    uint8_t unk90[0xB0 - 0x90]; // 90
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(TerrainCollisionNodeInstance, 0xA0);
#else
RED4EXT_ASSERT_SIZE(TerrainCollisionNodeInstance, 0xB0);
#endif
} // namespace world
using worldTerrainCollisionNodeInstance = world::TerrainCollisionNodeInstance;
} // namespace RED4ext

// clang-format on
