#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/DynArray.hpp>
#include <RED4ext/Scripting/Natives/Generated/quest/IUIManagerNodeType.hpp>
#include <RED4ext/Scripting/Natives/Generated/quest/ShowDialogIndicator_NodeTypeParams.hpp>

namespace RED4ext
{
namespace quest
{
struct ShowDialogIndicator_NodeType : quest::IUIManagerNodeType
{
    static constexpr const char* NAME = "questShowDialogIndicator_NodeType";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    uint8_t unk34[0x38 - 0x34]; // 34
    DynArray<quest::ShowDialogIndicator_NodeTypeParams> params; // 38
#else
    DynArray<quest::ShowDialogIndicator_NodeTypeParams> params; // 38
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(ShowDialogIndicator_NodeType, 0x48);
RED4EXT_ASSERT_OFFSET(ShowDialogIndicator_NodeType, params, 0x38);
#else
RED4EXT_ASSERT_SIZE(ShowDialogIndicator_NodeType, 0x48);
#endif
} // namespace quest
using questShowDialogIndicator_NodeType = quest::ShowDialogIndicator_NodeType;
} // namespace RED4ext

// clang-format on
