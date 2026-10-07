#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/DynArray.hpp>
#include <RED4ext/NativeTypes.hpp>
#include <RED4ext/Scripting/Natives/Generated/CResource.hpp>

namespace RED4ext
{
namespace anim { struct AnimSet; }

namespace anim
{
struct AnimSetupResource : CResource
{
    static constexpr const char* NAME = "animAnimSetupResource";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    uint8_t unk39[0x40 - 0x39]; // 39
    DynArray<Ref<anim::AnimSet>> dependencies; // 40
#else
    DynArray<Ref<anim::AnimSet>> dependencies; // 40
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(AnimSetupResource, 0x50);
RED4EXT_ASSERT_OFFSET(AnimSetupResource, dependencies, 0x40);
#else
RED4EXT_ASSERT_SIZE(AnimSetupResource, 0x50);
#endif
} // namespace anim
using animAnimSetupResource = anim::AnimSetupResource;
} // namespace RED4ext

// clang-format on
