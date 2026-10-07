#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/Scripting/Natives/Generated/world/IRuntimeSystem.hpp>

namespace RED4ext
{
namespace world
{
struct RuntimeSystemTransformAnimator : world::IRuntimeSystem
{
    static constexpr const char* NAME = "worldRuntimeSystemTransformAnimator";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    uint8_t unk48[0xF8 - 0x48]; // 48
#else
    uint8_t unk48[0x100 - 0x48]; // 48
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(RuntimeSystemTransformAnimator, 0xF8);
#else
RED4EXT_ASSERT_SIZE(RuntimeSystemTransformAnimator, 0x100);
#endif
} // namespace world
using worldRuntimeSystemTransformAnimator = world::RuntimeSystemTransformAnimator;
} // namespace RED4ext

// clang-format on
