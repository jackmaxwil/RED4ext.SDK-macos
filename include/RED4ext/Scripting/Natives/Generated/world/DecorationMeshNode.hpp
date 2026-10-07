#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/Handle.hpp>
#include <RED4ext/Scripting/Natives/Generated/physics/FilterDataSource.hpp>
#include <RED4ext/Scripting/Natives/Generated/world/MeshNode.hpp>

namespace RED4ext
{
namespace physics { struct FilterData; }

namespace world
{
struct DecorationMeshNode : world::MeshNode
{
    static constexpr const char* NAME = "worldDecorationMeshNode";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    uint8_t unk5A[0x60 - 0x5A]; // 5A
    Handle<physics::FilterData> filterData; // 60
    physics::FilterDataSource filterDataSource; // 70
    bool startAsleep; // 71
    uint8_t unk72[0x78 - 0x72]; // 72
#else
    Handle<physics::FilterData> filterData; // 60
    physics::FilterDataSource filterDataSource; // 70
    bool startAsleep; // 71
    uint8_t unk72[0x78 - 0x72]; // 72
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(DecorationMeshNode, 0x78);
RED4EXT_ASSERT_OFFSET(DecorationMeshNode, filterData, 0x60);
RED4EXT_ASSERT_OFFSET(DecorationMeshNode, filterDataSource, 0x70);
RED4EXT_ASSERT_OFFSET(DecorationMeshNode, startAsleep, 0x71);
#else
RED4EXT_ASSERT_SIZE(DecorationMeshNode, 0x78);
#endif
} // namespace world
using worldDecorationMeshNode = world::DecorationMeshNode;
} // namespace RED4ext

// clang-format on
