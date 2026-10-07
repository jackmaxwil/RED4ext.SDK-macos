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
namespace nav { struct LocomotionPath; }

namespace nav
{
struct LocomotionPathResource : CResource
{
    static constexpr const char* NAME = "navLocomotionPathResource";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    uint8_t unk39[0x40 - 0x39]; // 39
    DynArray<Handle<nav::LocomotionPath>> paths; // 40
    uint8_t unk50[0x80 - 0x50]; // 50
#else
    DynArray<Handle<nav::LocomotionPath>> paths; // 40
    uint8_t unk50[0x80 - 0x50]; // 50
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(LocomotionPathResource, 0x80);
RED4EXT_ASSERT_OFFSET(LocomotionPathResource, paths, 0x40);
#else
RED4EXT_ASSERT_SIZE(LocomotionPathResource, 0x80);
#endif
} // namespace nav
using navLocomotionPathResource = nav::LocomotionPathResource;
} // namespace RED4ext

// clang-format on
