#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/Scripting/Natives/Generated/ent/IVisualComponent.hpp>

namespace RED4ext
{
namespace ent
{
struct __declspec(align(0x10)) LightBlockingComponent : ent::IVisualComponent
{
    static constexpr const char* NAME = "entLightBlockingComponent";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    uint8_t unk13C[0x150 - 0x13C]; // 13C
    float radius; // 150
    uint8_t lightBlockerComponentVersion; // 154
    uint8_t unk155[0x160 - 0x155]; // 155
#else
    uint8_t unk140[0x150 - 0x140]; // 140
    float radius; // 150
    uint8_t lightBlockerComponentVersion; // 154
    uint8_t unk155[0x160 - 0x155]; // 155
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(LightBlockingComponent, 0x160);
RED4EXT_ASSERT_OFFSET(LightBlockingComponent, radius, 0x150);
RED4EXT_ASSERT_OFFSET(LightBlockingComponent, lightBlockerComponentVersion, 0x154);
#else
RED4EXT_ASSERT_SIZE(LightBlockingComponent, 0x160);
#endif
} // namespace ent
using entLightBlockingComponent = ent::LightBlockingComponent;
} // namespace RED4ext

// clang-format on
