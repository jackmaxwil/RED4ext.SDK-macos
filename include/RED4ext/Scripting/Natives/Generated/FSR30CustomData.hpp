#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/Scripting/Natives/Generated/ICameraStorageCustomData.hpp>

namespace RED4ext
{
struct FSR30CustomData : ICameraStorageCustomData
{
    static constexpr const char* NAME = "FSR30CustomData";
    static constexpr const char* ALIAS = NAME;

    uint8_t unk18[0x30 - 0x18]; // 18
};
#ifdef __APPLE__
// FSR30CustomData is not in the macOS RTTI dump: no macOS layout to assert
#else
RED4EXT_ASSERT_SIZE(FSR30CustomData, 0x30);
#endif
} // namespace RED4ext

// clang-format on
