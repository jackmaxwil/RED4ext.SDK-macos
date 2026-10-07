#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/ISerializable.hpp>

namespace RED4ext
{
namespace world
{
struct Node : ISerializable
{
    static constexpr const char* NAME = "worldNode";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    bool isVisibleInGame; // 30
    bool isHostOnly; // 31
#else
    bool isVisibleInGame; // 30
    bool isHostOnly; // 31
    uint8_t unk32[0x38 - 0x32]; // 32
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(Node, 0x38);
RED4EXT_ASSERT_OFFSET(Node, isVisibleInGame, 0x30);
RED4EXT_ASSERT_OFFSET(Node, isHostOnly, 0x31);
#else
RED4EXT_ASSERT_SIZE(Node, 0x38);
#endif
} // namespace world
using worldNode = world::Node;
} // namespace RED4ext

// clang-format on
