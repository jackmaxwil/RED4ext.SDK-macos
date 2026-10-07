#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/CName.hpp>
#include <RED4ext/Scripting/Natives/Generated/game/ScriptableSystemRequest.hpp>

namespace RED4ext
{
namespace game
{
struct SDOClickedRequest : game::ScriptableSystemRequest
{
    static constexpr const char* NAME = "gameSDOClickedRequest";
    static constexpr const char* ALIAS = "SDOClickedRequest";

#ifdef __APPLE__
    uint8_t unk45[0x48 - 0x45]; // 45
    CName fullPath; // 48
    CName key; // 50
#else
    CName fullPath; // 48
    CName key; // 50
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(SDOClickedRequest, 0x58);
RED4EXT_ASSERT_OFFSET(SDOClickedRequest, fullPath, 0x48);
RED4EXT_ASSERT_OFFSET(SDOClickedRequest, key, 0x50);
#else
RED4EXT_ASSERT_SIZE(SDOClickedRequest, 0x58);
#endif
} // namespace game
using gameSDOClickedRequest = game::SDOClickedRequest;
using SDOClickedRequest = game::SDOClickedRequest;
} // namespace RED4ext

// clang-format on
