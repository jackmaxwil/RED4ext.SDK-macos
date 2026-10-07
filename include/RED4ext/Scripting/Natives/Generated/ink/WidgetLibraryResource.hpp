#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/Containers/DynArray.hpp>
#include <RED4ext/Handle.hpp>
#include <RED4ext/NativeTypes.hpp>
#include <RED4ext/Scripting/Natives/Generated/CResource.hpp>
#include <RED4ext/Scripting/Natives/Generated/ink/ETextureResolution.hpp>
#include <RED4ext/Scripting/Natives/Generated/ink/WidgetLibraryItem.hpp>
#include <RED4ext/Scripting/Natives/Generated/ink/WidgetResourceVersion.hpp>

namespace RED4ext
{
struct CResource;
namespace ink::anim { struct AnimationLibraryResource; }
namespace ink::anim { struct Sequence; }

namespace ink
{
struct WidgetLibraryResource : CResource
{
    static constexpr const char* NAME = "inkWidgetLibraryResource";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    ink::ETextureResolution rootResolution; // 39
    uint8_t unk3A[0x3C - 0x3A]; // 3A
    uint32_t rootDefinitionIndex; // 3C
    DynArray<ink::WidgetLibraryItem> libraryItems; // 40
    DynArray<Ref<ink::WidgetLibraryResource>> externalLibraries; // 50
    RaRef<ink::anim::AnimationLibraryResource> animationLibraryResRef; // 60
    uint8_t unk68[0x78 - 0x68]; // 68
    DynArray<Handle<ink::anim::Sequence>> sequences; // 78
    DynArray<RaRef<CResource>> externalDependenciesForInternalItems; // 88
    ink::WidgetResourceVersion version; // 98
    uint8_t unk99[0xA0 - 0x99]; // 99
#else
    ink::ETextureResolution rootResolution; // 40
    uint8_t unk41[0x44 - 0x41]; // 41
    uint32_t rootDefinitionIndex; // 44
    DynArray<ink::WidgetLibraryItem> libraryItems; // 48
    DynArray<Ref<ink::WidgetLibraryResource>> externalLibraries; // 58
    RaRef<ink::anim::AnimationLibraryResource> animationLibraryResRef; // 68
    uint8_t unk70[0x80 - 0x70]; // 70
    DynArray<Handle<ink::anim::Sequence>> sequences; // 80
    DynArray<RaRef<CResource>> externalDependenciesForInternalItems; // 90
    ink::WidgetResourceVersion version; // A0
    uint8_t unkA1[0xA8 - 0xA1]; // A1
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(WidgetLibraryResource, 0xA0);
RED4EXT_ASSERT_OFFSET(WidgetLibraryResource, rootResolution, 0x39);
RED4EXT_ASSERT_OFFSET(WidgetLibraryResource, rootDefinitionIndex, 0x3C);
RED4EXT_ASSERT_OFFSET(WidgetLibraryResource, libraryItems, 0x40);
RED4EXT_ASSERT_OFFSET(WidgetLibraryResource, externalLibraries, 0x50);
RED4EXT_ASSERT_OFFSET(WidgetLibraryResource, animationLibraryResRef, 0x60);
RED4EXT_ASSERT_OFFSET(WidgetLibraryResource, sequences, 0x78);
RED4EXT_ASSERT_OFFSET(WidgetLibraryResource, externalDependenciesForInternalItems, 0x88);
RED4EXT_ASSERT_OFFSET(WidgetLibraryResource, version, 0x98);
#else
RED4EXT_ASSERT_SIZE(WidgetLibraryResource, 0xA8);
#endif
} // namespace ink
using inkWidgetLibraryResource = ink::WidgetLibraryResource;
} // namespace RED4ext

// clang-format on
