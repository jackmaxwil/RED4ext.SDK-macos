#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/Scripting/Natives/Generated/IParticleDrawer.hpp>

namespace RED4ext
{
struct CParticleDrawerSphereAligned : IParticleDrawer
{
    static constexpr const char* NAME = "CParticleDrawerSphereAligned";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    bool verticalFixed; // 34
    bool isGPUBased; // 35
    uint8_t unk36[0x38 - 0x36]; // 36
#else
    bool verticalFixed; // 38
    bool isGPUBased; // 39
    uint8_t unk3A[0x40 - 0x3A]; // 3A
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(CParticleDrawerSphereAligned, 0x38);
RED4EXT_ASSERT_OFFSET(CParticleDrawerSphereAligned, verticalFixed, 0x34);
RED4EXT_ASSERT_OFFSET(CParticleDrawerSphereAligned, isGPUBased, 0x35);
#else
RED4EXT_ASSERT_SIZE(CParticleDrawerSphereAligned, 0x40);
#endif
} // namespace RED4ext

// clang-format on
