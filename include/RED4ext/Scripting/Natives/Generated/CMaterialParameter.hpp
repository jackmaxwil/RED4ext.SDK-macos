#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/CName.hpp>
#include <RED4ext/ISerializable.hpp>

namespace RED4ext
{
struct CMaterialParameter : ISerializable
{
    static constexpr const char* NAME = "CMaterialParameter";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    CName parameterName; // 30
    uint32_t register_; // 38 -- register
#else
    CName parameterName; // 30
    uint32_t register_; // 38 -- register
    uint8_t unk3C[0x40 - 0x3C]; // 3C
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(CMaterialParameter, 0x40);
RED4EXT_ASSERT_OFFSET(CMaterialParameter, parameterName, 0x30);
RED4EXT_ASSERT_OFFSET(CMaterialParameter, register_, 0x38);
#else
RED4EXT_ASSERT_SIZE(CMaterialParameter, 0x40);
#endif
} // namespace RED4ext

// clang-format on
