#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/Scripting/Natives/Generated/ent/LightComponent.hpp>

namespace RED4ext
{
namespace game
{
struct __declspec(align(0x10)) PhotomodeLightComponent : ent::LightComponent
{
    static constexpr const char* NAME = "gamePhotomodeLightComponent";
    static constexpr const char* ALIAS = "PhotomodeLightComponent";

#ifdef __APPLE__
    uint8_t unk1F8[0x260 - 0x1F8]; // 1F8
#else
    uint8_t unk200[0x270 - 0x200]; // 200
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(PhotomodeLightComponent, 0x260);
#else
RED4EXT_ASSERT_SIZE(PhotomodeLightComponent, 0x270);
#endif
} // namespace game
using gamePhotomodeLightComponent = game::PhotomodeLightComponent;
using PhotomodeLightComponent = game::PhotomodeLightComponent;
} // namespace RED4ext

// clang-format on
