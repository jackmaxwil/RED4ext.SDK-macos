#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/DynArray.hpp>
#include <RED4ext/Scripting/Natives/Generated/CResource.hpp>
#include <RED4ext/Scripting/Natives/Generated/scn/ScenesVersionsSceneChanges.hpp>

namespace RED4ext
{
namespace scn
{
struct ScenesVersions : CResource
{
    static constexpr const char* NAME = "scnScenesVersions";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    uint8_t unk39[0x3C - 0x39]; // 39
    uint32_t currentVersion; // 3C
    DynArray<scn::ScenesVersionsSceneChanges> scenes; // 40
#else
    uint32_t currentVersion; // 40
    uint8_t unk44[0x48 - 0x44]; // 44
    DynArray<scn::ScenesVersionsSceneChanges> scenes; // 48
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(ScenesVersions, 0x50);
RED4EXT_ASSERT_OFFSET(ScenesVersions, currentVersion, 0x3C);
RED4EXT_ASSERT_OFFSET(ScenesVersions, scenes, 0x40);
#else
RED4EXT_ASSERT_SIZE(ScenesVersions, 0x58);
#endif
} // namespace scn
using scnScenesVersions = scn::ScenesVersions;
} // namespace RED4ext

// clang-format on
