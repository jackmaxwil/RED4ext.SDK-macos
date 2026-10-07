#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/Handle.hpp>
#include <RED4ext/NativeTypes.hpp>
#include <RED4ext/Scripting/Natives/Generated/Quaternion.hpp>
#include <RED4ext/Scripting/Natives/Generated/ent/IPlacedComponent.hpp>
#include <RED4ext/Scripting/Natives/Generated/game/EffectRef.hpp>
#include <RED4ext/Scripting/Natives/Generated/game/projectile/OnCollisionAction.hpp>
#include <RED4ext/Scripting/Natives/Generated/game/projectile/VelocityParams.hpp>
#include <RED4ext/Scripting/Natives/Generated/physics/QueryPreset.hpp>

namespace RED4ext
{
namespace physics { struct FilterData; }
namespace world { struct Effect; }

namespace game::projectile
{
struct __declspec(align(0x10)) Component : ent::IPlacedComponent
{
    static constexpr const char* NAME = "gameprojectileComponent";
    static constexpr const char* ALIAS = "ProjectileComponent";

#ifdef __APPLE__
    uint8_t unk120[0x799 - 0x120]; // 120
    bool deriveOwnerVelocity; // 799
    uint8_t unk79A[0x79C - 0x79A]; // 79A
    game::projectile::OnCollisionAction onCollisionAction; // 79C
    bool useSweepCollision; // 7A0
    uint8_t unk7A1[0x7A4 - 0x7A1]; // 7A1
    float sweepCollisionRadius; // 7A4
    uint8_t unk7A8[0x7AC - 0x7A8]; // 7A8
    bool collisionsFilterClosest; // 7AC
    uint8_t unk7AD[0x7C0 - 0x7AD]; // 7AD
    game::projectile::VelocityParams derivedVelocityParams; // 7C0
    uint8_t unk7CC[0x7F0 - 0x7CC]; // 7CC
    Handle<physics::FilterData> filterData; // 7F0
    physics::QueryPreset queryPreset; // 800
    uint8_t unk808[0x810 - 0x808]; // 808
    game::EffectRef gameEffectRef; // 810
    uint8_t unk838[0x868 - 0x838]; // 838
    RaRef<world::Effect> previewEffect; // 868
    RaRef<world::Effect> bouncePreviewEffect; // 870
    RaRef<world::Effect> explosionPreviewEffect; // 878
    float explosionPreviewTime; // 880
    uint8_t unk884[0x890 - 0x884]; // 884
    Quaternion rotationOffset; // 890
    uint8_t unk8A0[0x910 - 0x8A0]; // 8A0
#else
    uint8_t unk120[0x7A9 - 0x120]; // 120
    bool deriveOwnerVelocity; // 7A9
    uint8_t unk7AA[0x7AC - 0x7AA]; // 7AA
    game::projectile::OnCollisionAction onCollisionAction; // 7AC
    bool useSweepCollision; // 7B0
    uint8_t unk7B1[0x7B4 - 0x7B1]; // 7B1
    float sweepCollisionRadius; // 7B4
    uint8_t unk7B8[0x7BC - 0x7B8]; // 7B8
    bool collisionsFilterClosest; // 7BC
    uint8_t unk7BD[0x7D0 - 0x7BD]; // 7BD
    game::projectile::VelocityParams derivedVelocityParams; // 7D0
    uint8_t unk7DC[0x800 - 0x7DC]; // 7DC
    Handle<physics::FilterData> filterData; // 800
    physics::QueryPreset queryPreset; // 810
    uint8_t unk818[0x820 - 0x818]; // 818
    game::EffectRef gameEffectRef; // 820
    uint8_t unk848[0x878 - 0x848]; // 848
    RaRef<world::Effect> previewEffect; // 878
    RaRef<world::Effect> bouncePreviewEffect; // 880
    RaRef<world::Effect> explosionPreviewEffect; // 888
    float explosionPreviewTime; // 890
    uint8_t unk894[0x8A0 - 0x894]; // 894
    Quaternion rotationOffset; // 8A0
    uint8_t unk8B0[0x920 - 0x8B0]; // 8B0
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(Component, 0x910);
RED4EXT_ASSERT_OFFSET(Component, deriveOwnerVelocity, 0x799);
RED4EXT_ASSERT_OFFSET(Component, onCollisionAction, 0x79C);
RED4EXT_ASSERT_OFFSET(Component, useSweepCollision, 0x7A0);
RED4EXT_ASSERT_OFFSET(Component, sweepCollisionRadius, 0x7A4);
RED4EXT_ASSERT_OFFSET(Component, collisionsFilterClosest, 0x7AC);
RED4EXT_ASSERT_OFFSET(Component, derivedVelocityParams, 0x7C0);
RED4EXT_ASSERT_OFFSET(Component, filterData, 0x7F0);
RED4EXT_ASSERT_OFFSET(Component, queryPreset, 0x800);
RED4EXT_ASSERT_OFFSET(Component, gameEffectRef, 0x810);
RED4EXT_ASSERT_OFFSET(Component, previewEffect, 0x868);
RED4EXT_ASSERT_OFFSET(Component, bouncePreviewEffect, 0x870);
RED4EXT_ASSERT_OFFSET(Component, explosionPreviewEffect, 0x878);
RED4EXT_ASSERT_OFFSET(Component, explosionPreviewTime, 0x880);
RED4EXT_ASSERT_OFFSET(Component, rotationOffset, 0x890);
#else
RED4EXT_ASSERT_SIZE(Component, 0x920);
#endif
} // namespace game::projectile
using gameprojectileComponent = game::projectile::Component;
using ProjectileComponent = game::projectile::Component;
} // namespace RED4ext

// clang-format on
