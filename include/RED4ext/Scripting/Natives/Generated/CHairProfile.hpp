#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/Containers/DynArray.hpp>
#include <RED4ext/Scripting/Natives/Generated/CResource.hpp>
#include <RED4ext/Scripting/Natives/Generated/rend/GradientEntry.hpp>

namespace RED4ext
{
struct CHairProfile : CResource
{
    static constexpr const char* NAME = "CHairProfile";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    uint8_t unk39[0x3A - 0x39]; // 39
    uint16_t sampleCount; // 3A
    uint8_t unk3C[0x40 - 0x3C]; // 3C
    DynArray<rend::GradientEntry> gradientEntriesID; // 40
    DynArray<rend::GradientEntry> gradientEntriesRootToTip; // 50
    uint8_t unk60[0x70 - 0x60]; // 60
#else
    uint16_t sampleCount; // 40
    uint8_t unk42[0x48 - 0x42]; // 42
    DynArray<rend::GradientEntry> gradientEntriesID; // 48
    DynArray<rend::GradientEntry> gradientEntriesRootToTip; // 58
    uint8_t unk68[0x78 - 0x68]; // 68
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(CHairProfile, 0x70);
RED4EXT_ASSERT_OFFSET(CHairProfile, sampleCount, 0x3A);
RED4EXT_ASSERT_OFFSET(CHairProfile, gradientEntriesID, 0x40);
RED4EXT_ASSERT_OFFSET(CHairProfile, gradientEntriesRootToTip, 0x50);
#else
RED4EXT_ASSERT_SIZE(CHairProfile, 0x78);
#endif
} // namespace RED4ext

// clang-format on
