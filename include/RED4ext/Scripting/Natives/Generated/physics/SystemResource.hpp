#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/DynArray.hpp>
#include <RED4ext/Handle.hpp>
#include <RED4ext/Scripting/Natives/Generated/CResource.hpp>

namespace RED4ext
{
namespace physics { struct SystemBody; }
namespace physics { struct SystemJoint; }

namespace physics
{
struct SystemResource : CResource
{
    static constexpr const char* NAME = "physicsSystemResource";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    uint8_t unk39[0x40 - 0x39]; // 39
    DynArray<Handle<physics::SystemBody>> bodies; // 40
    DynArray<Handle<physics::SystemJoint>> joints; // 50
#else
    DynArray<Handle<physics::SystemBody>> bodies; // 40
    DynArray<Handle<physics::SystemJoint>> joints; // 50
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(SystemResource, 0x60);
RED4EXT_ASSERT_OFFSET(SystemResource, bodies, 0x40);
RED4EXT_ASSERT_OFFSET(SystemResource, joints, 0x50);
#else
RED4EXT_ASSERT_SIZE(SystemResource, 0x60);
#endif
} // namespace physics
using physicsSystemResource = physics::SystemResource;
} // namespace RED4ext

// clang-format on
