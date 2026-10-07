#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/Handle.hpp>
#include <RED4ext/NativeTypes.hpp>
#include <RED4ext/Scripting/Natives/Generated/game/interactions/vis/IVisualizerDefinition.hpp>

namespace RED4ext
{
namespace game::interactions::vis { struct IVisualizerTimeProvider; }

namespace game::interactions::vis
{
struct DialogVisualizerDefinition : game::interactions::vis::IVisualizerDefinition
{
    static constexpr const char* NAME = "gameinteractionsvisDialogVisualizerDefinition";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    uint8_t unk42[0x48 - 0x42]; // 42
    CString displayNameOverride; // 48
    bool useLookAt; // 68
    uint8_t unk69[0x6C - 0x69]; // 69
    bool disableAfterSelectingChoice; // 6C
    uint8_t unk6D[0x70 - 0x6D]; // 6D
    Handle<game::interactions::vis::IVisualizerTimeProvider> timeProvider; // 70
    uint8_t hubPriority; // 80
    uint8_t unk81[0xA8 - 0x81]; // 81
#else
    CString displayNameOverride; // 48
    bool useLookAt; // 68
    uint8_t unk69[0x6C - 0x69]; // 69
    bool disableAfterSelectingChoice; // 6C
    uint8_t unk6D[0x70 - 0x6D]; // 6D
    Handle<game::interactions::vis::IVisualizerTimeProvider> timeProvider; // 70
    uint8_t hubPriority; // 80
    uint8_t unk81[0xA8 - 0x81]; // 81
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(DialogVisualizerDefinition, 0xA8);
RED4EXT_ASSERT_OFFSET(DialogVisualizerDefinition, displayNameOverride, 0x48);
RED4EXT_ASSERT_OFFSET(DialogVisualizerDefinition, useLookAt, 0x68);
RED4EXT_ASSERT_OFFSET(DialogVisualizerDefinition, disableAfterSelectingChoice, 0x6C);
RED4EXT_ASSERT_OFFSET(DialogVisualizerDefinition, timeProvider, 0x70);
RED4EXT_ASSERT_OFFSET(DialogVisualizerDefinition, hubPriority, 0x80);
#else
RED4EXT_ASSERT_SIZE(DialogVisualizerDefinition, 0xA8);
#endif
} // namespace game::interactions::vis
using gameinteractionsvisDialogVisualizerDefinition = game::interactions::vis::DialogVisualizerDefinition;
} // namespace RED4ext

// clang-format on
