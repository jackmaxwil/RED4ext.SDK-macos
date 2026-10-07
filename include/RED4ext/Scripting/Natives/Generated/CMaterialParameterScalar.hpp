#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/Scripting/Natives/Generated/CMaterialParameter.hpp>

namespace RED4ext
{
struct CMaterialParameterScalar : CMaterialParameter
{
    static constexpr const char* NAME = "CMaterialParameterScalar";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    float scalar; // 3C
    float min; // 40
    float max; // 44
#else
    float scalar; // 40
    float min; // 44
    float max; // 48
    uint8_t unk4C[0x50 - 0x4C]; // 4C
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(CMaterialParameterScalar, 0x48);
RED4EXT_ASSERT_OFFSET(CMaterialParameterScalar, scalar, 0x3C);
RED4EXT_ASSERT_OFFSET(CMaterialParameterScalar, min, 0x40);
RED4EXT_ASSERT_OFFSET(CMaterialParameterScalar, max, 0x44);
#else
RED4EXT_ASSERT_SIZE(CMaterialParameterScalar, 0x50);
#endif
} // namespace RED4ext

// clang-format on
