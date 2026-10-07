#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/DynArray.hpp>
#include <RED4ext/NativeTypes.hpp>
#include <RED4ext/Scripting/Natives/Generated/Vector3.hpp>
#include <RED4ext/Scripting/Natives/Generated/physics/ICollider.hpp>

namespace RED4ext
{
namespace physics
{
struct __declspec(align(0x10)) ColliderConvex : physics::ICollider
{
    static constexpr const char* NAME = "physicsColliderConvex";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    DynArray<Vector3> vertices; // 88
    DynArray<uint8_t> indexBuffer; // 98
    DynArray<uint16_t> polygonVertices; // A8
    DataBuffer compiledGeometryBuffer; // B8
    uint8_t unkE0[0xF0 - 0xE0]; // E0
#else
    DynArray<Vector3> vertices; // 90
    DynArray<uint8_t> indexBuffer; // A0
    DynArray<uint16_t> polygonVertices; // B0
    DataBuffer compiledGeometryBuffer; // C0
    uint8_t unkE8[0x100 - 0xE8]; // E8
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(ColliderConvex, 0xF0);
RED4EXT_ASSERT_OFFSET(ColliderConvex, vertices, 0x88);
RED4EXT_ASSERT_OFFSET(ColliderConvex, indexBuffer, 0x98);
RED4EXT_ASSERT_OFFSET(ColliderConvex, polygonVertices, 0xA8);
RED4EXT_ASSERT_OFFSET(ColliderConvex, compiledGeometryBuffer, 0xB8);
#else
RED4EXT_ASSERT_SIZE(ColliderConvex, 0x100);
#endif
} // namespace physics
using physicsColliderConvex = physics::ColliderConvex;
} // namespace RED4ext

// clang-format on
