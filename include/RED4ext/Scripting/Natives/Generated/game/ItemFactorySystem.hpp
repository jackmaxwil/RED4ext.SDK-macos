#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/Scripting/Natives/Generated/game/IItemFactorySystem.hpp>

namespace RED4ext
{
namespace game
{
struct __declspec(align(0x10)) ItemFactorySystem : game::IItemFactorySystem
{
    static constexpr const char* NAME = "gameItemFactorySystem";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    uint8_t unk48[0x60A0 - 0x48]; // 48
#else
    uint8_t unk48[0x9060 - 0x48]; // 48
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(ItemFactorySystem, 0x60A0);
#else
RED4EXT_ASSERT_SIZE(ItemFactorySystem, 0x9060);
#endif
} // namespace game
using gameItemFactorySystem = game::ItemFactorySystem;
} // namespace RED4ext

// clang-format on
