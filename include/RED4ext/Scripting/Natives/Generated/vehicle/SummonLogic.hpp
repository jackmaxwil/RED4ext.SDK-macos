#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>

namespace RED4ext
{
namespace vehicle
{
struct SummonLogic
{
    static constexpr const char* NAME = "vehicleSummonLogic";
    static constexpr const char* ALIAS = "SummonLogic";

#ifdef __APPLE__
    uint8_t unk00[0x180 - 0x0]; // 0
#else
    uint8_t unk00[0x1A0 - 0x0]; // 0
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(SummonLogic, 0x180);
#else
RED4EXT_ASSERT_SIZE(SummonLogic, 0x1A0);
#endif
} // namespace vehicle
using vehicleSummonLogic = vehicle::SummonLogic;
using SummonLogic = vehicle::SummonLogic;
} // namespace RED4ext

// clang-format on
