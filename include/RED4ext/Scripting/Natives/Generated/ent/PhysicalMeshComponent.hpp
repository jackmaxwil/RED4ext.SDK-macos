#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/CName.hpp>
#include <RED4ext/Handle.hpp>
#include <RED4ext/Scripting/Natives/Generated/ent/MeshComponent.hpp>
#include <RED4ext/Scripting/Natives/Generated/physics/FilterDataSource.hpp>
#include <RED4ext/Scripting/Natives/Generated/physics/SimulationType.hpp>

namespace RED4ext
{
namespace physics { struct FilterData; }

namespace ent
{
struct __declspec(align(0x10)) PhysicalMeshComponent : ent::MeshComponent
{
    static constexpr const char* NAME = "entPhysicalMeshComponent";
    static constexpr const char* ALIAS = "PhysicalMeshComponent";

#ifdef __APPLE__
    uint8_t unk1D8[0x200 - 0x1D8]; // 1D8
    Handle<physics::FilterData> filterData; // 200
    CName visibilityAnimationParam; // 210
    uint8_t unk218[0x220 - 0x218]; // 218
    physics::FilterDataSource filterDataSource; // 220
    physics::SimulationType simulationType; // 221
    bool startInactive; // 222
    bool useResourceSimulationType; // 223
    uint8_t unk224[0x230 - 0x224]; // 224
#else
    uint8_t unk1E0[0x210 - 0x1E0]; // 1E0
    Handle<physics::FilterData> filterData; // 210
    CName visibilityAnimationParam; // 220
    uint8_t unk228[0x230 - 0x228]; // 228
    physics::FilterDataSource filterDataSource; // 230
    physics::SimulationType simulationType; // 231
    bool startInactive; // 232
    bool useResourceSimulationType; // 233
    uint8_t unk234[0x240 - 0x234]; // 234
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(PhysicalMeshComponent, 0x230);
RED4EXT_ASSERT_OFFSET(PhysicalMeshComponent, filterData, 0x200);
RED4EXT_ASSERT_OFFSET(PhysicalMeshComponent, visibilityAnimationParam, 0x210);
RED4EXT_ASSERT_OFFSET(PhysicalMeshComponent, filterDataSource, 0x220);
RED4EXT_ASSERT_OFFSET(PhysicalMeshComponent, simulationType, 0x221);
RED4EXT_ASSERT_OFFSET(PhysicalMeshComponent, startInactive, 0x222);
RED4EXT_ASSERT_OFFSET(PhysicalMeshComponent, useResourceSimulationType, 0x223);
#else
RED4EXT_ASSERT_SIZE(PhysicalMeshComponent, 0x240);
#endif
} // namespace ent
using entPhysicalMeshComponent = ent::PhysicalMeshComponent;
using PhysicalMeshComponent = ent::PhysicalMeshComponent;
} // namespace RED4ext

// clang-format on
