#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/Containers/DynArray.hpp>
#include <RED4ext/NativeTypes.hpp>
#include <RED4ext/Scripting/Natives/Generated/ent/IComponent.hpp>
#include <RED4ext/Scripting/Natives/Generated/game/FppRepDetachedObjectInfo.hpp>
#include <RED4ext/Scripting/Natives/Generated/game/TppRepAttachedObjectInfo.hpp>

namespace RED4ext
{
namespace game
{
struct TPPRepresentationComponent : ent::IComponent
{
    static constexpr const char* NAME = "gameTPPRepresentationComponent";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    uint8_t unk8D[0x90 - 0x8D]; // 8D
    DynArray<game::FppRepDetachedObjectInfo> detachedObjectInfo; // 90
    DynArray<game::TppRepAttachedObjectInfo> attachedObjectInfo; // A0
    DynArray<TweakDBID> affectedAppearanceSlots; // B0
    uint8_t unkC0[0x1D0 - 0xC0]; // C0
#else
    DynArray<game::FppRepDetachedObjectInfo> detachedObjectInfo; // 90
    DynArray<game::TppRepAttachedObjectInfo> attachedObjectInfo; // A0
    DynArray<TweakDBID> affectedAppearanceSlots; // B0
    uint8_t unkC0[0x1D0 - 0xC0]; // C0
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(TPPRepresentationComponent, 0x1D0);
RED4EXT_ASSERT_OFFSET(TPPRepresentationComponent, detachedObjectInfo, 0x90);
RED4EXT_ASSERT_OFFSET(TPPRepresentationComponent, attachedObjectInfo, 0xA0);
RED4EXT_ASSERT_OFFSET(TPPRepresentationComponent, affectedAppearanceSlots, 0xB0);
#else
RED4EXT_ASSERT_SIZE(TPPRepresentationComponent, 0x1D0);
#endif
} // namespace game
using gameTPPRepresentationComponent = game::TPPRepresentationComponent;
} // namespace RED4ext

// clang-format on
