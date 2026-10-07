#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/NativeTypes.hpp>
#include <RED4ext/Scripting/Natives/Generated/Vector4.hpp>
#include <RED4ext/Scripting/Natives/Generated/world/Node.hpp>

namespace RED4ext
{
struct CBitmapTexture;

namespace world
{
struct __declspec(align(0x10)) DistantGINode : world::Node
{
    static constexpr const char* NAME = "worldDistantGINode";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    uint8_t unk32[0x38 - 0x32]; // 32
    RaRef<CBitmapTexture> dataAlbedo; // 38
    RaRef<CBitmapTexture> dataNormal; // 40
    RaRef<CBitmapTexture> dataHeight; // 48
    Vector4 sectorSpan; // 50
#else
    RaRef<CBitmapTexture> dataAlbedo; // 38
    RaRef<CBitmapTexture> dataNormal; // 40
    RaRef<CBitmapTexture> dataHeight; // 48
    Vector4 sectorSpan; // 50
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(DistantGINode, 0x60);
RED4EXT_ASSERT_OFFSET(DistantGINode, dataAlbedo, 0x38);
RED4EXT_ASSERT_OFFSET(DistantGINode, dataNormal, 0x40);
RED4EXT_ASSERT_OFFSET(DistantGINode, dataHeight, 0x48);
RED4EXT_ASSERT_OFFSET(DistantGINode, sectorSpan, 0x50);
#else
RED4EXT_ASSERT_SIZE(DistantGINode, 0x60);
#endif
} // namespace world
using worldDistantGINode = world::DistantGINode;
} // namespace RED4ext

// clang-format on
