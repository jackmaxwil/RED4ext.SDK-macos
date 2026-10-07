#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>

namespace RED4ext
{
struct ScriptReentrantRWLock
{
    static constexpr const char* NAME = "ScriptReentrantRWLock";
    static constexpr const char* ALIAS = "RWLock";

#ifdef __APPLE__
    uint8_t unk00[0xD0 - 0x0]; // 0
#else
    uint8_t unk00[0x10 - 0x0]; // 0
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(ScriptReentrantRWLock, 0xD0);
#else
RED4EXT_ASSERT_SIZE(ScriptReentrantRWLock, 0x10);
#endif
using RWLock = ScriptReentrantRWLock;
} // namespace RED4ext

// clang-format on
