#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/Scripting/Natives/Generated/Sample_Replicated_Root_Object.hpp>

namespace RED4ext
{
struct Sample_Customized_Replicated_Root_Object : Sample_Replicated_Root_Object
{
    static constexpr const char* NAME = "Sample_Customized_Replicated_Root_Object";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    bool bool2; // 11
    uint8_t unk12[0x18 - 0x12]; // 12
#else
    bool bool2; // 18
    uint8_t unk19[0x20 - 0x19]; // 19
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(Sample_Customized_Replicated_Root_Object, 0x18);
RED4EXT_ASSERT_OFFSET(Sample_Customized_Replicated_Root_Object, bool2, 0x11);
#else
RED4EXT_ASSERT_SIZE(Sample_Customized_Replicated_Root_Object, 0x20);
#endif
} // namespace RED4ext

// clang-format on
