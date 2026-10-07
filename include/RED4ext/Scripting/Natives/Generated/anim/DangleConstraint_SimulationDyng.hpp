#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/Handle.hpp>
#include <RED4ext/Scripting/Natives/Generated/anim/DangleConstraint_Simulation.hpp>
#include <RED4ext/Scripting/Natives/Generated/anim/DyngParticlesContainer.hpp>

namespace RED4ext
{
namespace anim { struct IDyngConstraint; }

namespace anim
{
struct DangleConstraint_SimulationDyng : anim::DangleConstraint_Simulation
{
    static constexpr const char* NAME = "animDangleConstraint_SimulationDyng";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    bool HACK_checkDangleTeleport; // 78
    uint8_t unk79[0x7C - 0x79]; // 79
    float substepTime; // 7C
    uint32_t solverIterations; // 80
    uint8_t unk84[0x88 - 0x84]; // 84
    anim::DyngParticlesContainer particlesContainer; // 88
    Handle<anim::IDyngConstraint> dyngConstraint; // 140
    uint8_t unk150[0x1C0 - 0x150]; // 150
#else
    bool HACK_checkDangleTeleport; // 78
    uint8_t unk79[0x7C - 0x79]; // 79
    float substepTime; // 7C
    uint32_t solverIterations; // 80
    uint8_t unk84[0x88 - 0x84]; // 84
    anim::DyngParticlesContainer particlesContainer; // 88
    Handle<anim::IDyngConstraint> dyngConstraint; // 148
    uint8_t unk158[0x1C8 - 0x158]; // 158
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(DangleConstraint_SimulationDyng, 0x1C0);
RED4EXT_ASSERT_OFFSET(DangleConstraint_SimulationDyng, HACK_checkDangleTeleport, 0x78);
RED4EXT_ASSERT_OFFSET(DangleConstraint_SimulationDyng, substepTime, 0x7C);
RED4EXT_ASSERT_OFFSET(DangleConstraint_SimulationDyng, solverIterations, 0x80);
RED4EXT_ASSERT_OFFSET(DangleConstraint_SimulationDyng, particlesContainer, 0x88);
RED4EXT_ASSERT_OFFSET(DangleConstraint_SimulationDyng, dyngConstraint, 0x140);
#else
RED4EXT_ASSERT_SIZE(DangleConstraint_SimulationDyng, 0x1C8);
#endif
} // namespace anim
using animDangleConstraint_SimulationDyng = anim::DangleConstraint_SimulationDyng;
} // namespace RED4ext

// clang-format on
