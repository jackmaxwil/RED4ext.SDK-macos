#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/Scripting/Natives/Generated/input/InputSystemWin32Base.hpp>

namespace RED4ext
{
namespace input
{
struct InputSystemEditor : input::InputSystemWin32Base
{
    static constexpr const char* NAME = "inputInputSystemEditor";
    static constexpr const char* ALIAS = NAME;

    uint8_t unk190[0xE70 - 0x190]; // 190
};
#ifdef __APPLE__
// inputInputSystemEditor is not in the macOS RTTI dump: no macOS layout to assert
#else
RED4EXT_ASSERT_SIZE(InputSystemEditor, 0xE70);
#endif
} // namespace input
using inputInputSystemEditor = input::InputSystemEditor;
} // namespace RED4ext

// clang-format on
