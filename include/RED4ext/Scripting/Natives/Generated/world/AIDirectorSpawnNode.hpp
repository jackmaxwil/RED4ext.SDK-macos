#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/Scripting/Natives/Generated/red/TagList.hpp>
#include <RED4ext/Scripting/Natives/Generated/world/Node.hpp>

namespace RED4ext
{
namespace world
{
struct AIDirectorSpawnNode : world::Node
{
    static constexpr const char* NAME = "worldAIDirectorSpawnNode";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    uint8_t unk32[0x38 - 0x32]; // 32
    red::TagList tags; // 38
#else
    red::TagList tags; // 38
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(AIDirectorSpawnNode, 0x48);
RED4EXT_ASSERT_OFFSET(AIDirectorSpawnNode, tags, 0x38);
#else
RED4EXT_ASSERT_SIZE(AIDirectorSpawnNode, 0x48);
#endif
} // namespace world
using worldAIDirectorSpawnNode = world::AIDirectorSpawnNode;
} // namespace RED4ext

// clang-format on
