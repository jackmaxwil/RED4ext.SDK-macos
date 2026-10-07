#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/DynArray.hpp>
#include <RED4ext/NativeTypes.hpp>
#include <RED4ext/Scripting/Natives/Generated/game/data/ValueDataNode.hpp>

namespace RED4ext
{
namespace game::data
{
struct ComplexValueNode : game::data::ValueDataNode
{
    static constexpr const char* NAME = "gamedataComplexValueNode";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    uint8_t unk94[0x98 - 0x94]; // 94
    DynArray<CString> data; // 98
#else
    DynArray<CString> data; // 98
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(ComplexValueNode, 0xA8);
RED4EXT_ASSERT_OFFSET(ComplexValueNode, data, 0x98);
#else
RED4EXT_ASSERT_SIZE(ComplexValueNode, 0xA8);
#endif
} // namespace game::data
using gamedataComplexValueNode = game::data::ComplexValueNode;
} // namespace RED4ext

// clang-format on
