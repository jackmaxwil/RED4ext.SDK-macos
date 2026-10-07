#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/DynArray.hpp>
#include <RED4ext/Scripting/Natives/Generated/CResource.hpp>
#include <RED4ext/Scripting/Natives/Generated/CurveSetEntry.hpp>

namespace RED4ext
{
struct CurveSet : CResource
{
    static constexpr const char* NAME = "CurveSet";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    uint8_t unk39[0x40 - 0x39]; // 39
    DynArray<CurveSetEntry> curves; // 40
#else
    DynArray<CurveSetEntry> curves; // 40
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(CurveSet, 0x50);
RED4EXT_ASSERT_OFFSET(CurveSet, curves, 0x40);
#else
RED4EXT_ASSERT_SIZE(CurveSet, 0x50);
#endif
} // namespace RED4ext

// clang-format on
