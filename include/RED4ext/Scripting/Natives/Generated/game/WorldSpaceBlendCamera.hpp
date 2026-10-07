#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/Scripting/Natives/Generated/ent/BaseCameraComponent.hpp>

namespace RED4ext
{
namespace game
{
struct __declspec(align(0x10)) WorldSpaceBlendCamera : ent::BaseCameraComponent
{
    static constexpr const char* NAME = "gameWorldSpaceBlendCamera";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    uint8_t unk1D8[0x250 - 0x1D8]; // 1D8
#else
    uint8_t unk1E0[0x250 - 0x1E0]; // 1E0
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(WorldSpaceBlendCamera, 0x250);
#else
RED4EXT_ASSERT_SIZE(WorldSpaceBlendCamera, 0x250);
#endif
} // namespace game
using gameWorldSpaceBlendCamera = game::WorldSpaceBlendCamera;
} // namespace RED4ext

// clang-format on
