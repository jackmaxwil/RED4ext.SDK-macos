#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/Containers/DynArray.hpp>
#include <RED4ext/NativeTypes.hpp>
#include <RED4ext/Scripting/Natives/Generated/CResource.hpp>
#include <RED4ext/Scripting/Natives/Generated/world/StreamingSectorCategory.hpp>

namespace RED4ext
{
struct CResource;
namespace world { struct StreamingSectorInplaceContent; }

namespace world
{
struct StreamingSector : CResource
{
    static constexpr const char* NAME = "worldStreamingSector";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    uint8_t unk39[0xA0 - 0x39]; // 39
    DynArray<Ref<CResource>> localInplaceResource; // A0
    uint8_t unkB0[0xC0 - 0xB0]; // B0
    RaRef<world::StreamingSectorInplaceContent> externInplaceResource; // C0
    uint8_t unkC8[0xD8 - 0xC8]; // C8
    uint8_t level; // D8
    world::StreamingSectorCategory category; // D9
    uint8_t unkDA[0xE0 - 0xDA]; // DA
#else
    uint8_t unk40[0xA0 - 0x40]; // 40
    DynArray<Ref<CResource>> localInplaceResource; // A0
    uint8_t unkB0[0xC0 - 0xB0]; // B0
    RaRef<world::StreamingSectorInplaceContent> externInplaceResource; // C0
    uint8_t unkC8[0xD8 - 0xC8]; // C8
    uint8_t level; // D8
    world::StreamingSectorCategory category; // D9
    uint8_t unkDA[0xE0 - 0xDA]; // DA
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(StreamingSector, 0xE0);
RED4EXT_ASSERT_OFFSET(StreamingSector, localInplaceResource, 0xA0);
RED4EXT_ASSERT_OFFSET(StreamingSector, externInplaceResource, 0xC0);
RED4EXT_ASSERT_OFFSET(StreamingSector, level, 0xD8);
RED4EXT_ASSERT_OFFSET(StreamingSector, category, 0xD9);
#else
RED4EXT_ASSERT_SIZE(StreamingSector, 0xE0);
#endif
} // namespace world
using worldStreamingSector = world::StreamingSector;
} // namespace RED4ext

// clang-format on
