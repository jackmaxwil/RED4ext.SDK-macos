#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/Scripting/Natives/Generated/ICameraStorageCustomData.hpp>

namespace RED4ext
{
struct FSR3CustomData : ICameraStorageCustomData
{
    static constexpr const char* NAME = "FSR3CustomData";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    uint8_t unk18[0x2D8 - 0x18]; // 18
#else
    uint8_t unk18[0x30 - 0x18]; // 18
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(FSR3CustomData, 0x2D8);
#else
RED4EXT_ASSERT_SIZE(FSR3CustomData, 0x30);
#endif
} // namespace RED4ext

// clang-format on
