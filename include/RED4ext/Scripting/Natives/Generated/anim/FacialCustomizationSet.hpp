#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/DynArray.hpp>
#include <RED4ext/NativeTypes.hpp>
#include <RED4ext/Scripting/Natives/Generated/CResource.hpp>
#include <RED4ext/Scripting/Natives/Generated/anim/FacialCustomizationTargetEntryTemp.hpp>
#include <RED4ext/Scripting/Natives/Generated/anim/FacialSetup_PosesBufferInfo.hpp>

namespace RED4ext
{
namespace anim { struct FacialSetup; }

namespace anim
{
struct FacialCustomizationSet : CResource
{
    static constexpr const char* NAME = "animFacialCustomizationSet";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    uint8_t unk39[0x40 - 0x39]; // 39
    Ref<anim::FacialSetup> baseSetup; // 40
    DynArray<RaRef<anim::FacialSetup>> targetSetups; // 58
    DynArray<anim::FacialCustomizationTargetEntryTemp> targetSetupsTemp; // 68
    uint32_t numTargets; // 78
    bool isCooked; // 7C
    uint8_t unk7D[0x88 - 0x7D]; // 7D
    anim::FacialSetup_PosesBufferInfo posesInfo; // 88
    uint8_t unkC4[0xC8 - 0xC4]; // C4
    DynArray<uint8_t> jointRegions; // C8
    DataBuffer mainPosesData; // D8
    DataBuffer correctivePosesData; // 100
    DynArray<uint16_t> usedTransformIndices; // 128
    uint8_t unk138[0x268 - 0x138]; // 138
    uint32_t numJoints; // 268
    uint8_t unk26C[0x270 - 0x26C]; // 26C
    DataBuffer rigReferencePosesData; // 270
    uint8_t unk298[0x2A8 - 0x298]; // 298
#else
    Ref<anim::FacialSetup> baseSetup; // 40
    DynArray<RaRef<anim::FacialSetup>> targetSetups; // 58
    DynArray<anim::FacialCustomizationTargetEntryTemp> targetSetupsTemp; // 68
    uint32_t numTargets; // 78
    bool isCooked; // 7C
    uint8_t unk7D[0x88 - 0x7D]; // 7D
    anim::FacialSetup_PosesBufferInfo posesInfo; // 88
    uint8_t unkC4[0xC8 - 0xC4]; // C4
    DynArray<uint8_t> jointRegions; // C8
    DataBuffer mainPosesData; // D8
    DataBuffer correctivePosesData; // 100
    DynArray<uint16_t> usedTransformIndices; // 128
    uint8_t unk138[0x268 - 0x138]; // 138
    uint32_t numJoints; // 268
    uint8_t unk26C[0x270 - 0x26C]; // 26C
    DataBuffer rigReferencePosesData; // 270
    uint8_t unk298[0x2A8 - 0x298]; // 298
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(FacialCustomizationSet, 0x2A8);
RED4EXT_ASSERT_OFFSET(FacialCustomizationSet, baseSetup, 0x40);
RED4EXT_ASSERT_OFFSET(FacialCustomizationSet, targetSetups, 0x58);
RED4EXT_ASSERT_OFFSET(FacialCustomizationSet, targetSetupsTemp, 0x68);
RED4EXT_ASSERT_OFFSET(FacialCustomizationSet, numTargets, 0x78);
RED4EXT_ASSERT_OFFSET(FacialCustomizationSet, isCooked, 0x7C);
RED4EXT_ASSERT_OFFSET(FacialCustomizationSet, posesInfo, 0x88);
RED4EXT_ASSERT_OFFSET(FacialCustomizationSet, jointRegions, 0xC8);
RED4EXT_ASSERT_OFFSET(FacialCustomizationSet, mainPosesData, 0xD8);
RED4EXT_ASSERT_OFFSET(FacialCustomizationSet, correctivePosesData, 0x100);
RED4EXT_ASSERT_OFFSET(FacialCustomizationSet, usedTransformIndices, 0x128);
RED4EXT_ASSERT_OFFSET(FacialCustomizationSet, numJoints, 0x268);
RED4EXT_ASSERT_OFFSET(FacialCustomizationSet, rigReferencePosesData, 0x270);
#else
RED4EXT_ASSERT_SIZE(FacialCustomizationSet, 0x2A8);
#endif
} // namespace anim
using animFacialCustomizationSet = anim::FacialCustomizationSet;
} // namespace RED4ext

// clang-format on
