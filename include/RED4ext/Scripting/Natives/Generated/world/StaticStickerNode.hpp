#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/DynArray.hpp>
#include <RED4ext/NativeTypes.hpp>
#include <RED4ext/Scripting/Natives/Generated/Color.hpp>
#include <RED4ext/Scripting/Natives/Generated/world/Node.hpp>

namespace RED4ext
{
struct CBitmapTexture;

namespace world
{
struct StaticStickerNode : world::Node
{
    static constexpr const char* NAME = "worldStaticStickerNode";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    uint8_t unk32[0x38 - 0x32]; // 32
    DynArray<CString> labels; // 38
    DynArray<RaRef<CBitmapTexture>> sprites; // 48
    uint8_t unk58[0x78 - 0x58]; // 58
    Color textColor; // 78
    Color backgroundColor; // 7C
    int32_t spriteSize; // 80
    float scale; // 84
    float visibilityDistance; // 88
    bool showBackground; // 8C
    bool alignSpritesHorizontally; // 8D
    uint8_t unk8E[0x90 - 0x8E]; // 8E
#else
    DynArray<CString> labels; // 38
    DynArray<RaRef<CBitmapTexture>> sprites; // 48
    uint8_t unk58[0x78 - 0x58]; // 58
    Color textColor; // 78
    Color backgroundColor; // 7C
    int32_t spriteSize; // 80
    float scale; // 84
    float visibilityDistance; // 88
    bool showBackground; // 8C
    bool alignSpritesHorizontally; // 8D
    uint8_t unk8E[0x90 - 0x8E]; // 8E
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(StaticStickerNode, 0x90);
RED4EXT_ASSERT_OFFSET(StaticStickerNode, labels, 0x38);
RED4EXT_ASSERT_OFFSET(StaticStickerNode, sprites, 0x48);
RED4EXT_ASSERT_OFFSET(StaticStickerNode, textColor, 0x78);
RED4EXT_ASSERT_OFFSET(StaticStickerNode, backgroundColor, 0x7C);
RED4EXT_ASSERT_OFFSET(StaticStickerNode, spriteSize, 0x80);
RED4EXT_ASSERT_OFFSET(StaticStickerNode, scale, 0x84);
RED4EXT_ASSERT_OFFSET(StaticStickerNode, visibilityDistance, 0x88);
RED4EXT_ASSERT_OFFSET(StaticStickerNode, showBackground, 0x8C);
RED4EXT_ASSERT_OFFSET(StaticStickerNode, alignSpritesHorizontally, 0x8D);
#else
RED4EXT_ASSERT_SIZE(StaticStickerNode, 0x90);
#endif
} // namespace world
using worldStaticStickerNode = world::StaticStickerNode;
} // namespace RED4ext

// clang-format on
