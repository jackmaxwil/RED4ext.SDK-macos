#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/CName.hpp>
#include <RED4ext/Scripting/Natives/Generated/game/ScriptableSystemRequest.hpp>

namespace RED4ext
{
namespace quest
{
struct SetPhoneStatusRequest : game::ScriptableSystemRequest
{
    static constexpr const char* NAME = "questSetPhoneStatusRequest";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    uint8_t unk45[0x48 - 0x45]; // 45
    CName status; // 48
#else
    CName status; // 48
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(SetPhoneStatusRequest, 0x50);
RED4EXT_ASSERT_OFFSET(SetPhoneStatusRequest, status, 0x48);
#else
RED4EXT_ASSERT_SIZE(SetPhoneStatusRequest, 0x50);
#endif
} // namespace quest
using questSetPhoneStatusRequest = quest::SetPhoneStatusRequest;
} // namespace RED4ext

// clang-format on
