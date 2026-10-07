#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/Containers/DynArray.hpp>
#include <RED4ext/Scripting/Natives/Generated/CResource.hpp>
#include <RED4ext/Scripting/Natives/Generated/game/CookedGpsMappinData.hpp>
#include <RED4ext/Scripting/Natives/Generated/game/CookedMappinData.hpp>
#include <RED4ext/Scripting/Natives/Generated/game/CookedMultiMappinData.hpp>

namespace RED4ext
{
namespace game
{
struct MappinResource : CResource
{
    static constexpr const char* NAME = "gameMappinResource";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    uint8_t unk39[0x40 - 0x39]; // 39
    DynArray<game::CookedMappinData> cookedData; // 40
    DynArray<game::CookedMultiMappinData> cookedMultiData; // 50
    DynArray<game::CookedGpsMappinData> cookedGpsData; // 60
#else
    DynArray<game::CookedMappinData> cookedData; // 40
    DynArray<game::CookedMultiMappinData> cookedMultiData; // 50
    DynArray<game::CookedGpsMappinData> cookedGpsData; // 60
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(MappinResource, 0x70);
RED4EXT_ASSERT_OFFSET(MappinResource, cookedData, 0x40);
RED4EXT_ASSERT_OFFSET(MappinResource, cookedMultiData, 0x50);
RED4EXT_ASSERT_OFFSET(MappinResource, cookedGpsData, 0x60);
#else
RED4EXT_ASSERT_SIZE(MappinResource, 0x70);
#endif
} // namespace game
using gameMappinResource = game::MappinResource;
} // namespace RED4ext

// clang-format on
