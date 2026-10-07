#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/CName.hpp>
#include <RED4ext/Containers/DynArray.hpp>
#include <RED4ext/Scripting/Natives/Generated/AI/AIEvent.hpp>

namespace RED4ext
{
namespace AI
{
struct TaggedAIEvent : AI::AIEvent
{
    static constexpr const char* NAME = "AITaggedAIEvent";
    static constexpr const char* ALIAS = "TaggedAIEvent";

#ifdef __APPLE__
    uint8_t unk4C[0x50 - 0x4C]; // 4C
    DynArray<CName> tags; // 50
#else
    DynArray<CName> tags; // 50
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(TaggedAIEvent, 0x60);
RED4EXT_ASSERT_OFFSET(TaggedAIEvent, tags, 0x50);
#else
RED4EXT_ASSERT_SIZE(TaggedAIEvent, 0x60);
#endif
} // namespace AI
using AITaggedAIEvent = AI::TaggedAIEvent;
using TaggedAIEvent = AI::TaggedAIEvent;
} // namespace RED4ext

// clang-format on
