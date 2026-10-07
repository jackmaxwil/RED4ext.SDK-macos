#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/Containers/DynArray.hpp>
#include <RED4ext/Handle.hpp>
#include <RED4ext/NativeTypes.hpp>
#include <RED4ext/Scripting/Natives/Generated/world/ITriggerAreaNotifer.hpp>

namespace RED4ext
{
struct AreaShapeOutline;

namespace world
{
struct VehicleForbiddenAreaNotifier : world::ITriggerAreaNotifer
{
    static constexpr const char* NAME = "worldVehicleForbiddenAreaNotifier";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    uint8_t unkB2[0xC8 - 0xB2]; // B2
    bool innerAreaBoundToOuterArea; // C8
    uint8_t unkC9[0xD0 - 0xC9]; // C9
    Handle<AreaShapeOutline> innerAreaOutline; // D0
    DynArray<NodeRef> parkingSpots; // E0
    float innerAreaSpeedLimit; // F0
    float areaSpeedLimit; // F4
    bool enableNullArea; // F8
    bool dismount; // F9
    bool enableSummoning; // FA
    uint8_t unkFB[0x100 - 0xFB]; // FB
#else
    uint8_t unkB8[0xC8 - 0xB8]; // B8
    bool innerAreaBoundToOuterArea; // C8
    uint8_t unkC9[0xD0 - 0xC9]; // C9
    Handle<AreaShapeOutline> innerAreaOutline; // D0
    DynArray<NodeRef> parkingSpots; // E0
    float innerAreaSpeedLimit; // F0
    float areaSpeedLimit; // F4
    bool enableNullArea; // F8
    bool dismount; // F9
    bool enableSummoning; // FA
    uint8_t unkFB[0x100 - 0xFB]; // FB
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(VehicleForbiddenAreaNotifier, 0x100);
RED4EXT_ASSERT_OFFSET(VehicleForbiddenAreaNotifier, innerAreaBoundToOuterArea, 0xC8);
RED4EXT_ASSERT_OFFSET(VehicleForbiddenAreaNotifier, innerAreaOutline, 0xD0);
RED4EXT_ASSERT_OFFSET(VehicleForbiddenAreaNotifier, parkingSpots, 0xE0);
RED4EXT_ASSERT_OFFSET(VehicleForbiddenAreaNotifier, innerAreaSpeedLimit, 0xF0);
RED4EXT_ASSERT_OFFSET(VehicleForbiddenAreaNotifier, areaSpeedLimit, 0xF4);
RED4EXT_ASSERT_OFFSET(VehicleForbiddenAreaNotifier, enableNullArea, 0xF8);
RED4EXT_ASSERT_OFFSET(VehicleForbiddenAreaNotifier, dismount, 0xF9);
RED4EXT_ASSERT_OFFSET(VehicleForbiddenAreaNotifier, enableSummoning, 0xFA);
#else
RED4EXT_ASSERT_SIZE(VehicleForbiddenAreaNotifier, 0x100);
#endif
} // namespace world
using worldVehicleForbiddenAreaNotifier = world::VehicleForbiddenAreaNotifier;
} // namespace RED4ext

// clang-format on
