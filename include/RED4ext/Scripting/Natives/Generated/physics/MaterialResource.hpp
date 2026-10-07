#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/Scripting/Natives/Generated/CResource.hpp>
#include <RED4ext/Scripting/Natives/Generated/Color.hpp>
#include <RED4ext/Scripting/Natives/Generated/physics/MaterialFriction.hpp>
#include <RED4ext/Scripting/Natives/Generated/physics/MaterialTags.hpp>

namespace RED4ext
{
namespace physics
{
struct MaterialResource : CResource
{
    static constexpr const char* NAME = "physicsMaterialResource";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    uint8_t unk39[0x48 - 0x39]; // 39
    uint64_t id; // 48
    Color color; // 50
    float staticFriction; // 54
    float dynamicFriction; // 58
    float restitution; // 5C
    float density; // 60
    physics::MaterialFriction frictionMode; // 64
    physics::MaterialTags tags; // 68
    uint8_t unk6D[0x70 - 0x6D]; // 6D
#else
    uint8_t unk40[0x48 - 0x40]; // 40
    uint64_t id; // 48
    Color color; // 50
    float staticFriction; // 54
    float dynamicFriction; // 58
    float restitution; // 5C
    float density; // 60
    physics::MaterialFriction frictionMode; // 64
    physics::MaterialTags tags; // 68
    uint8_t unk6D[0x70 - 0x6D]; // 6D
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(MaterialResource, 0x70);
RED4EXT_ASSERT_OFFSET(MaterialResource, id, 0x48);
RED4EXT_ASSERT_OFFSET(MaterialResource, color, 0x50);
RED4EXT_ASSERT_OFFSET(MaterialResource, staticFriction, 0x54);
RED4EXT_ASSERT_OFFSET(MaterialResource, dynamicFriction, 0x58);
RED4EXT_ASSERT_OFFSET(MaterialResource, restitution, 0x5C);
RED4EXT_ASSERT_OFFSET(MaterialResource, density, 0x60);
RED4EXT_ASSERT_OFFSET(MaterialResource, frictionMode, 0x64);
RED4EXT_ASSERT_OFFSET(MaterialResource, tags, 0x68);
#else
RED4EXT_ASSERT_SIZE(MaterialResource, 0x70);
#endif
} // namespace physics
using physicsMaterialResource = physics::MaterialResource;
} // namespace RED4ext

// clang-format on
