#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/Scripting/Natives/Generated/CResource.hpp>

namespace RED4ext
{
struct TweakDBResource : CResource
{
    static constexpr const char* NAME = "TweakDBResource";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    uint8_t unk39[0x60 - 0x39]; // 39
#else
    uint8_t unk40[0x60 - 0x40]; // 40
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(TweakDBResource, 0x60);
#else
RED4EXT_ASSERT_SIZE(TweakDBResource, 0x60);
#endif
} // namespace RED4ext

// clang-format on
