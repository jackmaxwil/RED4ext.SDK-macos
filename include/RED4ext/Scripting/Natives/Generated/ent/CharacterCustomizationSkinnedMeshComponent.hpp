#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/Scripting/Natives/Generated/ent/SkinnedMeshComponent.hpp>
#include <RED4ext/Scripting/Natives/Generated/red/TagList.hpp>

namespace RED4ext
{
namespace ent
{
struct __declspec(align(0x10)) CharacterCustomizationSkinnedMeshComponent : ent::SkinnedMeshComponent
{
    static constexpr const char* NAME = "entCharacterCustomizationSkinnedMeshComponent";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    red::TagList tags; // 268
    uint8_t unk278[0x280 - 0x278]; // 278
#else
    red::TagList tags; // 270
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(CharacterCustomizationSkinnedMeshComponent, 0x280);
RED4EXT_ASSERT_OFFSET(CharacterCustomizationSkinnedMeshComponent, tags, 0x268);
#else
RED4EXT_ASSERT_SIZE(CharacterCustomizationSkinnedMeshComponent, 0x280);
#endif
} // namespace ent
using entCharacterCustomizationSkinnedMeshComponent = ent::CharacterCustomizationSkinnedMeshComponent;
} // namespace RED4ext

// clang-format on
