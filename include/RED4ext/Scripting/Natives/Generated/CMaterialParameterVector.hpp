#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/Scripting/Natives/Generated/CMaterialParameter.hpp>
#include <RED4ext/Scripting/Natives/Generated/Vector4.hpp>

namespace RED4ext
{
struct __declspec(align(0x10)) CMaterialParameterVector : CMaterialParameter
{
    static constexpr const char* NAME = "CMaterialParameterVector";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    uint8_t unk3C[0x40 - 0x3C]; // 3C
    Vector4 vector; // 40
#else
    Vector4 vector; // 40
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(CMaterialParameterVector, 0x50);
RED4EXT_ASSERT_OFFSET(CMaterialParameterVector, vector, 0x40);
#else
RED4EXT_ASSERT_SIZE(CMaterialParameterVector, 0x50);
#endif
} // namespace RED4ext

// clang-format on
