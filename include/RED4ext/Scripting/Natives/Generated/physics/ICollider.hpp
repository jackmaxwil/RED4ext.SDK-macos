#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/CName.hpp>
#include <RED4ext/DynArray.hpp>
#include <RED4ext/Handle.hpp>
#include <RED4ext/ISerializable.hpp>
#include <RED4ext/Scripting/Natives/Generated/Transform.hpp>
#include <RED4ext/Scripting/Natives/Generated/physics/ApperanceMaterial.hpp>

namespace RED4ext
{
namespace physics { struct FilterData; }

namespace physics
{
struct __declspec(align(0x10)) ICollider : ISerializable
{
    static constexpr const char* NAME = "physicsICollider";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    Transform localToBody; // 30
    CName material; // 50
    DynArray<physics::ApperanceMaterial> materialApperanceOverrides; // 58
    CName tag; // 68
    Handle<physics::FilterData> filterData; // 70
    float volumeModifier; // 80
    bool isImported; // 84
    bool isQueryShapeOnly; // 85
    uint8_t unk86[0x88 - 0x86]; // 86
#else
    Transform localToBody; // 30
    CName material; // 50
    DynArray<physics::ApperanceMaterial> materialApperanceOverrides; // 58
    CName tag; // 68
    Handle<physics::FilterData> filterData; // 70
    float volumeModifier; // 80
    bool isImported; // 84
    bool isQueryShapeOnly; // 85
    uint8_t unk86[0x90 - 0x86]; // 86
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(ICollider, 0x90);
RED4EXT_ASSERT_OFFSET(ICollider, localToBody, 0x30);
RED4EXT_ASSERT_OFFSET(ICollider, material, 0x50);
RED4EXT_ASSERT_OFFSET(ICollider, materialApperanceOverrides, 0x58);
RED4EXT_ASSERT_OFFSET(ICollider, tag, 0x68);
RED4EXT_ASSERT_OFFSET(ICollider, filterData, 0x70);
RED4EXT_ASSERT_OFFSET(ICollider, volumeModifier, 0x80);
RED4EXT_ASSERT_OFFSET(ICollider, isImported, 0x84);
RED4EXT_ASSERT_OFFSET(ICollider, isQueryShapeOnly, 0x85);
#else
RED4EXT_ASSERT_SIZE(ICollider, 0x90);
#endif
} // namespace physics
using physicsICollider = physics::ICollider;
} // namespace RED4ext

// clang-format on
