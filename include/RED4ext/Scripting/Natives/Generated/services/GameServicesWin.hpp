#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/Scripting/Natives/Generated/services/GameServices.hpp>

namespace RED4ext
{
namespace services
{
struct GameServicesWin : services::GameServices
{
    static constexpr const char* NAME = "servicesGameServicesWin";
    static constexpr const char* ALIAS = NAME;

    uint8_t unk7D8[0x950 - 0x7D8]; // 7D8
};
#ifdef __APPLE__
// servicesGameServicesWin is not in the macOS RTTI dump: no macOS layout to assert
#else
RED4EXT_ASSERT_SIZE(GameServicesWin, 0x950);
#endif
} // namespace services
using servicesGameServicesWin = services::GameServicesWin;
} // namespace RED4ext

// clang-format on
