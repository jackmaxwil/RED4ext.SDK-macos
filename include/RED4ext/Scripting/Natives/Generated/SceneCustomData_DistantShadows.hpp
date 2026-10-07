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
    uint8_t unk3E0[0xC8D80 - 0x3E0]; // 3E0
#else
    uint8_t unk3E0[0xC8CC0 - 0x3E0]; // 3E0
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(SceneCustomData_DistantShadows, 0xC8D80);
#else
RED4EXT_ASSERT_SIZE(SceneCustomData_DistantShadows, 0xC8CC0);
#endif
} // namespace RED4ext

// clang-format on
