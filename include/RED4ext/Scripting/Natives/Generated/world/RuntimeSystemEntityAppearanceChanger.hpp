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
struct RuntimeSystemEntityAppearanceChanger : world::IRuntimeSystem
{
    static constexpr const char* NAME = "worldRuntimeSystemEntityAppearanceChanger";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    uint8_t unk48[0xF0 - 0x48]; // 48
#else
    uint8_t unk48[0xF8 - 0x48]; // 48
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(RuntimeSystemEntityAppearanceChanger, 0xF0);
#else
RED4EXT_ASSERT_SIZE(RuntimeSystemEntityAppearanceChanger, 0xF8);
#endif
} // namespace world
using worldRuntimeSystemEntityAppearanceChanger = world::RuntimeSystemEntityAppearanceChanger;
} // namespace RED4ext

// clang-format on
