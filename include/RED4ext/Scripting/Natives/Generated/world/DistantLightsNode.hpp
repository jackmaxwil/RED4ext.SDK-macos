#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/NativeTypes.hpp>
#include <RED4ext/Scripting/Natives/Generated/world/Node.hpp>

namespace RED4ext
{
struct CDistantLightsResource;

namespace world
{
struct DistantLightsNode : world::Node
{
    static constexpr const char* NAME = "worldDistantLightsNode";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    uint8_t unk32[0x38 - 0x32]; // 32
    RaRef<CDistantLightsResource> data; // 38
#else
    RaRef<CDistantLightsResource> data; // 38
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(DistantLightsNode, 0x40);
RED4EXT_ASSERT_OFFSET(DistantLightsNode, data, 0x38);
#else
RED4EXT_ASSERT_SIZE(DistantLightsNode, 0x40);
#endif
} // namespace world
using worldDistantLightsNode = world::DistantLightsNode;
} // namespace RED4ext

// clang-format on
