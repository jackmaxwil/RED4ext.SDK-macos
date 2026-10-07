#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/DynArray.hpp>
#include <RED4ext/Handle.hpp>
#include <RED4ext/Scripting/Natives/Generated/CResource.hpp>

namespace RED4ext
{
namespace ink::anim { struct Sequence; }

namespace ink::anim
{
struct AnimationLibraryResource : CResource
{
    static constexpr const char* NAME = "inkanimAnimationLibraryResource";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    uint8_t unk39[0x40 - 0x39]; // 39
    DynArray<Handle<ink::anim::Sequence>> sequences; // 40
#else
    DynArray<Handle<ink::anim::Sequence>> sequences; // 40
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(AnimationLibraryResource, 0x50);
RED4EXT_ASSERT_OFFSET(AnimationLibraryResource, sequences, 0x40);
#else
RED4EXT_ASSERT_SIZE(AnimationLibraryResource, 0x50);
#endif
} // namespace ink::anim
using inkanimAnimationLibraryResource = ink::anim::AnimationLibraryResource;
} // namespace RED4ext

// clang-format on
