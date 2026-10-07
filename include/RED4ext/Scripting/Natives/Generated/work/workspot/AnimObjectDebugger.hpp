#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/Scripting/Natives/Generated/work/DebuggingTool.hpp>

namespace RED4ext
{
namespace work::workspot
{
struct AnimObjectDebugger : work::DebuggingTool
{
    static constexpr const char* NAME = "workworkspotAnimObjectDebugger";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    uint8_t unk18[0x48 - 0x18]; // 18
#else
    uint8_t unk18[0x50 - 0x18]; // 18
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(AnimObjectDebugger, 0x48);
#else
RED4EXT_ASSERT_SIZE(AnimObjectDebugger, 0x50);
#endif
} // namespace work::workspot
using workworkspotAnimObjectDebugger = work::workspot::AnimObjectDebugger;
} // namespace RED4ext

// clang-format on
