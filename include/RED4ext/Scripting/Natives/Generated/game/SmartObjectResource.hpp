#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/Containers/DynArray.hpp>
#include <RED4ext/Scripting/Natives/Generated/CResource.hpp>
#include <RED4ext/Scripting/Natives/Generated/game/BodyTypeAnimationDefinition.hpp>
#include <RED4ext/Scripting/Natives/Generated/game/SmartObjectGate.hpp>
#include <RED4ext/Scripting/Natives/Generated/game/SmartObjectType.hpp>

namespace RED4ext
{
namespace game
{
struct SmartObjectResource : CResource
{
    static constexpr const char* NAME = "gameSmartObjectResource";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    uint8_t unk39[0x40 - 0x39]; // 39
    DynArray<game::SmartObjectGate> entryPoints; // 40
    DynArray<game::SmartObjectGate> exitPoints; // 50
    DynArray<game::BodyTypeAnimationDefinition> bodyTypes; // 60
    DynArray<game::SmartObjectGate> loopAnimations; // 70
    game::SmartObjectType type; // 80
    uint8_t unk84[0x88 - 0x84]; // 84
#else
    DynArray<game::SmartObjectGate> entryPoints; // 40
    DynArray<game::SmartObjectGate> exitPoints; // 50
    DynArray<game::BodyTypeAnimationDefinition> bodyTypes; // 60
    DynArray<game::SmartObjectGate> loopAnimations; // 70
    game::SmartObjectType type; // 80
    uint8_t unk84[0x88 - 0x84]; // 84
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(SmartObjectResource, 0x88);
RED4EXT_ASSERT_OFFSET(SmartObjectResource, entryPoints, 0x40);
RED4EXT_ASSERT_OFFSET(SmartObjectResource, exitPoints, 0x50);
RED4EXT_ASSERT_OFFSET(SmartObjectResource, bodyTypes, 0x60);
RED4EXT_ASSERT_OFFSET(SmartObjectResource, loopAnimations, 0x70);
RED4EXT_ASSERT_OFFSET(SmartObjectResource, type, 0x80);
#else
RED4EXT_ASSERT_SIZE(SmartObjectResource, 0x88);
#endif
} // namespace game
using gameSmartObjectResource = game::SmartObjectResource;
} // namespace RED4ext

// clang-format on
