#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/Handle.hpp>
#include <RED4ext/Scripting/Natives/Generated/AI/behavior/TaskDefinition.hpp>

namespace RED4ext
{
namespace AI { struct ArgumentMapping; }

namespace AI::behavior
{
struct GenerateSearchInfluenceTaskDefinition : AI::behavior::TaskDefinition
{
    static constexpr const char* NAME = "AIbehaviorGenerateSearchInfluenceTaskDefinition";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    uint8_t unk31[0x38 - 0x31]; // 31
    Handle<AI::ArgumentMapping> position; // 38
    Handle<AI::ArgumentMapping> path; // 48
    Handle<AI::ArgumentMapping> radius; // 58
#else
    Handle<AI::ArgumentMapping> position; // 38
    Handle<AI::ArgumentMapping> path; // 48
    Handle<AI::ArgumentMapping> radius; // 58
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(GenerateSearchInfluenceTaskDefinition, 0x68);
RED4EXT_ASSERT_OFFSET(GenerateSearchInfluenceTaskDefinition, position, 0x38);
RED4EXT_ASSERT_OFFSET(GenerateSearchInfluenceTaskDefinition, path, 0x48);
RED4EXT_ASSERT_OFFSET(GenerateSearchInfluenceTaskDefinition, radius, 0x58);
#else
RED4EXT_ASSERT_SIZE(GenerateSearchInfluenceTaskDefinition, 0x68);
#endif
} // namespace AI::behavior
using AIbehaviorGenerateSearchInfluenceTaskDefinition = AI::behavior::GenerateSearchInfluenceTaskDefinition;
} // namespace RED4ext

// clang-format on
