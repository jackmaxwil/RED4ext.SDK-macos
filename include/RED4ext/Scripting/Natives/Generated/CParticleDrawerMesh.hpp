#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/DynArray.hpp>
#include <RED4ext/NativeTypes.hpp>
#include <RED4ext/Scripting/Natives/Generated/EMeshParticleOrientationMode.hpp>
#include <RED4ext/Scripting/Natives/Generated/IParticleDrawer.hpp>

namespace RED4ext
{
struct CMesh;

struct CParticleDrawerMesh : IParticleDrawer
{
    static constexpr const char* NAME = "CParticleDrawerMesh";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    uint8_t unk34[0x38 - 0x34]; // 34
    DynArray<Ref<CMesh>> meshes; // 38
    EMeshParticleOrientationMode orientationMode; // 48
    uint8_t unk4C[0x50 - 0x4C]; // 4C
#else
    DynArray<Ref<CMesh>> meshes; // 38
    EMeshParticleOrientationMode orientationMode; // 48
    uint8_t unk4C[0x50 - 0x4C]; // 4C
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(CParticleDrawerMesh, 0x50);
RED4EXT_ASSERT_OFFSET(CParticleDrawerMesh, meshes, 0x38);
RED4EXT_ASSERT_OFFSET(CParticleDrawerMesh, orientationMode, 0x48);
#else
RED4EXT_ASSERT_SIZE(CParticleDrawerMesh, 0x50);
#endif
} // namespace RED4ext

// clang-format on
