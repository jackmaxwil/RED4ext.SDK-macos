#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/Scripting/Natives/Generated/IParticleDrawer.hpp>

namespace RED4ext
{
struct CParticleDrawerScreen : IParticleDrawer
{
    static constexpr const char* NAME = "CParticleDrawerScreen";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    bool isGPUBased; // 34
    uint8_t unk35[0x38 - 0x35]; // 35
#else
    bool isGPUBased; // 38
    uint8_t unk39[0x40 - 0x39]; // 39
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(CParticleDrawerScreen, 0x38);
RED4EXT_ASSERT_OFFSET(CParticleDrawerScreen, isGPUBased, 0x34);
#else
RED4EXT_ASSERT_SIZE(CParticleDrawerScreen, 0x40);
#endif
} // namespace RED4ext

// clang-format on
