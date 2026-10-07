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
struct UnTagObjectRequest : game::ScriptableSystemRequest
{
    static constexpr const char* NAME = "gameUnTagObjectRequest";
    static constexpr const char* ALIAS = "UnTagObjectRequest";

#ifdef __APPLE__
    uint8_t unk45[0x48 - 0x45]; // 45
    WeakHandle<game::Object> object; // 48
#else
    WeakHandle<game::Object> object; // 48
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(UnTagObjectRequest, 0x58);
RED4EXT_ASSERT_OFFSET(UnTagObjectRequest, object, 0x48);
#else
RED4EXT_ASSERT_SIZE(UnTagObjectRequest, 0x58);
#endif
} // namespace game
using gameUnTagObjectRequest = game::UnTagObjectRequest;
using UnTagObjectRequest = game::UnTagObjectRequest;
} // namespace RED4ext

// clang-format on
