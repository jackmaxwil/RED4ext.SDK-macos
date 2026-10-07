#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/CName.hpp>
#include <RED4ext/Containers/DynArray.hpp>
#include <RED4ext/Handle.hpp>
#include <RED4ext/Scripting/Natives/Generated/AI/TreeArgumentsDefinition.hpp>
#include <RED4ext/Scripting/Natives/Generated/CResource.hpp>

namespace RED4ext
{
namespace AI::behavior { struct BehaviorDelegate; }
namespace AI::behavior { struct TreeNodeDefinition; }

namespace AI::behavior
{
struct Resource : CResource
{
    static constexpr const char* NAME = "AIbehaviorResource";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    uint8_t unk39[0x40 - 0x39]; // 39
    Handle<AI::behavior::TreeNodeDefinition> root; // 40
    AI::TreeArgumentsDefinition arguments; // 50
    Handle<AI::behavior::BehaviorDelegate> delegate; // 68
    DynArray<CName> initializationEvents; // 78
#else
    Handle<AI::behavior::TreeNodeDefinition> root; // 40
    AI::TreeArgumentsDefinition arguments; // 50
    Handle<AI::behavior::BehaviorDelegate> delegate; // 68
    DynArray<CName> initializationEvents; // 78
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(Resource, 0x88);
RED4EXT_ASSERT_OFFSET(Resource, root, 0x40);
RED4EXT_ASSERT_OFFSET(Resource, arguments, 0x50);
RED4EXT_ASSERT_OFFSET(Resource, delegate, 0x68);
RED4EXT_ASSERT_OFFSET(Resource, initializationEvents, 0x78);
#else
RED4EXT_ASSERT_SIZE(Resource, 0x88);
#endif
} // namespace AI::behavior
using AIbehaviorResource = AI::behavior::Resource;
} // namespace RED4ext

// clang-format on
