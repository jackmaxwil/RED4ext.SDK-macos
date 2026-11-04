#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/Containers/DynArray.hpp>
#include <RED4ext/Scripting/Natives/Generated/world/CollisionNode.hpp>

namespace RED4ext
{
namespace world
{
struct __declspec(align(0x10)) FoliageDestructionNode : world::CollisionNode
{
    static constexpr const char* NAME = "worldFoliageDestructionNode";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    DynArray<uint32_t> populationIndex; // B0
    uint64_t foliageResourceHash; // C0
    uint32_t dataVersion; // C8
    uint8_t unkCC[0xD0 - 0xCC]; // CC
#else
    DynArray<uint32_t> populationIndex; // C0
    uint64_t foliageResourceHash; // D0
    uint32_t dataVersion; // D8
    uint8_t unkDC[0xE0 - 0xDC]; // DC
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(FoliageDestructionNode, 0xD0);
RED4EXT_ASSERT_OFFSET(FoliageDestructionNode, populationIndex, 0xB0);
RED4EXT_ASSERT_OFFSET(FoliageDestructionNode, foliageResourceHash, 0xC0);
RED4EXT_ASSERT_OFFSET(FoliageDestructionNode, dataVersion, 0xC8);
#else
RED4EXT_ASSERT_SIZE(FoliageDestructionNode, 0xE0);
#endif
} // namespace world
using worldFoliageDestructionNode = world::FoliageDestructionNode;
} // namespace RED4ext

// clang-format on
