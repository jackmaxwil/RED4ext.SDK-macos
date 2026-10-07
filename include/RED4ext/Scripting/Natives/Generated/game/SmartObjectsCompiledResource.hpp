#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/Handle.hpp>
#include <RED4ext/Scripting/Natives/Generated/Box.hpp>
#include <RED4ext/Scripting/Natives/Generated/res/StreamedResource.hpp>

namespace RED4ext
{
namespace game { struct CompiledNodes; }
namespace game { struct SmartObjectAnimationDatabase; }
namespace game { struct SmartObjectMembership; }
namespace game { struct SmartObjectPropertyDictionary; }
namespace game { struct SmartObjectTransformDictionary; }
namespace game { struct SmartObjectTransformSequenceDictionary; }

namespace game
{
struct __declspec(align(0x10)) SmartObjectsCompiledResource : res::StreamedResource
{
    static constexpr const char* NAME = "gameSmartObjectsCompiledResource";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    uint8_t unk39[0x40 - 0x39]; // 39
    Handle<game::SmartObjectAnimationDatabase> animationDatabase; // 40
    Handle<game::CompiledNodes> compiledNodesData; // 50
    Handle<game::SmartObjectTransformDictionary> transformDictionary; // 60
    Handle<game::SmartObjectPropertyDictionary> propertyDictionary; // 70
    Handle<game::SmartObjectTransformSequenceDictionary> transformSequenceDictionary; // 80
    Handle<game::SmartObjectMembership> soMembership; // 90
    Box localBoundingBox; // A0
#else
    Handle<game::SmartObjectAnimationDatabase> animationDatabase; // 40
    Handle<game::CompiledNodes> compiledNodesData; // 50
    Handle<game::SmartObjectTransformDictionary> transformDictionary; // 60
    Handle<game::SmartObjectPropertyDictionary> propertyDictionary; // 70
    Handle<game::SmartObjectTransformSequenceDictionary> transformSequenceDictionary; // 80
    Handle<game::SmartObjectMembership> soMembership; // 90
    Box localBoundingBox; // A0
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(SmartObjectsCompiledResource, 0xC0);
RED4EXT_ASSERT_OFFSET(SmartObjectsCompiledResource, animationDatabase, 0x40);
RED4EXT_ASSERT_OFFSET(SmartObjectsCompiledResource, compiledNodesData, 0x50);
RED4EXT_ASSERT_OFFSET(SmartObjectsCompiledResource, transformDictionary, 0x60);
RED4EXT_ASSERT_OFFSET(SmartObjectsCompiledResource, propertyDictionary, 0x70);
RED4EXT_ASSERT_OFFSET(SmartObjectsCompiledResource, transformSequenceDictionary, 0x80);
RED4EXT_ASSERT_OFFSET(SmartObjectsCompiledResource, soMembership, 0x90);
RED4EXT_ASSERT_OFFSET(SmartObjectsCompiledResource, localBoundingBox, 0xA0);
#else
RED4EXT_ASSERT_SIZE(SmartObjectsCompiledResource, 0xC0);
#endif
} // namespace game
using gameSmartObjectsCompiledResource = game::SmartObjectsCompiledResource;
} // namespace RED4ext

// clang-format on
