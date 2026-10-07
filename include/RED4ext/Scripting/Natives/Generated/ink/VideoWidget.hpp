#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/CName.hpp>
#include <RED4ext/NativeTypes.hpp>
#include <RED4ext/Scripting/Natives/Generated/ink/LeafWidget.hpp>

namespace RED4ext
{
struct Bink;

namespace ink
{
struct __declspec(align(0x10)) VideoWidget : ink::LeafWidget
{
    static constexpr const char* NAME = "inkVideoWidget";
    static constexpr const char* ALIAS = "inkVideo";

#ifdef __APPLE__
    uint8_t unk1FE[0x230 - 0x1FE]; // 1FE
    RaRef<Bink> videoResource; // 230
    uint8_t unk238[0x258 - 0x238]; // 238
    CName overriddenPlayerName; // 258
    uint8_t unk260[0x268 - 0x260]; // 260
    bool isParallaxEnabled; // 268
    uint8_t unk269[0x26A - 0x269]; // 269
    bool loop; // 26A
    uint8_t unk26B[0x272 - 0x26B]; // 26B
    bool prefetchVideo; // 272
    uint8_t unk273[0x2A0 - 0x273]; // 273
#else
    uint8_t unk200[0x238 - 0x200]; // 200
    RaRef<Bink> videoResource; // 238
    uint8_t unk240[0x260 - 0x240]; // 240
    CName overriddenPlayerName; // 260
    uint8_t unk268[0x270 - 0x268]; // 268
    bool isParallaxEnabled; // 270
    uint8_t unk271[0x272 - 0x271]; // 271
    bool loop; // 272
    uint8_t unk273[0x27A - 0x273]; // 273
    bool prefetchVideo; // 27A
    uint8_t unk27B[0x2B0 - 0x27B]; // 27B
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(VideoWidget, 0x2A0);
RED4EXT_ASSERT_OFFSET(VideoWidget, videoResource, 0x230);
RED4EXT_ASSERT_OFFSET(VideoWidget, overriddenPlayerName, 0x258);
RED4EXT_ASSERT_OFFSET(VideoWidget, isParallaxEnabled, 0x268);
RED4EXT_ASSERT_OFFSET(VideoWidget, loop, 0x26A);
RED4EXT_ASSERT_OFFSET(VideoWidget, prefetchVideo, 0x272);
#else
RED4EXT_ASSERT_SIZE(VideoWidget, 0x2B0);
#endif
} // namespace ink
using inkVideoWidget = ink::VideoWidget;
using inkVideo = ink::VideoWidget;
} // namespace RED4ext

// clang-format on
