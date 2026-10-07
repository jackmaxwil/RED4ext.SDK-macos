#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/NativeTypes.hpp>
#include <RED4ext/Scripting/Natives/Generated/CResource.hpp>
#include <RED4ext/Scripting/Natives/Generated/Vector2.hpp>
#include <RED4ext/Scripting/Natives/Generated/Vector3.hpp>

namespace RED4ext
{
namespace minimap
{
struct EncodedShapes : CResource
{
    static constexpr const char* NAME = "minimapEncodedShapes";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    uint8_t unk39[0x40 - 0x39]; // 39
    DataBuffer Buffer; // 40
    Vector2 QuantizationScale; // 68
    Vector2 QuantizationBias; // 70
    Vector3 BoxQuantizationScale; // 78
    Vector3 BoxQuantizationBias; // 84
    uint32_t NumPoints; // 90
    uint32_t NumBorderPoints; // 94
    uint32_t NumFillPoints; // 98
    uint32_t NumShapes; // 9C
    uint32_t NumSpatialBuckets; // A0
    uint32_t NumUniqueGeometry; // A4
    uint32_t NumOwners; // A8
    uint32_t Version; // AC
#else
    DataBuffer Buffer; // 40
    Vector2 QuantizationScale; // 68
    Vector2 QuantizationBias; // 70
    Vector3 BoxQuantizationScale; // 78
    Vector3 BoxQuantizationBias; // 84
    uint32_t NumPoints; // 90
    uint32_t NumBorderPoints; // 94
    uint32_t NumFillPoints; // 98
    uint32_t NumShapes; // 9C
    uint32_t NumSpatialBuckets; // A0
    uint32_t NumUniqueGeometry; // A4
    uint32_t NumOwners; // A8
    uint32_t Version; // AC
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(EncodedShapes, 0xB0);
RED4EXT_ASSERT_OFFSET(EncodedShapes, Buffer, 0x40);
RED4EXT_ASSERT_OFFSET(EncodedShapes, QuantizationScale, 0x68);
RED4EXT_ASSERT_OFFSET(EncodedShapes, QuantizationBias, 0x70);
RED4EXT_ASSERT_OFFSET(EncodedShapes, BoxQuantizationScale, 0x78);
RED4EXT_ASSERT_OFFSET(EncodedShapes, BoxQuantizationBias, 0x84);
RED4EXT_ASSERT_OFFSET(EncodedShapes, NumPoints, 0x90);
RED4EXT_ASSERT_OFFSET(EncodedShapes, NumBorderPoints, 0x94);
RED4EXT_ASSERT_OFFSET(EncodedShapes, NumFillPoints, 0x98);
RED4EXT_ASSERT_OFFSET(EncodedShapes, NumShapes, 0x9C);
RED4EXT_ASSERT_OFFSET(EncodedShapes, NumSpatialBuckets, 0xA0);
RED4EXT_ASSERT_OFFSET(EncodedShapes, NumUniqueGeometry, 0xA4);
RED4EXT_ASSERT_OFFSET(EncodedShapes, NumOwners, 0xA8);
RED4EXT_ASSERT_OFFSET(EncodedShapes, Version, 0xAC);
#else
RED4EXT_ASSERT_SIZE(EncodedShapes, 0xB0);
#endif
} // namespace minimap
using minimapEncodedShapes = minimap::EncodedShapes;
} // namespace RED4ext

// clang-format on
