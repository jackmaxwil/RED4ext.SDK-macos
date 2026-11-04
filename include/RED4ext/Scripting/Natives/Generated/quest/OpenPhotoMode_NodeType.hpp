#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/NativeTypes.hpp>
#include <RED4ext/Scripting/Natives/Generated/quest/IUIManagerNodeType.hpp>

namespace RED4ext
{
namespace quest
{
struct OpenPhotoMode_NodeType : quest::IUIManagerNodeType
{
    static constexpr const char* NAME = "questOpenPhotoMode_NodeType";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    uint8_t unk34[0x38 - 0x34]; // 34
    CString factName; // 38
    bool forceFppMode; // 58
    bool alwaysAllowTPP; // 59
    bool lockExitUntilScreenshot; // 5A
    bool blockOutfitOption; // 5B
    uint8_t unk5C[0x60 - 0x5C]; // 5C
#else
    CString factName; // 38
    bool forceFppMode; // 58
    bool alwaysAllowTPP; // 59
    bool lockExitUntilScreenshot; // 5A
    bool blockOutfitOption; // 5B
    uint8_t unk5C[0x60 - 0x5C]; // 5C
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(OpenPhotoMode_NodeType, 0x60);
RED4EXT_ASSERT_OFFSET(OpenPhotoMode_NodeType, factName, 0x38);
RED4EXT_ASSERT_OFFSET(OpenPhotoMode_NodeType, forceFppMode, 0x58);
RED4EXT_ASSERT_OFFSET(OpenPhotoMode_NodeType, alwaysAllowTPP, 0x59);
RED4EXT_ASSERT_OFFSET(OpenPhotoMode_NodeType, lockExitUntilScreenshot, 0x5A);
RED4EXT_ASSERT_OFFSET(OpenPhotoMode_NodeType, blockOutfitOption, 0x5B);
#else
RED4EXT_ASSERT_SIZE(OpenPhotoMode_NodeType, 0x60);
#endif
} // namespace quest
using questOpenPhotoMode_NodeType = quest::OpenPhotoMode_NodeType;
} // namespace RED4ext

// clang-format on
