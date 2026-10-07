#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>

namespace RED4ext
{
struct Sample_Replicated_Root_Object
{
    static constexpr const char* NAME = "Sample_Replicated_Root_Object";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    alignas(8) uint8_t unk00[0x10 - 0x0]; // 0
    bool bool_; // 10 -- bool
    ~Sample_Replicated_Root_Object() {} // non-POD, so clang reuses the tail padding like the game
#else
    uint8_t unk00[0x10 - 0x0]; // 0
    bool bool_; // 10 -- bool
    uint8_t unk11[0x18 - 0x11]; // 11
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(Sample_Replicated_Root_Object, 0x18);
RED4EXT_ASSERT_OFFSET(Sample_Replicated_Root_Object, bool_, 0x10);
#else
RED4EXT_ASSERT_SIZE(Sample_Replicated_Root_Object, 0x18);
#endif
} // namespace RED4ext

// clang-format on
