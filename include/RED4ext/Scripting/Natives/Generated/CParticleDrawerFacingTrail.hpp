#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/Scripting/Natives/Generated/CParticleDrawerTrail.hpp>

namespace RED4ext
{
struct CParticleDrawerFacingTrail : CParticleDrawerTrail
{
    static constexpr const char* NAME = "CParticleDrawerFacingTrail";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
#else
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(CParticleDrawerFacingTrail, 0x48);
#else
RED4EXT_ASSERT_SIZE(CParticleDrawerFacingTrail, 0x50);
#endif
} // namespace RED4ext

// clang-format on
