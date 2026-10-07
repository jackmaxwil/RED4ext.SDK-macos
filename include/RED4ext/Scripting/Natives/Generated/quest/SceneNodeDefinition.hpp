#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/DynArray.hpp>
#include <RED4ext/Handle.hpp>
#include <RED4ext/NativeTypes.hpp>
#include <RED4ext/Scripting/Natives/Generated/quest/SignalStoppingNodeDefinition.hpp>
#include <RED4ext/Scripting/Natives/Generated/scn/WorldMarker.hpp>

namespace RED4ext
{
namespace scn { struct IInterruptionOperation; }
namespace scn { struct SceneResource; }

namespace quest
{
struct SceneNodeDefinition : quest::SignalStoppingNodeDefinition
{
    static constexpr const char* NAME = "questSceneNodeDefinition";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    uint8_t unk42[0x48 - 0x42]; // 42
    RaRef<scn::SceneResource> sceneFile; // 48
    scn::WorldMarker sceneLocation; // 50
    DynArray<Handle<scn::IInterruptionOperation>> interruptionOperations; // 68
    bool syncToMusic; // 78
    bool notAllowedToBeFrozen; // 79
    bool reapplyInterruptionOperationsAfterGameLoad; // 7A
    uint8_t unk7B[0x88 - 0x7B]; // 7B
#else
    RaRef<scn::SceneResource> sceneFile; // 48
    scn::WorldMarker sceneLocation; // 50
    DynArray<Handle<scn::IInterruptionOperation>> interruptionOperations; // 68
    bool syncToMusic; // 78
    bool notAllowedToBeFrozen; // 79
    bool reapplyInterruptionOperationsAfterGameLoad; // 7A
    uint8_t unk7B[0x88 - 0x7B]; // 7B
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(SceneNodeDefinition, 0x88);
RED4EXT_ASSERT_OFFSET(SceneNodeDefinition, sceneFile, 0x48);
RED4EXT_ASSERT_OFFSET(SceneNodeDefinition, sceneLocation, 0x50);
RED4EXT_ASSERT_OFFSET(SceneNodeDefinition, interruptionOperations, 0x68);
RED4EXT_ASSERT_OFFSET(SceneNodeDefinition, syncToMusic, 0x78);
RED4EXT_ASSERT_OFFSET(SceneNodeDefinition, notAllowedToBeFrozen, 0x79);
RED4EXT_ASSERT_OFFSET(SceneNodeDefinition, reapplyInterruptionOperationsAfterGameLoad, 0x7A);
#else
RED4EXT_ASSERT_SIZE(SceneNodeDefinition, 0x88);
#endif
} // namespace quest
using questSceneNodeDefinition = quest::SceneNodeDefinition;
} // namespace RED4ext

// clang-format on
