#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/Scripting/Natives/Generated/game/CameraComponent.hpp>

namespace RED4ext
{
namespace game
{
struct __declspec(align(0x10)) Screenshot360CameraComponent : game::CameraComponent
{
    static constexpr const char* NAME = "gameScreenshot360CameraComponent";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    uint8_t unk318[0x3C0 - 0x318]; // 318
#else
    uint8_t unk320[0x3D0 - 0x320]; // 320
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(Screenshot360CameraComponent, 0x3C0);
#else
RED4EXT_ASSERT_SIZE(Screenshot360CameraComponent, 0x3D0);
#endif
} // namespace game
using gameScreenshot360CameraComponent = game::Screenshot360CameraComponent;
} // namespace RED4ext

// clang-format on
