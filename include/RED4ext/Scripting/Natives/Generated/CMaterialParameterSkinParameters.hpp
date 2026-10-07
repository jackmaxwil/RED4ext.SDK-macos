#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/NativeTypes.hpp>
#include <RED4ext/Scripting/Natives/Generated/CMaterialParameter.hpp>

namespace RED4ext
{
struct CSkinProfile;

struct CMaterialParameterSkinParameters : CMaterialParameter
{
    static constexpr const char* NAME = "CMaterialParameterSkinParameters";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    uint8_t unk3C[0x40 - 0x3C]; // 3C
    Ref<CSkinProfile> skinProfile; // 40
#else
    Ref<CSkinProfile> skinProfile; // 40
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(CMaterialParameterSkinParameters, 0x58);
RED4EXT_ASSERT_OFFSET(CMaterialParameterSkinParameters, skinProfile, 0x40);
#else
RED4EXT_ASSERT_SIZE(CMaterialParameterSkinParameters, 0x58);
#endif
} // namespace RED4ext

// clang-format on
