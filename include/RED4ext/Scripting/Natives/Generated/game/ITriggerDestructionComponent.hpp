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
struct ITriggerDestructionComponent : ent::IComponent
{
    static constexpr const char* NAME = "gameITriggerDestructionComponent";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    uint8_t unk8D[0x94 - 0x8D]; // 8D
    bool startActive; // 94
    uint8_t unk95[0x98 - 0x95]; // 95
#else
    uint8_t unk90[0x94 - 0x90]; // 90
    bool startActive; // 94
    uint8_t unk95[0x98 - 0x95]; // 95
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(ITriggerDestructionComponent, 0x98);
RED4EXT_ASSERT_OFFSET(ITriggerDestructionComponent, startActive, 0x94);
#else
RED4EXT_ASSERT_SIZE(ITriggerDestructionComponent, 0x98);
#endif
} // namespace game
using gameITriggerDestructionComponent = game::ITriggerDestructionComponent;
} // namespace RED4ext

// clang-format on
