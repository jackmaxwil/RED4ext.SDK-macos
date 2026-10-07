#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/NativeTypes.hpp>
#include <RED4ext/Scripting/Natives/Generated/world/Node.hpp>

namespace RED4ext
{
struct CParticleSystem;

namespace world
{
struct StaticParticleNode : world::Node
{
    static constexpr const char* NAME = "worldStaticParticleNode";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    uint8_t unk32[0x34 - 0x32]; // 32
    float emissionRate; // 34
    RaRef<CParticleSystem> particleSystem; // 38
    float forcedAutoHideDistance; // 40
    float forcedAutoHideRange; // 44
#else
    float emissionRate; // 38
    uint8_t unk3C[0x40 - 0x3C]; // 3C
    RaRef<CParticleSystem> particleSystem; // 40
    float forcedAutoHideDistance; // 48
    float forcedAutoHideRange; // 4C
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(StaticParticleNode, 0x48);
RED4EXT_ASSERT_OFFSET(StaticParticleNode, emissionRate, 0x34);
RED4EXT_ASSERT_OFFSET(StaticParticleNode, particleSystem, 0x38);
RED4EXT_ASSERT_OFFSET(StaticParticleNode, forcedAutoHideDistance, 0x40);
RED4EXT_ASSERT_OFFSET(StaticParticleNode, forcedAutoHideRange, 0x44);
#else
RED4EXT_ASSERT_SIZE(StaticParticleNode, 0x50);
#endif
} // namespace world
using worldStaticParticleNode = world::StaticParticleNode;
} // namespace RED4ext

// clang-format on
