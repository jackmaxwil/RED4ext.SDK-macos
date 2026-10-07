#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>

namespace RED4ext
{
namespace game
{
struct __declspec(align(0x10)) SmartObjectVisualData
{
    static constexpr const char* NAME = "gameSmartObjectVisualData";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    uint8_t unk00[0x70 - 0x0]; // 0
#else
    uint8_t unk00[0x80 - 0x0]; // 0
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(SmartObjectVisualData, 0x70);
#else
RED4EXT_ASSERT_SIZE(SmartObjectVisualData, 0x80);
#endif
} // namespace game
using gameSmartObjectVisualData = game::SmartObjectVisualData;
} // namespace RED4ext

// clang-format on
