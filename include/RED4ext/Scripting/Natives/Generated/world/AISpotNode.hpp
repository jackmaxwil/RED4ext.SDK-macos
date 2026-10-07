#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/CName.hpp>
#include <RED4ext/DynArray.hpp>
#include <RED4ext/Handle.hpp>
#include <RED4ext/NativeTypes.hpp>
#include <RED4ext/Scripting/Natives/Generated/red/TagList.hpp>
#include <RED4ext/Scripting/Natives/Generated/world/SocketNode.hpp>

namespace RED4ext
{
namespace AI { struct Spot; }
namespace world { struct TrafficSpotDefinition; }

namespace world
{
struct AISpotNode : world::SocketNode
{
    static constexpr const char* NAME = "worldAISpotNode";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    uint8_t unk32[0x38 - 0x32]; // 32
    Handle<world::TrafficSpotDefinition> spotDef; // 38
    Handle<AI::Spot> spot; // 48
    DynArray<CName> markings; // 58
    red::TagList crowdWhitelist; // 68
    red::TagList crowdBlacklist; // 78
    bool useCrowdWhitelist; // 88
    bool useCrowdBlacklist; // 89
    bool isWorkspotInfinite; // 8A
    bool isWorkspotStatic; // 8B
    bool disableBumps; // 8C
    uint8_t unk8D[0x90 - 0x8D]; // 8D
    NodeRef lookAtTarget; // 90
#else
    Handle<world::TrafficSpotDefinition> spotDef; // 38
    Handle<AI::Spot> spot; // 48
    DynArray<CName> markings; // 58
    red::TagList crowdWhitelist; // 68
    red::TagList crowdBlacklist; // 78
    bool useCrowdWhitelist; // 88
    bool useCrowdBlacklist; // 89
    bool isWorkspotInfinite; // 8A
    bool isWorkspotStatic; // 8B
    bool disableBumps; // 8C
    uint8_t unk8D[0x90 - 0x8D]; // 8D
    NodeRef lookAtTarget; // 90
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(AISpotNode, 0x98);
RED4EXT_ASSERT_OFFSET(AISpotNode, spotDef, 0x38);
RED4EXT_ASSERT_OFFSET(AISpotNode, spot, 0x48);
RED4EXT_ASSERT_OFFSET(AISpotNode, markings, 0x58);
RED4EXT_ASSERT_OFFSET(AISpotNode, crowdWhitelist, 0x68);
RED4EXT_ASSERT_OFFSET(AISpotNode, crowdBlacklist, 0x78);
RED4EXT_ASSERT_OFFSET(AISpotNode, useCrowdWhitelist, 0x88);
RED4EXT_ASSERT_OFFSET(AISpotNode, useCrowdBlacklist, 0x89);
RED4EXT_ASSERT_OFFSET(AISpotNode, isWorkspotInfinite, 0x8A);
RED4EXT_ASSERT_OFFSET(AISpotNode, isWorkspotStatic, 0x8B);
RED4EXT_ASSERT_OFFSET(AISpotNode, disableBumps, 0x8C);
RED4EXT_ASSERT_OFFSET(AISpotNode, lookAtTarget, 0x90);
#else
RED4EXT_ASSERT_SIZE(AISpotNode, 0x98);
#endif
} // namespace world
using worldAISpotNode = world::AISpotNode;
} // namespace RED4ext

// clang-format on
