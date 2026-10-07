#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/NativeTypes.hpp>
#include <RED4ext/Scripting/Natives/Generated/ent/IComponent.hpp>

namespace RED4ext
{
namespace game
{
struct ObjectCarrierComponent : ent::IComponent
{
    static constexpr const char* NAME = "gameObjectCarrierComponent";
    static constexpr const char* ALIAS = "ObjectCarrierComponent";

#ifdef __APPLE__
    uint8_t unk8D[0x90 - 0x8D]; // 8D
    TweakDBID objectToSpawn; // 90
    uint8_t unk98[0xA0 - 0x98]; // 98
#else
    TweakDBID objectToSpawn; // 90
    uint8_t unk98[0xA0 - 0x98]; // 98
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(ObjectCarrierComponent, 0xA0);
RED4EXT_ASSERT_OFFSET(ObjectCarrierComponent, objectToSpawn, 0x90);
#else
RED4EXT_ASSERT_SIZE(ObjectCarrierComponent, 0xA0);
#endif
} // namespace game
using gameObjectCarrierComponent = game::ObjectCarrierComponent;
using ObjectCarrierComponent = game::ObjectCarrierComponent;
} // namespace RED4ext

// clang-format on
