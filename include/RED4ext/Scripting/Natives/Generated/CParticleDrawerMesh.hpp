#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/Containers/DynArray.hpp>
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
    bool useBatchedRender; // 4C
    uint8_t unk4D[0x50 - 0x4D]; // 4D
#else
    DynArray<Ref<CMesh>> meshes; // 38
    EMeshParticleOrientationMode orientationMode; // 48
    bool useBatchedRender; // 4C
    uint8_t unk4D[0x50 - 0x4D]; // 4D
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(CParticleDrawerMesh, 0x50);
RED4EXT_ASSERT_OFFSET(CParticleDrawerMesh, meshes, 0x38);
RED4EXT_ASSERT_OFFSET(CParticleDrawerMesh, orientationMode, 0x48);
RED4EXT_ASSERT_OFFSET(CParticleDrawerMesh, useBatchedRender, 0x4C);
#else
RED4EXT_ASSERT_SIZE(CParticleDrawerMesh, 0x50);
#endif
} // namespace RED4ext

// clang-format on
