#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/CName.hpp>
#include <RED4ext/DynArray.hpp>
#include <RED4ext/Scripting/Natives/Generated/anim/AnimNode_BlendSpace_InternalsBlendSpaceCoordinateDescription.hpp>
#include <RED4ext/Scripting/Natives/Generated/anim/AnimNode_BlendSpace_InternalsBlendSpacePoint.hpp>

namespace RED4ext
{
namespace anim
{
struct AnimNode_BlendSpace_InternalsBlendSpace
{
    static constexpr const char* NAME = "animAnimNode_BlendSpace_InternalsBlendSpace";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    uint32_t spaceDimension; // 00
    uint8_t unk04[0x8 - 0x4]; // 4
    DynArray<anim::AnimNode_BlendSpace_InternalsBlendSpaceCoordinateDescription> coordinatesDescriptions; // 08
    DynArray<anim::AnimNode_BlendSpace_InternalsBlendSpacePoint> spacePoints; // 18
    uint32_t boundaryPointsCount; // 28
    bool fireAnimEndEvent; // 2C
    uint8_t unk2D[0x30 - 0x2D]; // 2D
    CName animEndEventName; // 30
    bool isLooped; // 38
    bool needsRuntimeTriangulation; // 39
    bool wasRuntimeTriangulationResaveDone; // 3A
    uint8_t unk3B[0xA0 - 0x3B]; // 3B
    DynArray<float> cachedSpacePoints_coordinates; // A0
    uint8_t unkB0[0xC0 - 0xB0]; // B0
    DynArray<uint32_t> cachedSpaceSimplexes_pointsIndices; // C0
    uint8_t unkD0[0xE0 - 0xD0]; // D0
    DynArray<int32_t> cachedSamplesForGridPoints_simplexIndex; // E0
    uint8_t unkF0[0x100 - 0xF0]; // F0
    DynArray<float> cachedSamplesForGridPoints_weightsForPoints; // 100
    uint8_t unk110[0x170 - 0x110]; // 110
#else
    uint32_t spaceDimension; // 00
    uint8_t unk04[0x8 - 0x4]; // 4
    DynArray<anim::AnimNode_BlendSpace_InternalsBlendSpaceCoordinateDescription> coordinatesDescriptions; // 08
    DynArray<anim::AnimNode_BlendSpace_InternalsBlendSpacePoint> spacePoints; // 18
    uint32_t boundaryPointsCount; // 28
    bool fireAnimEndEvent; // 2C
    uint8_t unk2D[0x30 - 0x2D]; // 2D
    CName animEndEventName; // 30
    bool isLooped; // 38
    bool needsRuntimeTriangulation; // 39
    bool wasRuntimeTriangulationResaveDone; // 3A
    uint8_t unk3B[0xB8 - 0x3B]; // 3B
    DynArray<float> cachedSpacePoints_coordinates; // B8
    uint8_t unkC8[0xE0 - 0xC8]; // C8
    DynArray<uint32_t> cachedSpaceSimplexes_pointsIndices; // E0
    uint8_t unkF0[0x108 - 0xF0]; // F0
    DynArray<int32_t> cachedSamplesForGridPoints_simplexIndex; // 108
    uint8_t unk118[0x130 - 0x118]; // 118
    DynArray<float> cachedSamplesForGridPoints_weightsForPoints; // 130
    uint8_t unk140[0x1C8 - 0x140]; // 140
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(AnimNode_BlendSpace_InternalsBlendSpace, 0x170);
RED4EXT_ASSERT_OFFSET(AnimNode_BlendSpace_InternalsBlendSpace, spaceDimension, 0x0);
RED4EXT_ASSERT_OFFSET(AnimNode_BlendSpace_InternalsBlendSpace, coordinatesDescriptions, 0x8);
RED4EXT_ASSERT_OFFSET(AnimNode_BlendSpace_InternalsBlendSpace, spacePoints, 0x18);
RED4EXT_ASSERT_OFFSET(AnimNode_BlendSpace_InternalsBlendSpace, boundaryPointsCount, 0x28);
RED4EXT_ASSERT_OFFSET(AnimNode_BlendSpace_InternalsBlendSpace, fireAnimEndEvent, 0x2C);
RED4EXT_ASSERT_OFFSET(AnimNode_BlendSpace_InternalsBlendSpace, animEndEventName, 0x30);
RED4EXT_ASSERT_OFFSET(AnimNode_BlendSpace_InternalsBlendSpace, isLooped, 0x38);
RED4EXT_ASSERT_OFFSET(AnimNode_BlendSpace_InternalsBlendSpace, needsRuntimeTriangulation, 0x39);
RED4EXT_ASSERT_OFFSET(AnimNode_BlendSpace_InternalsBlendSpace, wasRuntimeTriangulationResaveDone, 0x3A);
RED4EXT_ASSERT_OFFSET(AnimNode_BlendSpace_InternalsBlendSpace, cachedSpacePoints_coordinates, 0xA0);
RED4EXT_ASSERT_OFFSET(AnimNode_BlendSpace_InternalsBlendSpace, cachedSpaceSimplexes_pointsIndices, 0xC0);
RED4EXT_ASSERT_OFFSET(AnimNode_BlendSpace_InternalsBlendSpace, cachedSamplesForGridPoints_simplexIndex, 0xE0);
RED4EXT_ASSERT_OFFSET(AnimNode_BlendSpace_InternalsBlendSpace, cachedSamplesForGridPoints_weightsForPoints, 0x100);
#else
RED4EXT_ASSERT_SIZE(AnimNode_BlendSpace_InternalsBlendSpace, 0x1C8);
#endif
} // namespace anim
using animAnimNode_BlendSpace_InternalsBlendSpace = anim::AnimNode_BlendSpace_InternalsBlendSpace;
} // namespace RED4ext

// clang-format on
