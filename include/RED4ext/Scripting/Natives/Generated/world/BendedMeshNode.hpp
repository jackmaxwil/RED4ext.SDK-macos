#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/CName.hpp>
#include <RED4ext/Containers/DynArray.hpp>
#include <RED4ext/NativeTypes.hpp>
#include <RED4ext/Scripting/Natives/Generated/Box.hpp>
#include <RED4ext/Scripting/Natives/Generated/Matrix.hpp>
#include <RED4ext/Scripting/Natives/Generated/NavGenNavigationSetting.hpp>
#include <RED4ext/Scripting/Natives/Generated/shadows/ShadowCastingMode.hpp>
#include <RED4ext/Scripting/Natives/Generated/world/Node.hpp>

namespace RED4ext
{
struct CMesh;

namespace world
{
struct __declspec(align(0x10)) BendedMeshNode : world::Node
{
    static constexpr const char* NAME = "worldBendedMeshNode";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    uint8_t unk32[0x38 - 0x32]; // 32
    RaRef<CMesh> mesh; // 38
    DynArray<Matrix> deformationData; // 40
    Box deformedBox; // 50
    bool isBendedRoad; // 70
    shadows::ShadowCastingMode castShadows; // 71
    shadows::ShadowCastingMode castLocalShadows; // 72
    uint8_t unk73[0x78 - 0x73]; // 73
    CName meshAppearance; // 78
    uint8_t unk80[0x98 - 0x80]; // 80
    NavGenNavigationSetting navigationSetting; // 98
    bool removeFromRainMap; // 9A
    uint8_t version; // 9B
    uint8_t unk9C[0xA0 - 0x9C]; // 9C
#else
    RaRef<CMesh> mesh; // 38
    DynArray<Matrix> deformationData; // 40
    Box deformedBox; // 50
    bool isBendedRoad; // 70
    shadows::ShadowCastingMode castShadows; // 71
    shadows::ShadowCastingMode castLocalShadows; // 72
    uint8_t unk73[0x78 - 0x73]; // 73
    CName meshAppearance; // 78
    uint8_t unk80[0x98 - 0x80]; // 80
    NavGenNavigationSetting navigationSetting; // 98
    bool removeFromRainMap; // 9A
    uint8_t version; // 9B
    uint8_t unk9C[0xA0 - 0x9C]; // 9C
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(BendedMeshNode, 0xA0);
RED4EXT_ASSERT_OFFSET(BendedMeshNode, mesh, 0x38);
RED4EXT_ASSERT_OFFSET(BendedMeshNode, deformationData, 0x40);
RED4EXT_ASSERT_OFFSET(BendedMeshNode, deformedBox, 0x50);
RED4EXT_ASSERT_OFFSET(BendedMeshNode, isBendedRoad, 0x70);
RED4EXT_ASSERT_OFFSET(BendedMeshNode, castShadows, 0x71);
RED4EXT_ASSERT_OFFSET(BendedMeshNode, castLocalShadows, 0x72);
RED4EXT_ASSERT_OFFSET(BendedMeshNode, meshAppearance, 0x78);
RED4EXT_ASSERT_OFFSET(BendedMeshNode, navigationSetting, 0x98);
RED4EXT_ASSERT_OFFSET(BendedMeshNode, removeFromRainMap, 0x9A);
RED4EXT_ASSERT_OFFSET(BendedMeshNode, version, 0x9B);
#else
RED4EXT_ASSERT_SIZE(BendedMeshNode, 0xA0);
#endif
} // namespace world
using worldBendedMeshNode = world::BendedMeshNode;
} // namespace RED4ext

// clang-format on
