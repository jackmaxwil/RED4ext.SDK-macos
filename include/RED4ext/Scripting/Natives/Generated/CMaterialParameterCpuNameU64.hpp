#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/CName.hpp>
#include <RED4ext/Scripting/Natives/Generated/CMaterialParameter.hpp>

namespace RED4ext
{
struct CMaterialParameterCpuNameU64 : CMaterialParameter
{
    static constexpr const char* NAME = "CMaterialParameterCpuNameU64";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    uint8_t unk3C[0x40 - 0x3C]; // 3C
    CName name; // 40
#else
    CName name; // 40
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(CMaterialParameterCpuNameU64, 0x48);
RED4EXT_ASSERT_OFFSET(CMaterialParameterCpuNameU64, name, 0x40);
#else
RED4EXT_ASSERT_SIZE(CMaterialParameterCpuNameU64, 0x48);
#endif
} // namespace RED4ext

// clang-format on
