#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/CName.hpp>
#include <RED4ext/DynArray.hpp>
#include <RED4ext/NativeTypes.hpp>
#include <RED4ext/Scripting/Natives/Generated/physics/ICollider.hpp>

namespace RED4ext
{
namespace physics
{
struct __declspec(align(0x10)) ColliderMesh : physics::ICollider
{
    static constexpr const char* NAME = "physicsColliderMesh";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    uint8_t unk88[0xB8 - 0x88]; // 88
    DynArray<CName> faceMaterials; // B8
    DataBuffer compiledGeometryBuffer; // C8
    uint8_t unkF0[0x100 - 0xF0]; // F0
#else
    uint8_t unk90[0xC0 - 0x90]; // 90
    DynArray<CName> faceMaterials; // C0
    DataBuffer compiledGeometryBuffer; // D0
    uint8_t unkF8[0x110 - 0xF8]; // F8
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(ColliderMesh, 0x100);
RED4EXT_ASSERT_OFFSET(ColliderMesh, faceMaterials, 0xB8);
RED4EXT_ASSERT_OFFSET(ColliderMesh, compiledGeometryBuffer, 0xC8);
#else
RED4EXT_ASSERT_SIZE(ColliderMesh, 0x110);
#endif
} // namespace physics
using physicsColliderMesh = physics::ColliderMesh;
} // namespace RED4ext

// clang-format on
