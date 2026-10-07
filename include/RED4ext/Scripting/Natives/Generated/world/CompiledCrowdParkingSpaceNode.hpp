#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/Scripting/Natives/Generated/world/Node.hpp>

namespace RED4ext
{
namespace world
{
struct CompiledCrowdParkingSpaceNode : world::Node
{
    static constexpr const char* NAME = "worldCompiledCrowdParkingSpaceNode";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    uint8_t unk32[0x34 - 0x32]; // 32
    uint32_t crowdCreationIndex; // 34
    uint32_t parkingSpaceId; // 38
    uint8_t unk3C[0x40 - 0x3C]; // 3C
#else
    uint32_t crowdCreationIndex; // 38
    uint32_t parkingSpaceId; // 3C
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(CompiledCrowdParkingSpaceNode, 0x40);
RED4EXT_ASSERT_OFFSET(CompiledCrowdParkingSpaceNode, crowdCreationIndex, 0x34);
RED4EXT_ASSERT_OFFSET(CompiledCrowdParkingSpaceNode, parkingSpaceId, 0x38);
#else
RED4EXT_ASSERT_SIZE(CompiledCrowdParkingSpaceNode, 0x40);
#endif
} // namespace world
using worldCompiledCrowdParkingSpaceNode = world::CompiledCrowdParkingSpaceNode;
} // namespace RED4ext

// clang-format on
