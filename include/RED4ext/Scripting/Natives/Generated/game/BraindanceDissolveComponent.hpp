#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/Scripting/Natives/Generated/ent/IComponent.hpp>

namespace RED4ext
{
namespace game
{
struct BraindanceDissolveComponent : ent::IComponent
{
    static constexpr const char* NAME = "gameBraindanceDissolveComponent";
    static constexpr const char* ALIAS = "BraindanceDissolveComponent";

#ifdef __APPLE__
    uint8_t unk8D[0xC0 - 0x8D]; // 8D
    float dissolveRadius; // C0
    uint8_t unkC4[0xC8 - 0xC4]; // C4
#else
    uint8_t unk90[0xC0 - 0x90]; // 90
    float dissolveRadius; // C0
    uint8_t unkC4[0xC8 - 0xC4]; // C4
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(BraindanceDissolveComponent, 0xC8);
RED4EXT_ASSERT_OFFSET(BraindanceDissolveComponent, dissolveRadius, 0xC0);
#else
RED4EXT_ASSERT_SIZE(BraindanceDissolveComponent, 0xC8);
#endif
} // namespace game
using gameBraindanceDissolveComponent = game::BraindanceDissolveComponent;
using BraindanceDissolveComponent = game::BraindanceDissolveComponent;
} // namespace RED4ext

// clang-format on
