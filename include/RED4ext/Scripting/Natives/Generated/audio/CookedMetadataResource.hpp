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
namespace audio { struct AudioMetadata; }

namespace audio
{
struct CookedMetadataResource : CResource
{
    static constexpr const char* NAME = "audioCookedMetadataResource";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    uint8_t unk39[0x40 - 0x39]; // 39
    DynArray<Handle<audio::AudioMetadata>> entries; // 40
#else
    DynArray<Handle<audio::AudioMetadata>> entries; // 40
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(CookedMetadataResource, 0x50);
RED4EXT_ASSERT_OFFSET(CookedMetadataResource, entries, 0x40);
#else
RED4EXT_ASSERT_SIZE(CookedMetadataResource, 0x50);
#endif
} // namespace audio
using audioCookedMetadataResource = audio::CookedMetadataResource;
} // namespace RED4ext

// clang-format on
