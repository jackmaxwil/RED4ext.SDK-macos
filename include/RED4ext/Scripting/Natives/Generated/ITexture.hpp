#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/Scripting/Natives/Generated/CResource.hpp>

namespace RED4ext
{
struct ITexture : CResource
{
    static constexpr const char* NAME = "ITexture";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    uint8_t unk39[0x3C - 0x39]; // 39
#else
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(ITexture, 0x40);
#else
RED4EXT_ASSERT_SIZE(ITexture, 0x40);
#endif
} // namespace RED4ext

// clang-format on
