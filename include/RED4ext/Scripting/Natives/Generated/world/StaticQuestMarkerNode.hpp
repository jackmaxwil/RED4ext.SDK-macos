#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/CName.hpp>
#include <RED4ext/NativeTypes.hpp>
#include <RED4ext/Scripting/Natives/Generated/world/Node.hpp>
#include <RED4ext/Scripting/Natives/Generated/world/QuestType.hpp>

namespace RED4ext
{
namespace world
{
struct StaticQuestMarkerNode : world::Node
{
    static constexpr const char* NAME = "worldStaticQuestMarkerNode";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    uint8_t unk32[0x48 - 0x32]; // 32
    world::QuestType questType; // 48
    uint8_t unk49[0x50 - 0x49]; // 49
    CString questLabel; // 50
    float questMarkerHeight; // 70
    uint8_t unk74[0x78 - 0x74]; // 74
    CName mapFilteringTag; // 78
#else
    uint8_t unk38[0x48 - 0x38]; // 38
    world::QuestType questType; // 48
    uint8_t unk49[0x50 - 0x49]; // 49
    CString questLabel; // 50
    float questMarkerHeight; // 70
    uint8_t unk74[0x78 - 0x74]; // 74
    CName mapFilteringTag; // 78
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(StaticQuestMarkerNode, 0x80);
RED4EXT_ASSERT_OFFSET(StaticQuestMarkerNode, questType, 0x48);
RED4EXT_ASSERT_OFFSET(StaticQuestMarkerNode, questLabel, 0x50);
RED4EXT_ASSERT_OFFSET(StaticQuestMarkerNode, questMarkerHeight, 0x70);
RED4EXT_ASSERT_OFFSET(StaticQuestMarkerNode, mapFilteringTag, 0x78);
#else
RED4EXT_ASSERT_SIZE(StaticQuestMarkerNode, 0x80);
#endif
} // namespace world
using worldStaticQuestMarkerNode = world::StaticQuestMarkerNode;
} // namespace RED4ext

// clang-format on
