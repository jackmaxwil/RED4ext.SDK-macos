#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/Handle.hpp>
#include <RED4ext/Scripting/Natives/Generated/AI/AIEvent.hpp>

namespace RED4ext
{
namespace ent { struct Entity; }
namespace game { struct StaticAreaShapeComponent; }

namespace AI
{
struct ApproachingAreaEvent : AI::AIEvent
{
    static constexpr const char* NAME = "AIApproachingAreaEvent";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    bool isApproachCancellation; // 4C
    uint8_t unk4D[0x50 - 0x4D]; // 4D
    WeakHandle<game::StaticAreaShapeComponent> areaComponent; // 50
    WeakHandle<ent::Entity> responseTarget; // 60
#else
    bool isApproachCancellation; // 50
    uint8_t unk51[0x58 - 0x51]; // 51
    WeakHandle<game::StaticAreaShapeComponent> areaComponent; // 58
    WeakHandle<ent::Entity> responseTarget; // 68
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(ApproachingAreaEvent, 0x70);
RED4EXT_ASSERT_OFFSET(ApproachingAreaEvent, isApproachCancellation, 0x4C);
RED4EXT_ASSERT_OFFSET(ApproachingAreaEvent, areaComponent, 0x50);
RED4EXT_ASSERT_OFFSET(ApproachingAreaEvent, responseTarget, 0x60);
#else
RED4EXT_ASSERT_SIZE(ApproachingAreaEvent, 0x78);
#endif
} // namespace AI
using AIApproachingAreaEvent = AI::ApproachingAreaEvent;
} // namespace RED4ext

// clang-format on
