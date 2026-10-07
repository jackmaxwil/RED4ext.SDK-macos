#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/Scripting/Natives/Generated/IParticleDrawer.hpp>

namespace RED4ext
{
struct CParticleDrawerMotionBlur : IParticleDrawer
{
    static constexpr const char* NAME = "CParticleDrawerMotionBlur";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    float stretchPerVelocity; // 34
    bool isGPUBased; // 38
    uint8_t unk39[0x40 - 0x39]; // 39
#else
    float stretchPerVelocity; // 38
    bool isGPUBased; // 3C
    uint8_t unk3D[0x40 - 0x3D]; // 3D
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(CParticleDrawerMotionBlur, 0x40);
RED4EXT_ASSERT_OFFSET(CParticleDrawerMotionBlur, stretchPerVelocity, 0x34);
RED4EXT_ASSERT_OFFSET(CParticleDrawerMotionBlur, isGPUBased, 0x38);
#else
RED4EXT_ASSERT_SIZE(CParticleDrawerMotionBlur, 0x40);
#endif
} // namespace RED4ext

// clang-format on
