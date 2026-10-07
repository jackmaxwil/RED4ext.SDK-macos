#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/Containers/DynArray.hpp>
#include <RED4ext/NativeTypes.hpp>
#include <RED4ext/Scripting/Natives/Generated/CResource.hpp>

namespace RED4ext
{
struct CResource;

namespace red
{
struct ResourceListResource : CResource
{
    static constexpr const char* NAME = "redResourceListResource";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    uint8_t unk39[0x40 - 0x39]; // 39
    DynArray<RaRef<CResource>> resources; // 40
    DynArray<CString> descriptions; // 50
#else
    DynArray<RaRef<CResource>> resources; // 40
    DynArray<CString> descriptions; // 50
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(ResourceListResource, 0x60);
RED4EXT_ASSERT_OFFSET(ResourceListResource, resources, 0x40);
RED4EXT_ASSERT_OFFSET(ResourceListResource, descriptions, 0x50);
#else
RED4EXT_ASSERT_SIZE(ResourceListResource, 0x60);
#endif
} // namespace red
using redResourceListResource = red::ResourceListResource;
} // namespace RED4ext

// clang-format on
