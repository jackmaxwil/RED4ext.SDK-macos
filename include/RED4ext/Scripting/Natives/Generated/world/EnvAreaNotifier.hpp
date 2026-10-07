#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/CName.hpp>
#include <RED4ext/DynArray.hpp>
#include <RED4ext/NativeTypes.hpp>
#include <RED4ext/Scripting/Natives/Generated/WorldRenderAreaSettings.hpp>
#include <RED4ext/Scripting/Natives/Generated/world/ITriggerAreaNotifer.hpp>

namespace RED4ext
{
namespace world { struct EnvironmentAreaParameters; }

namespace world
{
struct EnvAreaNotifier : world::ITriggerAreaNotifer
{
    static constexpr const char* NAME = "worldEnvAreaNotifier";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    uint8_t unkB2[0xB8 - 0xB2]; // B2
    Ref<world::EnvironmentAreaParameters> env; // B8
    WorldRenderAreaSettings params; // D0
    float blendTimeIn; // E0
    float blendTimeOut; // E4
    uint8_t priority; // E8
    uint8_t unkE9[0xEC - 0xE9]; // E9
    float horizontalFadeDistance; // EC
    float verticalFadeDistance; // F0
    uint8_t unkF4[0xF8 - 0xF4]; // F4
    DynArray<CName> weatherStateNames; // F8
    DynArray<bool> weatherStateValues; // 108
    uint8_t resourceVersion; // 118
    uint8_t unk119[0x120 - 0x119]; // 119
#else
    Ref<world::EnvironmentAreaParameters> env; // B8
    WorldRenderAreaSettings params; // D0
    float blendTimeIn; // E0
    float blendTimeOut; // E4
    uint8_t priority; // E8
    uint8_t unkE9[0xEC - 0xE9]; // E9
    float horizontalFadeDistance; // EC
    float verticalFadeDistance; // F0
    uint8_t unkF4[0xF8 - 0xF4]; // F4
    DynArray<CName> weatherStateNames; // F8
    DynArray<bool> weatherStateValues; // 108
    uint8_t resourceVersion; // 118
    uint8_t unk119[0x120 - 0x119]; // 119
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(EnvAreaNotifier, 0x120);
RED4EXT_ASSERT_OFFSET(EnvAreaNotifier, env, 0xB8);
RED4EXT_ASSERT_OFFSET(EnvAreaNotifier, params, 0xD0);
RED4EXT_ASSERT_OFFSET(EnvAreaNotifier, blendTimeIn, 0xE0);
RED4EXT_ASSERT_OFFSET(EnvAreaNotifier, blendTimeOut, 0xE4);
RED4EXT_ASSERT_OFFSET(EnvAreaNotifier, priority, 0xE8);
RED4EXT_ASSERT_OFFSET(EnvAreaNotifier, horizontalFadeDistance, 0xEC);
RED4EXT_ASSERT_OFFSET(EnvAreaNotifier, verticalFadeDistance, 0xF0);
RED4EXT_ASSERT_OFFSET(EnvAreaNotifier, weatherStateNames, 0xF8);
RED4EXT_ASSERT_OFFSET(EnvAreaNotifier, weatherStateValues, 0x108);
RED4EXT_ASSERT_OFFSET(EnvAreaNotifier, resourceVersion, 0x118);
#else
RED4EXT_ASSERT_SIZE(EnvAreaNotifier, 0x120);
#endif
} // namespace world
using worldEnvAreaNotifier = world::EnvAreaNotifier;
} // namespace RED4ext

// clang-format on
