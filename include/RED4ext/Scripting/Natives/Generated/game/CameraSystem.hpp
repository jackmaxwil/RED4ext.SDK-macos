#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/Scripting/Natives/Generated/game/ICameraSystem.hpp>

namespace RED4ext
{
namespace game
{
struct __declspec(align(0x10)) CameraSystem : game::ICameraSystem
{
    static constexpr const char* NAME = "gameCameraSystem";
    static constexpr const char* ALIAS = "CameraSystem";

#ifdef __APPLE__
    uint8_t unk48[0x740 - 0x48]; // 48
#else
    uint8_t unk48[0x780 - 0x48]; // 48
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(CameraSystem, 0x740);
#else
RED4EXT_ASSERT_SIZE(CameraSystem, 0x780);
#endif
} // namespace game
using gameCameraSystem = game::CameraSystem;
using CameraSystem = game::CameraSystem;
} // namespace RED4ext

// clang-format on
