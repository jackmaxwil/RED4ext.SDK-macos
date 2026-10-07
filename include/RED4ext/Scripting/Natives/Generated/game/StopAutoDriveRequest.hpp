#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/NativeTypes.hpp>
#include <RED4ext/Scripting/Natives/Generated/game/ScriptableSystemRequest.hpp>

namespace RED4ext
{
namespace game
{
struct StopAutoDriveRequest : game::ScriptableSystemRequest
{
    static constexpr const char* NAME = "gameStopAutoDriveRequest";
    static constexpr const char* ALIAS = "StopAutoDriveRequest";

#ifdef __APPLE__
    uint8_t unk45[0x48 - 0x45]; // 45
    CString locKey; // 48
    bool isDelamain; // 68
    uint8_t unk69[0x70 - 0x69]; // 69
#else
    CString locKey; // 48
    bool isDelamain; // 68
    uint8_t unk69[0x70 - 0x69]; // 69
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(StopAutoDriveRequest, 0x70);
RED4EXT_ASSERT_OFFSET(StopAutoDriveRequest, locKey, 0x48);
RED4EXT_ASSERT_OFFSET(StopAutoDriveRequest, isDelamain, 0x68);
#else
RED4EXT_ASSERT_SIZE(StopAutoDriveRequest, 0x70);
#endif
} // namespace game
using gameStopAutoDriveRequest = game::StopAutoDriveRequest;
using StopAutoDriveRequest = game::StopAutoDriveRequest;
} // namespace RED4ext

// clang-format on
