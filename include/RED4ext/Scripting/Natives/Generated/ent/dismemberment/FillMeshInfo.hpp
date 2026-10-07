#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/Scripting/Natives/Generated/ent/dismemberment/DangleInfo.hpp>
#include <RED4ext/Scripting/Natives/Generated/ent/dismemberment/MeshInfo.hpp>
#include <RED4ext/Scripting/Natives/Generated/ent/dismemberment/PlacementE.hpp>
#include <RED4ext/Scripting/Natives/Generated/ent/dismemberment/SimulationTypeE.hpp>

namespace RED4ext
{
namespace ent::dismemberment
{
struct __declspec(align(0x10)) FillMeshInfo : ent::dismemberment::MeshInfo
{
    static constexpr const char* NAME = "entdismembermentFillMeshInfo";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    ent::dismemberment::PlacementE Placement; // 68
    ent::dismemberment::SimulationTypeE Simulation; // 6A
    ent::dismemberment::DangleInfo Dangle; // 6C
#else
    ent::dismemberment::PlacementE Placement; // 80
    ent::dismemberment::SimulationTypeE Simulation; // 82
    ent::dismemberment::DangleInfo Dangle; // 84
    uint8_t unk98[0xA0 - 0x98]; // 98
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(FillMeshInfo, 0x80);
RED4EXT_ASSERT_OFFSET(FillMeshInfo, Placement, 0x68);
RED4EXT_ASSERT_OFFSET(FillMeshInfo, Simulation, 0x6A);
RED4EXT_ASSERT_OFFSET(FillMeshInfo, Dangle, 0x6C);
#else
RED4EXT_ASSERT_SIZE(FillMeshInfo, 0xA0);
#endif
} // namespace ent::dismemberment
using entdismembermentFillMeshInfo = ent::dismemberment::FillMeshInfo;
} // namespace RED4ext

// clang-format on
