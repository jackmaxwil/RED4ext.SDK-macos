#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/Handle.hpp>
#include <RED4ext/NativeTypes.hpp>
#include <RED4ext/Scripting/Natives/Generated/game/interactions/vis/IVisualizerDefinition.hpp>
#include <RED4ext/Scripting/Natives/Generated/game/interactions/vis/InteractionType.hpp>

namespace RED4ext
{
namespace game::interactions::vis { struct IVisualizerTimeProvider; }

namespace game::interactions::vis
{
struct DeviceVisualizerDefinition : game::interactions::vis::IVisualizerDefinition
{
    static constexpr const char* NAME = "gameinteractionsvisDeviceVisualizerDefinition";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    game::interactions::vis::InteractionType interactionType; // 42
    uint8_t unk43[0x48 - 0x43]; // 43
    CString displayNameOverride; // 48
    bool isDynamic; // 68
    bool useDefaultActionMapping; // 69
    bool createMappin; // 6A
    uint8_t unk6B[0x70 - 0x6B]; // 6B
    Handle<game::interactions::vis::IVisualizerTimeProvider> timeProvider; // 70
    uint8_t unk80[0x88 - 0x80]; // 80
#else
    game::interactions::vis::InteractionType interactionType; // 48
    uint8_t unk49[0x50 - 0x49]; // 49
    CString displayNameOverride; // 50
    bool isDynamic; // 70
    bool useDefaultActionMapping; // 71
    bool createMappin; // 72
    uint8_t unk73[0x78 - 0x73]; // 73
    Handle<game::interactions::vis::IVisualizerTimeProvider> timeProvider; // 78
    uint8_t unk88[0x90 - 0x88]; // 88
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(DeviceVisualizerDefinition, 0x88);
RED4EXT_ASSERT_OFFSET(DeviceVisualizerDefinition, interactionType, 0x42);
RED4EXT_ASSERT_OFFSET(DeviceVisualizerDefinition, displayNameOverride, 0x48);
RED4EXT_ASSERT_OFFSET(DeviceVisualizerDefinition, isDynamic, 0x68);
RED4EXT_ASSERT_OFFSET(DeviceVisualizerDefinition, useDefaultActionMapping, 0x69);
RED4EXT_ASSERT_OFFSET(DeviceVisualizerDefinition, createMappin, 0x6A);
RED4EXT_ASSERT_OFFSET(DeviceVisualizerDefinition, timeProvider, 0x70);
#else
RED4EXT_ASSERT_SIZE(DeviceVisualizerDefinition, 0x90);
#endif
} // namespace game::interactions::vis
using gameinteractionsvisDeviceVisualizerDefinition = game::interactions::vis::DeviceVisualizerDefinition;
} // namespace RED4ext

// clang-format on
