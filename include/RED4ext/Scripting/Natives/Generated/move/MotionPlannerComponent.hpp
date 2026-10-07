#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/Scripting/Natives/Generated/move/IMotionPlannerComponent.hpp>

namespace RED4ext
{
namespace move
{
struct MotionPlannerComponent : move::IMotionPlannerComponent
{
    static constexpr const char* NAME = "moveMotionPlannerComponent";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    uint8_t unk8D[0x1F0 - 0x8D]; // 8D
    bool snapToGround; // 1F0
    uint8_t unk1F1[0x1F8 - 0x1F1]; // 1F1
#else
    uint8_t unk90[0x1F0 - 0x90]; // 90
    bool snapToGround; // 1F0
    uint8_t unk1F1[0x1F8 - 0x1F1]; // 1F1
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(MotionPlannerComponent, 0x1F8);
RED4EXT_ASSERT_OFFSET(MotionPlannerComponent, snapToGround, 0x1F0);
#else
RED4EXT_ASSERT_SIZE(MotionPlannerComponent, 0x1F8);
#endif
} // namespace move
using moveMotionPlannerComponent = move::MotionPlannerComponent;
} // namespace RED4ext

// clang-format on
