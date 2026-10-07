#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/Scripting/Natives/Generated/IParticleDrawer.hpp>

namespace RED4ext
{
struct CParticleDrawerTrail : IParticleDrawer
{
    static constexpr const char* NAME = "CParticleDrawerTrail";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    float texturesPerUnit; // 34
    bool dynamicTexCoords; // 38
    uint8_t unk39[0x3C - 0x39]; // 39
    int32_t minSegmentsPer360Degrees; // 3C
    bool ribbonize; // 40
    uint8_t unk41[0x44 - 0x41]; // 41
    float ribbonTesselationDelta; // 44
#else
    float texturesPerUnit; // 38
    bool dynamicTexCoords; // 3C
    uint8_t unk3D[0x40 - 0x3D]; // 3D
    int32_t minSegmentsPer360Degrees; // 40
    bool ribbonize; // 44
    uint8_t unk45[0x48 - 0x45]; // 45
    float ribbonTesselationDelta; // 48
    uint8_t unk4C[0x50 - 0x4C]; // 4C
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(CParticleDrawerTrail, 0x48);
RED4EXT_ASSERT_OFFSET(CParticleDrawerTrail, texturesPerUnit, 0x34);
RED4EXT_ASSERT_OFFSET(CParticleDrawerTrail, dynamicTexCoords, 0x38);
RED4EXT_ASSERT_OFFSET(CParticleDrawerTrail, minSegmentsPer360Degrees, 0x3C);
RED4EXT_ASSERT_OFFSET(CParticleDrawerTrail, ribbonize, 0x40);
RED4EXT_ASSERT_OFFSET(CParticleDrawerTrail, ribbonTesselationDelta, 0x44);
#else
RED4EXT_ASSERT_SIZE(CParticleDrawerTrail, 0x50);
#endif
} // namespace RED4ext

// clang-format on
