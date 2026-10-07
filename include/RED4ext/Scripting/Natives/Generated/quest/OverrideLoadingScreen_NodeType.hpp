#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/Containers/DynArray.hpp>
#include <RED4ext/NativeTypes.hpp>
#include <RED4ext/Scripting/Natives/Generated/quest/IUIManagerNodeType.hpp>

namespace RED4ext
{
struct Bink;

namespace quest
{
struct OverrideLoadingScreen_NodeType : quest::IUIManagerNodeType
{
    static constexpr const char* NAME = "questOverrideLoadingScreen_NodeType";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    uint8_t unk34[0x38 - 0x34]; // 34
    RaRef<Bink> video; // 38
    DynArray<RaRef<Bink>> videos; // 40
    DynArray<CString> tooltips; // 50
    float tooltipDuration; // 60
    bool forceVideoFrameRate; // 64
    uint8_t unk65[0x68 - 0x65]; // 65
    uint32_t minimumPlayCount; // 68
    bool keepLoadingScreenWhileVideoIsPlaying; // 6C
    uint8_t unk6D[0x70 - 0x6D]; // 6D
    float glitchEffectTime; // 70
    uint8_t unk74[0x78 - 0x74]; // 74
#else
    RaRef<Bink> video; // 38
    DynArray<RaRef<Bink>> videos; // 40
    DynArray<CString> tooltips; // 50
    float tooltipDuration; // 60
    bool forceVideoFrameRate; // 64
    uint8_t unk65[0x68 - 0x65]; // 65
    uint32_t minimumPlayCount; // 68
    bool keepLoadingScreenWhileVideoIsPlaying; // 6C
    uint8_t unk6D[0x70 - 0x6D]; // 6D
    float glitchEffectTime; // 70
    uint8_t unk74[0x78 - 0x74]; // 74
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(OverrideLoadingScreen_NodeType, 0x78);
RED4EXT_ASSERT_OFFSET(OverrideLoadingScreen_NodeType, video, 0x38);
RED4EXT_ASSERT_OFFSET(OverrideLoadingScreen_NodeType, videos, 0x40);
RED4EXT_ASSERT_OFFSET(OverrideLoadingScreen_NodeType, tooltips, 0x50);
RED4EXT_ASSERT_OFFSET(OverrideLoadingScreen_NodeType, tooltipDuration, 0x60);
RED4EXT_ASSERT_OFFSET(OverrideLoadingScreen_NodeType, forceVideoFrameRate, 0x64);
RED4EXT_ASSERT_OFFSET(OverrideLoadingScreen_NodeType, minimumPlayCount, 0x68);
RED4EXT_ASSERT_OFFSET(OverrideLoadingScreen_NodeType, keepLoadingScreenWhileVideoIsPlaying, 0x6C);
RED4EXT_ASSERT_OFFSET(OverrideLoadingScreen_NodeType, glitchEffectTime, 0x70);
#else
RED4EXT_ASSERT_SIZE(OverrideLoadingScreen_NodeType, 0x78);
#endif
} // namespace quest
using questOverrideLoadingScreen_NodeType = quest::OverrideLoadingScreen_NodeType;
} // namespace RED4ext

// clang-format on
