#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/Handle.hpp>
#include <RED4ext/Scripting/Natives/Generated/game/ScriptableSystemRequest.hpp>

namespace RED4ext
{
namespace game { struct Object; }

namespace game
{
struct TagObjectRequest : game::ScriptableSystemRequest
{
    static constexpr const char* NAME = "gameTagObjectRequest";
    static constexpr const char* ALIAS = "TagObjectRequest";

#ifdef __APPLE__
    uint8_t unk45[0x48 - 0x45]; // 45
    WeakHandle<game::Object> object; // 48
#else
    WeakHandle<game::Object> object; // 48
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(TagObjectRequest, 0x58);
RED4EXT_ASSERT_OFFSET(TagObjectRequest, object, 0x48);
#else
RED4EXT_ASSERT_SIZE(TagObjectRequest, 0x58);
#endif
} // namespace game
using gameTagObjectRequest = game::TagObjectRequest;
using TagObjectRequest = game::TagObjectRequest;
} // namespace RED4ext

// clang-format on
