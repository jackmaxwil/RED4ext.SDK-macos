#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/DynArray.hpp>
#include <RED4ext/Scripting/Natives/Generated/CResource.hpp>
#include <RED4ext/Scripting/Natives/Generated/game/CookedPointOfInterestMappinData.hpp>

namespace RED4ext
{
namespace game
{
struct PointOfInterestMappinResource : CResource
{
    static constexpr const char* NAME = "gamePointOfInterestMappinResource";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    uint8_t unk39[0x40 - 0x39]; // 39
    DynArray<game::CookedPointOfInterestMappinData> cookedData; // 40
#else
    DynArray<game::CookedPointOfInterestMappinData> cookedData; // 40
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(PointOfInterestMappinResource, 0x50);
RED4EXT_ASSERT_OFFSET(PointOfInterestMappinResource, cookedData, 0x40);
#else
RED4EXT_ASSERT_SIZE(PointOfInterestMappinResource, 0x50);
#endif
} // namespace game
using gamePointOfInterestMappinResource = game::PointOfInterestMappinResource;
} // namespace RED4ext

// clang-format on
