#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/CName.hpp>
#include <RED4ext/Handle.hpp>
#include <RED4ext/Scripting/Natives/Generated/Vector4.hpp>
#include <RED4ext/Scripting/Natives/Generated/game/QueryResult.hpp>
#include <RED4ext/Scripting/Natives/Generated/red/Event.hpp>

namespace RED4ext
{
namespace ent { struct IPlacedComponent; }
namespace game { struct AttackComputed; }
namespace game { struct Object; }
namespace game::damage { struct AttackData; }

namespace game::events
{
struct __declspec(align(0x10)) HitEvent : red::Event
{
    static constexpr const char* NAME = "gameeventsHitEvent";
    static constexpr const char* ALIAS = "gameHitEvent";

#ifdef __APPLE__
    Handle<game::damage::AttackData> attackData; // 40
    WeakHandle<game::Object> target; // 50
    Vector4 hitPosition; // 60
    Vector4 hitDirection; // 70
    WeakHandle<ent::IPlacedComponent> hitComponent; // 80
    CName hitColliderTag; // 90
    uint8_t unk98[0xA0 - 0x98]; // 98
    game::QueryResult hitRepresentationResult; // A0
    uint8_t unkB0[0xC8 - 0xB0]; // B0
    float attackPentration; // C8
    bool hasPiercedTechSurface; // CC
    uint8_t unkCD[0xD0 - 0xCD]; // CD
    Handle<game::AttackComputed> attackComputed; // D0
    uint8_t unkE0[0xE8 - 0xE0]; // E0
#else
    Handle<game::damage::AttackData> attackData; // 40
    WeakHandle<game::Object> target; // 50
    Vector4 hitPosition; // 60
    Vector4 hitDirection; // 70
    WeakHandle<ent::IPlacedComponent> hitComponent; // 80
    CName hitColliderTag; // 90
    uint8_t unk98[0xA0 - 0x98]; // 98
    game::QueryResult hitRepresentationResult; // A0
    uint8_t unkB0[0xC8 - 0xB0]; // B0
    float attackPentration; // C8
    bool hasPiercedTechSurface; // CC
    uint8_t unkCD[0xD0 - 0xCD]; // CD
    Handle<game::AttackComputed> attackComputed; // D0
    uint8_t unkE0[0xF0 - 0xE0]; // E0
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(HitEvent, 0xF0);
RED4EXT_ASSERT_OFFSET(HitEvent, attackData, 0x40);
RED4EXT_ASSERT_OFFSET(HitEvent, target, 0x50);
RED4EXT_ASSERT_OFFSET(HitEvent, hitPosition, 0x60);
RED4EXT_ASSERT_OFFSET(HitEvent, hitDirection, 0x70);
RED4EXT_ASSERT_OFFSET(HitEvent, hitComponent, 0x80);
RED4EXT_ASSERT_OFFSET(HitEvent, hitColliderTag, 0x90);
RED4EXT_ASSERT_OFFSET(HitEvent, hitRepresentationResult, 0xA0);
RED4EXT_ASSERT_OFFSET(HitEvent, attackPentration, 0xC8);
RED4EXT_ASSERT_OFFSET(HitEvent, hasPiercedTechSurface, 0xCC);
RED4EXT_ASSERT_OFFSET(HitEvent, attackComputed, 0xD0);
#else
RED4EXT_ASSERT_SIZE(HitEvent, 0xF0);
#endif
} // namespace game::events
using gameeventsHitEvent = game::events::HitEvent;
using gameHitEvent = game::events::HitEvent;
} // namespace RED4ext

// clang-format on
