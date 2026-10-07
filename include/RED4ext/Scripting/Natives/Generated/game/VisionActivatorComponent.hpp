#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/Scripting/Natives/Generated/ent/IComponent.hpp>

namespace RED4ext
{
namespace game
{
struct VisionActivatorComponent : ent::IComponent
{
    static constexpr const char* NAME = "gameVisionActivatorComponent";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    uint8_t unk8D[0xB0 - 0x8D]; // 8D
#else
    uint8_t unk90[0xB0 - 0x90]; // 90
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(VisionActivatorComponent, 0xB0);
#else
RED4EXT_ASSERT_SIZE(VisionActivatorComponent, 0xB0);
#endif
} // namespace game
using gameVisionActivatorComponent = game::VisionActivatorComponent;
} // namespace RED4ext

// clang-format on
