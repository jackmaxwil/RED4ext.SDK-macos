#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/Handle.hpp>
#include <RED4ext/Scripting/Natives/Generated/ent/SkinnedMeshComponent.hpp>
#include <RED4ext/Scripting/Natives/Generated/physics/FilterDataSource.hpp>
#include <RED4ext/Scripting/Natives/Generated/physics/SimulationType.hpp>

namespace RED4ext
{
namespace physics { struct FilterData; }

namespace ent
{
struct __declspec(align(0x10)) PhysicalSkinnedMeshComponent : ent::SkinnedMeshComponent
{
    static constexpr const char* NAME = "entPhysicalSkinnedMeshComponent";
    static constexpr const char* ALIAS = "PhysicalSkinnedMeshComponent";

#ifdef __APPLE__
    uint8_t unk268[0x2A0 - 0x268]; // 268
    Handle<physics::FilterData> filterData; // 2A0
    uint8_t unk2B0[0x2BC - 0x2B0]; // 2B0
    physics::SimulationType simulationType; // 2BC
    physics::FilterDataSource filterDataSource; // 2BD
    bool startInactive; // 2BE
    uint8_t unk2BF[0x2C0 - 0x2BF]; // 2BF
    bool useResourceSimulationType; // 2C0
    uint8_t unk2C1[0x2D0 - 0x2C1]; // 2C1
#else
    uint8_t unk270[0x2A8 - 0x270]; // 270
    Handle<physics::FilterData> filterData; // 2A8
    uint8_t unk2B8[0x2C4 - 0x2B8]; // 2B8
    physics::SimulationType simulationType; // 2C4
    physics::FilterDataSource filterDataSource; // 2C5
    bool startInactive; // 2C6
    uint8_t unk2C7[0x2C8 - 0x2C7]; // 2C7
    bool useResourceSimulationType; // 2C8
    uint8_t unk2C9[0x2D0 - 0x2C9]; // 2C9
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(PhysicalSkinnedMeshComponent, 0x2D0);
RED4EXT_ASSERT_OFFSET(PhysicalSkinnedMeshComponent, filterData, 0x2A0);
RED4EXT_ASSERT_OFFSET(PhysicalSkinnedMeshComponent, simulationType, 0x2BC);
RED4EXT_ASSERT_OFFSET(PhysicalSkinnedMeshComponent, filterDataSource, 0x2BD);
RED4EXT_ASSERT_OFFSET(PhysicalSkinnedMeshComponent, startInactive, 0x2BE);
RED4EXT_ASSERT_OFFSET(PhysicalSkinnedMeshComponent, useResourceSimulationType, 0x2C0);
#else
RED4EXT_ASSERT_SIZE(PhysicalSkinnedMeshComponent, 0x2D0);
#endif
} // namespace ent
using entPhysicalSkinnedMeshComponent = ent::PhysicalSkinnedMeshComponent;
using PhysicalSkinnedMeshComponent = ent::PhysicalSkinnedMeshComponent;
} // namespace RED4ext

// clang-format on
