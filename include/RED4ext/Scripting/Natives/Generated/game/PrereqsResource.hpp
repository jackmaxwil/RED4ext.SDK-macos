#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/Containers/DynArray.hpp>
#include <RED4ext/Scripting/Natives/Generated/CResource.hpp>
#include <RED4ext/Scripting/Natives/Generated/game/PrereqDefinition.hpp>

namespace RED4ext
{
namespace game
{
struct PrereqsResource : CResource
{
    static constexpr const char* NAME = "gamePrereqsResource";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    uint8_t unk39[0x40 - 0x39]; // 39
    DynArray<game::PrereqDefinition> prereqs; // 40
#else
    DynArray<game::PrereqDefinition> prereqs; // 40
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(PrereqsResource, 0x50);
RED4EXT_ASSERT_OFFSET(PrereqsResource, prereqs, 0x40);
#else
RED4EXT_ASSERT_SIZE(PrereqsResource, 0x50);
#endif
} // namespace game
using gamePrereqsResource = game::PrereqsResource;
} // namespace RED4ext

// clang-format on
