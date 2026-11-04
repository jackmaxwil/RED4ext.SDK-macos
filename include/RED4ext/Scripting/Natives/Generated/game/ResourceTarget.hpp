#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/Scripting/Natives/Generated/game/CallbackSystemTarget.hpp>

namespace RED4ext
{
namespace game
{
struct ResourceTarget : game::CallbackSystemTarget
{
    static constexpr const char* NAME = "gameResourceTarget";
    static constexpr const char* ALIAS = "ResourceTarget";

#ifdef __APPLE__
    uint8_t unk40[0x98 - 0x40]; // 40
#else
    uint8_t unk40[0x80 - 0x40]; // 40
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(ResourceTarget, 0x98);
#else
RED4EXT_ASSERT_SIZE(ResourceTarget, 0x80);
#endif
} // namespace game
using gameResourceTarget = game::ResourceTarget;
using ResourceTarget = game::ResourceTarget;
} // namespace RED4ext

// clang-format on
