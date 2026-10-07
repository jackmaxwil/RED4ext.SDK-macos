#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/Scripting/Natives/Generated/work/IWorkspotCondition.hpp>

namespace RED4ext
{
namespace work
{
struct CoverTypeCondition : work::IWorkspotCondition
{
    static constexpr const char* NAME = "workCoverTypeCondition";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    bool isHighCover; // 35
    uint8_t unk36[0x38 - 0x36]; // 36
#else
    bool isHighCover; // 38
    uint8_t unk39[0x40 - 0x39]; // 39
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(CoverTypeCondition, 0x38);
RED4EXT_ASSERT_OFFSET(CoverTypeCondition, isHighCover, 0x35);
#else
RED4EXT_ASSERT_SIZE(CoverTypeCondition, 0x40);
#endif
} // namespace work
using workCoverTypeCondition = work::CoverTypeCondition;
} // namespace RED4ext

// clang-format on
