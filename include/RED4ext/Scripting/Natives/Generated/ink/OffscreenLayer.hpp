#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/Scripting/Natives/Generated/ink/Layer.hpp>

namespace RED4ext
{
namespace ink
{
struct OffscreenLayer : ink::Layer
{
    static constexpr const char* NAME = "inkOffscreenLayer";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    uint8_t unk150[0x170 - 0x150]; // 150
#else
    uint8_t unk150[0x178 - 0x150]; // 150
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(OffscreenLayer, 0x170);
#else
RED4EXT_ASSERT_SIZE(OffscreenLayer, 0x178);
#endif
} // namespace ink
using inkOffscreenLayer = ink::OffscreenLayer;
} // namespace RED4ext

// clang-format on
