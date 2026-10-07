#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/CName.hpp>
#include <RED4ext/Containers/DynArray.hpp>
#include <RED4ext/Scripting/Natives/Generated/CResource.hpp>
#include <RED4ext/Scripting/Natives/Generated/anim/LipsyncMappingSceneEntry.hpp>

namespace RED4ext
{
namespace anim
{
struct LipsyncMapping : CResource
{
    static constexpr const char* NAME = "animLipsyncMapping";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    uint8_t unk39[0x40 - 0x39]; // 39
    CName languageCodeName; // 40
    DynArray<uint64_t> scenePaths; // 48
    DynArray<anim::LipsyncMappingSceneEntry> sceneEntries; // 58
#else
    CName languageCodeName; // 40
    DynArray<uint64_t> scenePaths; // 48
    DynArray<anim::LipsyncMappingSceneEntry> sceneEntries; // 58
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(LipsyncMapping, 0x68);
RED4EXT_ASSERT_OFFSET(LipsyncMapping, languageCodeName, 0x40);
RED4EXT_ASSERT_OFFSET(LipsyncMapping, scenePaths, 0x48);
RED4EXT_ASSERT_OFFSET(LipsyncMapping, sceneEntries, 0x58);
#else
RED4EXT_ASSERT_SIZE(LipsyncMapping, 0x68);
#endif
} // namespace anim
using animLipsyncMapping = anim::LipsyncMapping;
} // namespace RED4ext

// clang-format on
