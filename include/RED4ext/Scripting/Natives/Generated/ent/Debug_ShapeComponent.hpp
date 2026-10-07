#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/Scripting/Natives/Generated/Color.hpp>
#include <RED4ext/Scripting/Natives/Generated/ent/Debug_ShapeType.hpp>
#include <RED4ext/Scripting/Natives/Generated/ent/IVisualComponent.hpp>

namespace RED4ext
{
namespace ent
{
struct __declspec(align(0x10)) Debug_ShapeComponent : ent::IVisualComponent
{
    static constexpr const char* NAME = "entDebug_ShapeComponent";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    ent::Debug_ShapeType shape; // 13C
    uint8_t unk13D[0x13E - 0x13D]; // 13D
    Color color; // 13E
    uint8_t unk142[0x144 - 0x142]; // 142
    float radius; // 144
    float halfHeight; // 148
    uint8_t unk14C[0x150 - 0x14C]; // 14C
#else
    ent::Debug_ShapeType shape; // 140
    uint8_t unk141[0x142 - 0x141]; // 141
    Color color; // 142
    uint8_t unk146[0x148 - 0x146]; // 146
    float radius; // 148
    float halfHeight; // 14C
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(Debug_ShapeComponent, 0x150);
RED4EXT_ASSERT_OFFSET(Debug_ShapeComponent, shape, 0x13C);
RED4EXT_ASSERT_OFFSET(Debug_ShapeComponent, color, 0x13E);
RED4EXT_ASSERT_OFFSET(Debug_ShapeComponent, radius, 0x144);
RED4EXT_ASSERT_OFFSET(Debug_ShapeComponent, halfHeight, 0x148);
#else
RED4EXT_ASSERT_SIZE(Debug_ShapeComponent, 0x150);
#endif
} // namespace ent
using entDebug_ShapeComponent = ent::Debug_ShapeComponent;
} // namespace RED4ext

// clang-format on
