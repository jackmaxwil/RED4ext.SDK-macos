#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/CName.hpp>
#include <RED4ext/DynArray.hpp>
#include <RED4ext/NativeTypes.hpp>
#include <RED4ext/Scripting/Natives/Generated/ent/SlotComponent.hpp>
#include <RED4ext/Scripting/Natives/Generated/game/HitRepresentationOverride.hpp>
#include <RED4ext/Scripting/Natives/Generated/game/HitShapeBVH.hpp>
#include <RED4ext/Scripting/Natives/Generated/game/HitShapeContainer.hpp>

namespace RED4ext
{
namespace game { struct HitRepresentationResource; }

namespace game
{
struct __declspec(align(0x10)) HitRepresentationComponent : ent::SlotComponent
{
    static constexpr const char* NAME = "gameHitRepresentationComponent";
    static constexpr const char* ALIAS = "HitRepresentationComponent";

#ifdef __APPLE__
    RaRef<game::HitRepresentationResource> resource; // 1A0
    uint8_t unk1A8[0x1C0 - 0x1A8]; // 1A8
    DynArray<game::HitRepresentationOverride> appearanceOverrides; // 1C0
    DynArray<game::HitShapeContainer> representations; // 1D0
    uint8_t unk1E0[0x200 - 0x1E0]; // 1E0
    CName physicsMaterial; // 200
    bool useResourceData; // 208
    uint8_t unk209[0x220 - 0x209]; // 209
    game::HitShapeBVH bvhRoot; // 220
    uint8_t unk2B0[0x340 - 0x2B0]; // 2B0
#else
    uint8_t unk1A0[0x1A8 - 0x1A0]; // 1A0
    RaRef<game::HitRepresentationResource> resource; // 1A8
    uint8_t unk1B0[0x1C8 - 0x1B0]; // 1B0
    DynArray<game::HitRepresentationOverride> appearanceOverrides; // 1C8
    DynArray<game::HitShapeContainer> representations; // 1D8
    uint8_t unk1E8[0x208 - 0x1E8]; // 1E8
    CName physicsMaterial; // 208
    bool useResourceData; // 210
    uint8_t unk211[0x230 - 0x211]; // 211
    game::HitShapeBVH bvhRoot; // 230
    uint8_t unk2C0[0x350 - 0x2C0]; // 2C0
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(HitRepresentationComponent, 0x340);
RED4EXT_ASSERT_OFFSET(HitRepresentationComponent, resource, 0x1A0);
RED4EXT_ASSERT_OFFSET(HitRepresentationComponent, appearanceOverrides, 0x1C0);
RED4EXT_ASSERT_OFFSET(HitRepresentationComponent, representations, 0x1D0);
RED4EXT_ASSERT_OFFSET(HitRepresentationComponent, physicsMaterial, 0x200);
RED4EXT_ASSERT_OFFSET(HitRepresentationComponent, useResourceData, 0x208);
RED4EXT_ASSERT_OFFSET(HitRepresentationComponent, bvhRoot, 0x220);
#else
RED4EXT_ASSERT_SIZE(HitRepresentationComponent, 0x350);
#endif
} // namespace game
using gameHitRepresentationComponent = game::HitRepresentationComponent;
using HitRepresentationComponent = game::HitRepresentationComponent;
} // namespace RED4ext

// clang-format on
