#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/Scripting/Natives/Generated/EulerAngles.hpp>
#include <RED4ext/Scripting/Natives/Generated/IParticleDrawer.hpp>

namespace RED4ext
{
struct CParticleDrawerEmitterOrientation : IParticleDrawer
{
    static constexpr const char* NAME = "CParticleDrawerEmitterOrientation";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    EulerAngles coordinateSystem; // 34
    bool isGPUBased; // 40
    uint8_t unk41[0x48 - 0x41]; // 41
#else
    EulerAngles coordinateSystem; // 38
    bool isGPUBased; // 44
    uint8_t unk45[0x48 - 0x45]; // 45
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(CParticleDrawerEmitterOrientation, 0x48);
RED4EXT_ASSERT_OFFSET(CParticleDrawerEmitterOrientation, coordinateSystem, 0x34);
RED4EXT_ASSERT_OFFSET(CParticleDrawerEmitterOrientation, isGPUBased, 0x40);
#else
RED4EXT_ASSERT_SIZE(CParticleDrawerEmitterOrientation, 0x48);
#endif
} // namespace RED4ext

// clang-format on
