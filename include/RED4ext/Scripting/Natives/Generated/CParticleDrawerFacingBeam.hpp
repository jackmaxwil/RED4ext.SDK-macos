#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/Scripting/Natives/Generated/IParticleDrawer.hpp>
#include <RED4ext/Scripting/Natives/Generated/Vector3.hpp>
#include <RED4ext/Scripting/Natives/Generated/Vector4.hpp>

namespace RED4ext
{
struct __declspec(align(0x10)) CParticleDrawerFacingBeam : IParticleDrawer
{
    static constexpr const char* NAME = "CParticleDrawerFacingBeam";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    float texturesPerUnit; // 34
    bool dynamicTexCoords; // 38
    uint8_t unk39[0x3C - 0x39]; // 39
    float transparencyOffset; // 3C
    float transparencyLength; // 40
    uint32_t numSegments; // 44
    uint8_t unk48[0x50 - 0x48]; // 48
    Vector4 sourceTangent; // 50
    Vector4 targetTangent; // 60
    Vector3 debugTargetTranslation; // 70
#else
    float texturesPerUnit; // 38
    bool dynamicTexCoords; // 3C
    uint8_t unk3D[0x40 - 0x3D]; // 3D
    float transparencyOffset; // 40
    float transparencyLength; // 44
    uint32_t numSegments; // 48
    uint8_t unk4C[0x50 - 0x4C]; // 4C
    Vector4 sourceTangent; // 50
    Vector4 targetTangent; // 60
    Vector3 debugTargetTranslation; // 70
    uint8_t unk7C[0x80 - 0x7C]; // 7C
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(CParticleDrawerFacingBeam, 0x80);
RED4EXT_ASSERT_OFFSET(CParticleDrawerFacingBeam, texturesPerUnit, 0x34);
RED4EXT_ASSERT_OFFSET(CParticleDrawerFacingBeam, dynamicTexCoords, 0x38);
RED4EXT_ASSERT_OFFSET(CParticleDrawerFacingBeam, transparencyOffset, 0x3C);
RED4EXT_ASSERT_OFFSET(CParticleDrawerFacingBeam, transparencyLength, 0x40);
RED4EXT_ASSERT_OFFSET(CParticleDrawerFacingBeam, numSegments, 0x44);
RED4EXT_ASSERT_OFFSET(CParticleDrawerFacingBeam, sourceTangent, 0x50);
RED4EXT_ASSERT_OFFSET(CParticleDrawerFacingBeam, targetTangent, 0x60);
RED4EXT_ASSERT_OFFSET(CParticleDrawerFacingBeam, debugTargetTranslation, 0x70);
#else
RED4EXT_ASSERT_SIZE(CParticleDrawerFacingBeam, 0x80);
#endif
} // namespace RED4ext

// clang-format on
