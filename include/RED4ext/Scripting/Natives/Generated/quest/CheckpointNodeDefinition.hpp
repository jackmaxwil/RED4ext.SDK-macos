#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/Containers/DynArray.hpp>
#include <RED4ext/NativeTypes.hpp>
#include <RED4ext/Scripting/Natives/Generated/quest/SignalStoppingNodeDefinition.hpp>

namespace RED4ext
{
namespace quest
{
struct CheckpointNodeDefinition : quest::SignalStoppingNodeDefinition
{
    static constexpr const char* NAME = "questCheckpointNodeDefinition";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    bool saveLock; // 42
    bool ignoreSaveLocks; // 43
    bool pointOfNoReturn; // 44
    bool endGameSave; // 45
    bool retryOnFailure; // 46
    uint8_t unk47[0x48 - 0x47]; // 47
    DynArray<TweakDBID> additionalEndGameRewardsTweak; // 48
    CString debugString; // 58
#else
    bool saveLock; // 48
    bool ignoreSaveLocks; // 49
    bool pointOfNoReturn; // 4A
    bool endGameSave; // 4B
    bool retryOnFailure; // 4C
    uint8_t unk4D[0x50 - 0x4D]; // 4D
    DynArray<TweakDBID> additionalEndGameRewardsTweak; // 50
    CString debugString; // 60
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(CheckpointNodeDefinition, 0x78);
RED4EXT_ASSERT_OFFSET(CheckpointNodeDefinition, saveLock, 0x42);
RED4EXT_ASSERT_OFFSET(CheckpointNodeDefinition, ignoreSaveLocks, 0x43);
RED4EXT_ASSERT_OFFSET(CheckpointNodeDefinition, pointOfNoReturn, 0x44);
RED4EXT_ASSERT_OFFSET(CheckpointNodeDefinition, endGameSave, 0x45);
RED4EXT_ASSERT_OFFSET(CheckpointNodeDefinition, retryOnFailure, 0x46);
RED4EXT_ASSERT_OFFSET(CheckpointNodeDefinition, additionalEndGameRewardsTweak, 0x48);
RED4EXT_ASSERT_OFFSET(CheckpointNodeDefinition, debugString, 0x58);
#else
RED4EXT_ASSERT_SIZE(CheckpointNodeDefinition, 0x80);
#endif
} // namespace quest
using questCheckpointNodeDefinition = quest::CheckpointNodeDefinition;
} // namespace RED4ext

// clang-format on
