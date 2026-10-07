#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/Containers/DynArray.hpp>
#include <RED4ext/Handle.hpp>
#include <RED4ext/Scripting/Natives/Generated/CResource.hpp>
#include <RED4ext/Scripting/Natives/Generated/anim/RigPart.hpp>

namespace RED4ext
{
namespace anim { struct IRigIkSetup; }

namespace anim
{
struct RigSharedData : CResource
{
    static constexpr const char* NAME = "animRigSharedData";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    uint8_t unk39[0x40 - 0x39]; // 39
    DynArray<anim::RigPart> parts; // 40
    DynArray<Handle<anim::IRigIkSetup>> ikSetups; // 50
#else
    DynArray<anim::RigPart> parts; // 40
    DynArray<Handle<anim::IRigIkSetup>> ikSetups; // 50
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(RigSharedData, 0x60);
RED4EXT_ASSERT_OFFSET(RigSharedData, parts, 0x40);
RED4EXT_ASSERT_OFFSET(RigSharedData, ikSetups, 0x50);
#else
RED4EXT_ASSERT_SIZE(RigSharedData, 0x60);
#endif
} // namespace anim
using animRigSharedData = anim::RigSharedData;
} // namespace RED4ext

// clang-format on
