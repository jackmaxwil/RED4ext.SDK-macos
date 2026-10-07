#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/Handle.hpp>
#include <RED4ext/Scripting/Natives/Generated/AI/AIEvent.hpp>

namespace RED4ext
{
namespace game { struct MountEventData; }

namespace game
{
struct MountAIEvent : AI::AIEvent
{
    static constexpr const char* NAME = "gameMountAIEvent";
    static constexpr const char* ALIAS = "MountAIEvent";

#ifdef __APPLE__
    uint8_t unk4C[0x50 - 0x4C]; // 4C
    Handle<game::MountEventData> data; // 50
#else
    Handle<game::MountEventData> data; // 50
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(MountAIEvent, 0x60);
RED4EXT_ASSERT_OFFSET(MountAIEvent, data, 0x50);
#else
RED4EXT_ASSERT_SIZE(MountAIEvent, 0x60);
#endif
} // namespace game
using gameMountAIEvent = game::MountAIEvent;
using MountAIEvent = game::MountAIEvent;
} // namespace RED4ext

// clang-format on
