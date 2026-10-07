#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/Containers/DynArray.hpp>
#include <RED4ext/Scripting/Natives/Generated/CResource.hpp>
#include <RED4ext/Scripting/Natives/Generated/loc/VoiceTag.hpp>

namespace RED4ext
{
namespace loc
{
struct VoiceTagListResource : CResource
{
    static constexpr const char* NAME = "locVoiceTagListResource";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    uint8_t unk39[0x40 - 0x39]; // 39
    DynArray<loc::VoiceTag> voiceTags; // 40
#else
    DynArray<loc::VoiceTag> voiceTags; // 40
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(VoiceTagListResource, 0x50);
RED4EXT_ASSERT_OFFSET(VoiceTagListResource, voiceTags, 0x40);
#else
RED4EXT_ASSERT_SIZE(VoiceTagListResource, 0x50);
#endif
} // namespace loc
using locVoiceTagListResource = loc::VoiceTagListResource;
} // namespace RED4ext

// clang-format on
