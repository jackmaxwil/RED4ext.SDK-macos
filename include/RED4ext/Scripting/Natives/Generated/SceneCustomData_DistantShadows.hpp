#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/Scripting/Natives/Generated/SceneCustomData_DistantShadowsCommon.hpp>

namespace RED4ext
{
struct SceneCustomData_DistantShadows : SceneCustomData_DistantShadowsCommon
{
    static constexpr const char* NAME = "SceneCustomData_DistantShadows";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    uint8_t unkF00[0xE3CC0 - 0xF00]; // F00
#else
    uint8_t unk1000[0xE4200 - 0x1000]; // 1000
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(SceneCustomData_DistantShadows, 0xE3CC0);
#else
RED4EXT_ASSERT_SIZE(SceneCustomData_DistantShadows, 0xE4200);
#endif
} // namespace RED4ext

// clang-format on
