#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/CName.hpp>
#include <RED4ext/Scripting/Natives/Generated/world/Node.hpp>

namespace RED4ext
{
namespace world
{
struct AudioTagNode : world::Node
{
    static constexpr const char* NAME = "worldAudioTagNode";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    uint8_t unk32[0x38 - 0x32]; // 32
    CName audioTag; // 38
    float radius; // 40
    uint8_t unk44[0x48 - 0x44]; // 44
#else
    CName audioTag; // 38
    float radius; // 40
    uint8_t unk44[0x48 - 0x44]; // 44
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(AudioTagNode, 0x48);
RED4EXT_ASSERT_OFFSET(AudioTagNode, audioTag, 0x38);
RED4EXT_ASSERT_OFFSET(AudioTagNode, radius, 0x40);
#else
RED4EXT_ASSERT_SIZE(AudioTagNode, 0x48);
#endif
} // namespace world
using worldAudioTagNode = world::AudioTagNode;
} // namespace RED4ext

// clang-format on
