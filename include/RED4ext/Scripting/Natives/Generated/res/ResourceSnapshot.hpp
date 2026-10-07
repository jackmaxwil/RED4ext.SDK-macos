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
struct CResource;

namespace res
{
struct ResourceSnapshot : CResource
{
    static constexpr const char* NAME = "resResourceSnapshot";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    uint8_t unk39[0x40 - 0x39]; // 39
    DynArray<RaRef<CResource>> resources; // 40
#else
    DynArray<RaRef<CResource>> resources; // 40
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(ResourceSnapshot, 0x50);
RED4EXT_ASSERT_OFFSET(ResourceSnapshot, resources, 0x40);
#else
RED4EXT_ASSERT_SIZE(ResourceSnapshot, 0x50);
#endif
} // namespace res
using resResourceSnapshot = res::ResourceSnapshot;
} // namespace RED4ext

// clang-format on
