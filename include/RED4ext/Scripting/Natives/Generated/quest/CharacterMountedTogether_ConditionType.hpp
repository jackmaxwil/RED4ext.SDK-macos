#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/Containers/DynArray.hpp>
#include <RED4ext/Handle.hpp>
#include <RED4ext/Scripting/Natives/Generated/quest/ICharacterConditionType.hpp>
#include <RED4ext/Scripting/Natives/Generated/quest/MountVehicleOrigin.hpp>
#include <RED4ext/Scripting/Natives/Generated/quest/MountVehicleType.hpp>

namespace RED4ext
{
namespace quest { struct MountedObjectInfo; }

namespace quest
{
struct CharacterMountedTogether_ConditionType : quest::ICharacterConditionType
{
    static constexpr const char* NAME = "questCharacterMountedTogether_ConditionType";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    uint8_t unk71[0x78 - 0x71]; // 71
    DynArray<Handle<quest::MountedObjectInfo>> characters; // 78
    uint8_t unk88[0x8C - 0x88]; // 88
    quest::MountVehicleType vehicleType; // 8C
    quest::MountVehicleOrigin vehicleOrigin; // 90
    uint8_t unk94[0x98 - 0x94]; // 94
#else
    DynArray<Handle<quest::MountedObjectInfo>> characters; // 78
    uint8_t unk88[0x8C - 0x88]; // 88
    quest::MountVehicleType vehicleType; // 8C
    quest::MountVehicleOrigin vehicleOrigin; // 90
    uint8_t unk94[0x98 - 0x94]; // 94
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(CharacterMountedTogether_ConditionType, 0x98);
RED4EXT_ASSERT_OFFSET(CharacterMountedTogether_ConditionType, characters, 0x78);
RED4EXT_ASSERT_OFFSET(CharacterMountedTogether_ConditionType, vehicleType, 0x8C);
RED4EXT_ASSERT_OFFSET(CharacterMountedTogether_ConditionType, vehicleOrigin, 0x90);
#else
RED4EXT_ASSERT_SIZE(CharacterMountedTogether_ConditionType, 0x98);
#endif
} // namespace quest
using questCharacterMountedTogether_ConditionType = quest::CharacterMountedTogether_ConditionType;
} // namespace RED4ext

// clang-format on
