#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/Handle.hpp>
#include <RED4ext/Scripting/Natives/Generated/game/events/HitEvent.hpp>

namespace RED4ext
{
namespace game { struct Object; }

namespace game::events
{
struct __declspec(align(0x10)) CoverHitEvent : game::events::HitEvent
{
    static constexpr const char* NAME = "gameeventsCoverHitEvent";
    static constexpr const char* ALIAS = "gameCoverHitEvent";

#ifdef __APPLE__
    WeakHandle<game::Object> cover; // E8
    uint8_t unkF8[0x100 - 0xF8]; // F8
#else
    WeakHandle<game::Object> cover; // F0
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(CoverHitEvent, 0x100);
RED4EXT_ASSERT_OFFSET(CoverHitEvent, cover, 0xE8);
#else
RED4EXT_ASSERT_SIZE(CoverHitEvent, 0x100);
#endif
} // namespace game::events
using gameeventsCoverHitEvent = game::events::CoverHitEvent;
using gameCoverHitEvent = game::events::CoverHitEvent;
} // namespace RED4ext

// clang-format on
