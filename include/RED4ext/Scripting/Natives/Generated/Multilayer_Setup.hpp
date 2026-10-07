#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/DynArray.hpp>
#include <RED4ext/Scripting/Natives/Generated/CResource.hpp>
#include <RED4ext/Scripting/Natives/Generated/Multilayer_Layer.hpp>

namespace RED4ext
{
struct Multilayer_Setup : CResource
{
    static constexpr const char* NAME = "Multilayer_Setup";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    uint8_t unk39[0x40 - 0x39]; // 39
    DynArray<Multilayer_Layer> layers; // 40
    uint8_t unk50[0x70 - 0x50]; // 50
    float ratio; // 70
    bool useNormal; // 74
    uint8_t unk75[0x80 - 0x75]; // 75
#else
    DynArray<Multilayer_Layer> layers; // 40
    uint8_t unk50[0x70 - 0x50]; // 50
    float ratio; // 70
    bool useNormal; // 74
    uint8_t unk75[0x80 - 0x75]; // 75
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(Multilayer_Setup, 0x80);
RED4EXT_ASSERT_OFFSET(Multilayer_Setup, layers, 0x40);
RED4EXT_ASSERT_OFFSET(Multilayer_Setup, ratio, 0x70);
RED4EXT_ASSERT_OFFSET(Multilayer_Setup, useNormal, 0x74);
#else
RED4EXT_ASSERT_SIZE(Multilayer_Setup, 0x80);
#endif
} // namespace RED4ext

// clang-format on
