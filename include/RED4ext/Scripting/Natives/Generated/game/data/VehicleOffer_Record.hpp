#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/Scripting/Natives/Generated/game/data/PurchaseOffer_Record.hpp>

namespace RED4ext
{
namespace game::data
{
struct VehicleOffer_Record : game::data::PurchaseOffer_Record
{
    static constexpr const char* NAME = "gamedataVehicleOffer_Record";
    static constexpr const char* ALIAS = "VehicleOffer_Record";

#ifdef __APPLE__
    uint8_t unk70[0xD8 - 0x70]; // 70
#else
    uint8_t unk70[0xE0 - 0x70]; // 70
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(VehicleOffer_Record, 0xD8);
#else
RED4EXT_ASSERT_SIZE(VehicleOffer_Record, 0xE0);
#endif
} // namespace game::data
using gamedataVehicleOffer_Record = game::data::VehicleOffer_Record;
using VehicleOffer_Record = game::data::VehicleOffer_Record;
} // namespace RED4ext

// clang-format on
