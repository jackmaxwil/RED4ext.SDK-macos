#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/Scripting/IScriptable.hpp>

namespace RED4ext
{
namespace AI
{
struct DriveCommandUpdate : IScriptable
{
    static constexpr const char* NAME = "AIDriveCommandUpdate";
    static constexpr const char* ALIAS = "DriveCommandUpdate";

#ifdef __APPLE__
    float minSpeed; // 40
    float maxSpeed; // 44
    bool clearTrafficOnPath; // 48
    uint8_t unk49[0x4C - 0x49]; // 49
#else
    float minSpeed; // 40
    float maxSpeed; // 44
    bool clearTrafficOnPath; // 48
    uint8_t unk49[0x50 - 0x49]; // 49
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(DriveCommandUpdate, 0x50);
RED4EXT_ASSERT_OFFSET(DriveCommandUpdate, minSpeed, 0x40);
RED4EXT_ASSERT_OFFSET(DriveCommandUpdate, maxSpeed, 0x44);
RED4EXT_ASSERT_OFFSET(DriveCommandUpdate, clearTrafficOnPath, 0x48);
#else
RED4EXT_ASSERT_SIZE(DriveCommandUpdate, 0x50);
#endif
} // namespace AI
using AIDriveCommandUpdate = AI::DriveCommandUpdate;
using DriveCommandUpdate = AI::DriveCommandUpdate;
} // namespace RED4ext

// clang-format on
