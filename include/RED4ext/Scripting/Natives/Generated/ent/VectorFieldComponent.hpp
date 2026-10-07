#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/Scripting/Natives/Generated/Vector3.hpp>
#include <RED4ext/Scripting/Natives/Generated/ent/IVisualComponent.hpp>

namespace RED4ext
{
namespace ent
{
struct __declspec(align(0x10)) VectorFieldComponent : ent::IVisualComponent
{
    static constexpr const char* NAME = "entVectorFieldComponent";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    Vector3 direction; // 13C
    uint8_t unk148[0x160 - 0x148]; // 148
#else
    Vector3 direction; // 140
    uint8_t unk14C[0x160 - 0x14C]; // 14C
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(VectorFieldComponent, 0x160);
RED4EXT_ASSERT_OFFSET(VectorFieldComponent, direction, 0x13C);
#else
RED4EXT_ASSERT_SIZE(VectorFieldComponent, 0x160);
#endif
} // namespace ent
using entVectorFieldComponent = ent::VectorFieldComponent;
} // namespace RED4ext

// clang-format on
