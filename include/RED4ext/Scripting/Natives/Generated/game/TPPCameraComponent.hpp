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
struct __declspec(align(0x10)) TPPCameraComponent : game::CameraComponent
{
    static constexpr const char* NAME = "gameTPPCameraComponent";
    static constexpr const char* ALIAS = "TPPCameraComponent";

#ifdef __APPLE__
    uint8_t unk318[0x430 - 0x318]; // 318
#else
    uint8_t unk320[0x430 - 0x320]; // 320
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(TPPCameraComponent, 0x430);
#else
RED4EXT_ASSERT_SIZE(TPPCameraComponent, 0x430);
#endif
} // namespace game
using gameTPPCameraComponent = game::TPPCameraComponent;
using TPPCameraComponent = game::TPPCameraComponent;
} // namespace RED4ext

// clang-format on
