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

namespace world
{
struct CookedPrefabData : CResource
{
    static constexpr const char* NAME = "worldCookedPrefabData";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    uint8_t unk39[0x40 - 0x39]; // 39
    DynArray<RaRef<CResource>> precookedDependencies; // 40
    DynArray<Ref<CResource>> dependencies; // 50
    uint8_t unk60[0x70 - 0x60]; // 60
#else
    DynArray<RaRef<CResource>> precookedDependencies; // 40
    DynArray<Ref<CResource>> dependencies; // 50
    uint8_t unk60[0x70 - 0x60]; // 60
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(CookedPrefabData, 0x70);
RED4EXT_ASSERT_OFFSET(CookedPrefabData, precookedDependencies, 0x40);
RED4EXT_ASSERT_OFFSET(CookedPrefabData, dependencies, 0x50);
#else
RED4EXT_ASSERT_SIZE(CookedPrefabData, 0x70);
#endif
} // namespace world
using worldCookedPrefabData = world::CookedPrefabData;
} // namespace RED4ext

// clang-format on
