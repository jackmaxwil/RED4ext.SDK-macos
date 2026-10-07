#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/Handle.hpp>
#include <RED4ext/Scripting/Natives/Generated/CResource.hpp>

namespace RED4ext
{
struct ISerializable;

struct JsonResource : CResource
{
    static constexpr const char* NAME = "JsonResource";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    uint8_t unk39[0x40 - 0x39]; // 39
    Handle<ISerializable> root; // 40
#else
    Handle<ISerializable> root; // 40
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(JsonResource, 0x50);
RED4EXT_ASSERT_OFFSET(JsonResource, root, 0x40);
#else
RED4EXT_ASSERT_SIZE(JsonResource, 0x50);
#endif
} // namespace RED4ext

// clang-format on
