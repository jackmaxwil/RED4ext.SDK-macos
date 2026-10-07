#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/NativeTypes.hpp>
#include <RED4ext/Scripting/Natives/Generated/ent/IVisualComponent.hpp>

namespace RED4ext
{
struct CMesh;

namespace ent
{
struct __declspec(align(0x10)) ClothComponent : ent::IVisualComponent
{
    static constexpr const char* NAME = "entClothComponent";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    uint8_t unk13C[0x140 - 0x13C]; // 13C
    Ref<CMesh> mesh; // 140
    uint8_t unk158[0x160 - 0x158]; // 158
#else
    Ref<CMesh> mesh; // 140
    uint8_t unk158[0x160 - 0x158]; // 158
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(ClothComponent, 0x160);
RED4EXT_ASSERT_OFFSET(ClothComponent, mesh, 0x140);
#else
RED4EXT_ASSERT_SIZE(ClothComponent, 0x160);
#endif
} // namespace ent
using entClothComponent = ent::ClothComponent;
} // namespace RED4ext

// clang-format on
