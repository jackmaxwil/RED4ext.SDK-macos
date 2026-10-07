#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/Scripting/Natives/Generated/game/data/VehicleDriveModelData_Record.hpp>

namespace RED4ext
{
namespace game::data
{
struct BikeDriveModelData_Record : game::data::VehicleDriveModelData_Record
{
    static constexpr const char* NAME = "gamedataBikeDriveModelData_Record";
    static constexpr const char* ALIAS = "BikeDriveModelData_Record";

#ifdef __APPLE__
    uint8_t unk2C8[0x330 - 0x2C8]; // 2C8
#else
    uint8_t unk2C8[0x338 - 0x2C8]; // 2C8
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(BikeDriveModelData_Record, 0x330);
#else
RED4EXT_ASSERT_SIZE(BikeDriveModelData_Record, 0x338);
#endif
} // namespace game::data
using gamedataBikeDriveModelData_Record = game::data::BikeDriveModelData_Record;
using BikeDriveModelData_Record = game::data::BikeDriveModelData_Record;
} // namespace RED4ext

// clang-format on
