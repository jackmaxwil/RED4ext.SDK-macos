#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/CName.hpp>
#include <RED4ext/NativeTypes.hpp>
#include <RED4ext/Scripting/IScriptable.hpp>

namespace RED4ext
{
namespace world
{
struct BenchmarkSummary : IScriptable
{
    static constexpr const char* NAME = "worldBenchmarkSummary";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    CString gameVersion; // 40
    CString benchmarkName; // 60
    CString gpuName; // 80
    uint64_t gpuMemory; // A0
    CString gpuDriverVersion; // A8
    CString cpuName; // C8
    uint64_t systemMemory; // E8
    CString osName; // F0
    CString osVersion; // 110
    uint8_t unk130[0x150 - 0x130]; // 130
    CString presetName; // 150
    CName presetLocalizedName; // 170
    CName textureQualityPresetLocalizedName; // 178
    uint32_t renderWidth; // 180
    uint32_t renderHeight; // 184
    uint8_t windowMode; // 188
    bool verticalSync; // 189
    uint8_t unk18A[0x18C - 0x18A]; // 18A
    int32_t fpsClamp; // 18C
    float averageFps; // 190
    float minFps; // 194
    float maxFps; // 198
    float time; // 19C
    uint32_t frameNumber; // 1A0
    uint8_t upscalingType; // 1A4
    uint8_t frameGenerationType; // 1A5
    bool DLAAEnabled; // 1A6
    uint8_t unk1A7[0x1A8 - 0x1A7]; // 1A7
    float DLAASharpness; // 1A8
    bool DLSSEnabled; // 1AC
    uint8_t unk1AD[0x1B0 - 0x1AD]; // 1AD
    int32_t DLSSPreset; // 1B0
    bool DLSSDEnabled; // 1B4
    uint8_t unk1B5[0x1B8 - 0x1B5]; // 1B5
    int32_t DLSSQuality; // 1B8
    float DLSSSharpness; // 1BC
    bool DLSSFrameGenEnabled; // 1C0
    bool DLSSMultiFrameGenEnabled; // 1C1
    uint8_t unk1C2[0x1C4 - 0x1C2]; // 1C2
    int32_t DLSSMultiFrameGenFrameToGenerate; // 1C4
    bool FSR2Enabled; // 1C8
    uint8_t unk1C9[0x1CC - 0x1C9]; // 1C9
    int32_t FSR2Quality; // 1CC
    float FSR2Sharpness; // 1D0
    bool FSR3Enabled; // 1D4
    uint8_t unk1D5[0x1D8 - 0x1D5]; // 1D5
    int32_t FSR3Quality; // 1D8
    float FSR3Sharpness; // 1DC
    bool FSR3FrameGenEnabled; // 1E0
    bool FSR4Enabled; // 1E1
    uint8_t unk1E2[0x1E4 - 0x1E2]; // 1E2
    int32_t FSR4Quality; // 1E4
    float FSR4Sharpness; // 1E8
    bool XeSSEnabled; // 1EC
    uint8_t unk1ED[0x1F0 - 0x1ED]; // 1ED
    int32_t XeSSQuality; // 1F0
    float XeSSSharpness; // 1F4
    bool XeSSFrameGenEnabled; // 1F8
    uint8_t unk1F9[0x204 - 0x1F9]; // 1F9
    bool DRSEnabled; // 204
    uint8_t unk205[0x208 - 0x205]; // 205
    uint32_t DRSTargetFPS; // 208
    uint32_t DRSMinimalResolutionPercentage; // 20C
    uint32_t DRSMaximalResolutionPercentage; // 210
    bool CASSharpeningEnabled; // 214
    bool FSREnabled; // 215
    uint8_t unk216[0x218 - 0x216]; // 216
    int32_t FSRQuality; // 218
    bool rayTracingEnabled; // 21C
    bool rayTracedReflections; // 21D
    bool rayTracedSunShadows; // 21E
    bool rayTracedLocalShadows; // 21F
    int32_t rayTracedLightingQuality; // 220
    bool rayTracedPathTracingEnabled; // 224
    uint8_t unk225[0x228 - 0x225]; // 225
#else
    CString gameVersion; // 40
    CString benchmarkName; // 60
    CString gpuName; // 80
    uint64_t gpuMemory; // A0
    CString gpuDriverVersion; // A8
    CString cpuName; // C8
    uint64_t systemMemory; // E8
    CString osName; // F0
    CString osVersion; // 110
    CString presetName; // 130
    CName presetLocalizedName; // 150
    CName textureQualityPresetLocalizedName; // 158
    uint32_t renderWidth; // 160
    uint32_t renderHeight; // 164
    uint8_t windowMode; // 168
    bool verticalSync; // 169
    uint8_t unk16A[0x16C - 0x16A]; // 16A
    int32_t fpsClamp; // 16C
    float averageFps; // 170
    float minFps; // 174
    float maxFps; // 178
    float time; // 17C
    uint32_t frameNumber; // 180
    uint8_t upscalingType; // 184
    uint8_t frameGenerationType; // 185
    bool DLAAEnabled; // 186
    uint8_t unk187[0x188 - 0x187]; // 187
    float DLAASharpness; // 188
    bool DLSSEnabled; // 18C
    uint8_t unk18D[0x190 - 0x18D]; // 18D
    int32_t DLSSPreset; // 190
    bool DLSSDEnabled; // 194
    uint8_t unk195[0x198 - 0x195]; // 195
    int32_t DLSSQuality; // 198
    float DLSSSharpness; // 19C
    bool DLSSFrameGenEnabled; // 1A0
    bool DLSSMultiFrameGenEnabled; // 1A1
    uint8_t unk1A2[0x1A4 - 0x1A2]; // 1A2
    int32_t DLSSMultiFrameGenFrameToGenerate; // 1A4
    bool FSR2Enabled; // 1A8
    uint8_t unk1A9[0x1AC - 0x1A9]; // 1A9
    int32_t FSR2Quality; // 1AC
    float FSR2Sharpness; // 1B0
    bool FSR3Enabled; // 1B4
    uint8_t unk1B5[0x1B8 - 0x1B5]; // 1B5
    int32_t FSR3Quality; // 1B8
    float FSR3Sharpness; // 1BC
    bool FSR3FrameGenEnabled; // 1C0
    bool FSR4Enabled; // 1C1
    uint8_t unk1C2[0x1C4 - 0x1C2]; // 1C2
    int32_t FSR4Quality; // 1C4
    float FSR4Sharpness; // 1C8
    bool XeSSEnabled; // 1CC
    uint8_t unk1CD[0x1D0 - 0x1CD]; // 1CD
    int32_t XeSSQuality; // 1D0
    float XeSSSharpness; // 1D4
    bool XeSSFrameGenEnabled; // 1D8
    bool DRSEnabled; // 1D9
    uint8_t unk1DA[0x1DC - 0x1DA]; // 1DA
    uint32_t DRSTargetFPS; // 1DC
    uint32_t DRSMinimalResolutionPercentage; // 1E0
    uint32_t DRSMaximalResolutionPercentage; // 1E4
    bool CASSharpeningEnabled; // 1E8
    bool FSREnabled; // 1E9
    uint8_t unk1EA[0x1EC - 0x1EA]; // 1EA
    int32_t FSRQuality; // 1EC
    bool rayTracingEnabled; // 1F0
    bool rayTracedReflections; // 1F1
    bool rayTracedSunShadows; // 1F2
    bool rayTracedLocalShadows; // 1F3
    int32_t rayTracedLightingQuality; // 1F4
    bool rayTracedPathTracingEnabled; // 1F8
    uint8_t unk1F9[0x200 - 0x1F9]; // 1F9
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(BenchmarkSummary, 0x228);
RED4EXT_ASSERT_OFFSET(BenchmarkSummary, gameVersion, 0x40);
RED4EXT_ASSERT_OFFSET(BenchmarkSummary, benchmarkName, 0x60);
RED4EXT_ASSERT_OFFSET(BenchmarkSummary, gpuName, 0x80);
RED4EXT_ASSERT_OFFSET(BenchmarkSummary, gpuMemory, 0xA0);
RED4EXT_ASSERT_OFFSET(BenchmarkSummary, gpuDriverVersion, 0xA8);
RED4EXT_ASSERT_OFFSET(BenchmarkSummary, cpuName, 0xC8);
RED4EXT_ASSERT_OFFSET(BenchmarkSummary, systemMemory, 0xE8);
RED4EXT_ASSERT_OFFSET(BenchmarkSummary, osName, 0xF0);
RED4EXT_ASSERT_OFFSET(BenchmarkSummary, osVersion, 0x110);
RED4EXT_ASSERT_OFFSET(BenchmarkSummary, presetName, 0x150);
RED4EXT_ASSERT_OFFSET(BenchmarkSummary, presetLocalizedName, 0x170);
RED4EXT_ASSERT_OFFSET(BenchmarkSummary, textureQualityPresetLocalizedName, 0x178);
RED4EXT_ASSERT_OFFSET(BenchmarkSummary, renderWidth, 0x180);
RED4EXT_ASSERT_OFFSET(BenchmarkSummary, renderHeight, 0x184);
RED4EXT_ASSERT_OFFSET(BenchmarkSummary, windowMode, 0x188);
RED4EXT_ASSERT_OFFSET(BenchmarkSummary, verticalSync, 0x189);
RED4EXT_ASSERT_OFFSET(BenchmarkSummary, fpsClamp, 0x18C);
RED4EXT_ASSERT_OFFSET(BenchmarkSummary, averageFps, 0x190);
RED4EXT_ASSERT_OFFSET(BenchmarkSummary, minFps, 0x194);
RED4EXT_ASSERT_OFFSET(BenchmarkSummary, maxFps, 0x198);
RED4EXT_ASSERT_OFFSET(BenchmarkSummary, time, 0x19C);
RED4EXT_ASSERT_OFFSET(BenchmarkSummary, frameNumber, 0x1A0);
RED4EXT_ASSERT_OFFSET(BenchmarkSummary, upscalingType, 0x1A4);
RED4EXT_ASSERT_OFFSET(BenchmarkSummary, frameGenerationType, 0x1A5);
RED4EXT_ASSERT_OFFSET(BenchmarkSummary, DLAAEnabled, 0x1A6);
RED4EXT_ASSERT_OFFSET(BenchmarkSummary, DLAASharpness, 0x1A8);
RED4EXT_ASSERT_OFFSET(BenchmarkSummary, DLSSEnabled, 0x1AC);
RED4EXT_ASSERT_OFFSET(BenchmarkSummary, DLSSPreset, 0x1B0);
RED4EXT_ASSERT_OFFSET(BenchmarkSummary, DLSSDEnabled, 0x1B4);
RED4EXT_ASSERT_OFFSET(BenchmarkSummary, DLSSQuality, 0x1B8);
RED4EXT_ASSERT_OFFSET(BenchmarkSummary, DLSSSharpness, 0x1BC);
RED4EXT_ASSERT_OFFSET(BenchmarkSummary, DLSSFrameGenEnabled, 0x1C0);
RED4EXT_ASSERT_OFFSET(BenchmarkSummary, DLSSMultiFrameGenEnabled, 0x1C1);
RED4EXT_ASSERT_OFFSET(BenchmarkSummary, DLSSMultiFrameGenFrameToGenerate, 0x1C4);
RED4EXT_ASSERT_OFFSET(BenchmarkSummary, FSR2Enabled, 0x1C8);
RED4EXT_ASSERT_OFFSET(BenchmarkSummary, FSR2Quality, 0x1CC);
RED4EXT_ASSERT_OFFSET(BenchmarkSummary, FSR2Sharpness, 0x1D0);
RED4EXT_ASSERT_OFFSET(BenchmarkSummary, FSR3Enabled, 0x1D4);
RED4EXT_ASSERT_OFFSET(BenchmarkSummary, FSR3Quality, 0x1D8);
RED4EXT_ASSERT_OFFSET(BenchmarkSummary, FSR3Sharpness, 0x1DC);
RED4EXT_ASSERT_OFFSET(BenchmarkSummary, FSR3FrameGenEnabled, 0x1E0);
RED4EXT_ASSERT_OFFSET(BenchmarkSummary, FSR4Enabled, 0x1E1);
RED4EXT_ASSERT_OFFSET(BenchmarkSummary, FSR4Quality, 0x1E4);
RED4EXT_ASSERT_OFFSET(BenchmarkSummary, FSR4Sharpness, 0x1E8);
RED4EXT_ASSERT_OFFSET(BenchmarkSummary, XeSSEnabled, 0x1EC);
RED4EXT_ASSERT_OFFSET(BenchmarkSummary, XeSSQuality, 0x1F0);
RED4EXT_ASSERT_OFFSET(BenchmarkSummary, XeSSSharpness, 0x1F4);
RED4EXT_ASSERT_OFFSET(BenchmarkSummary, XeSSFrameGenEnabled, 0x1F8);
RED4EXT_ASSERT_OFFSET(BenchmarkSummary, DRSEnabled, 0x204);
RED4EXT_ASSERT_OFFSET(BenchmarkSummary, DRSTargetFPS, 0x208);
RED4EXT_ASSERT_OFFSET(BenchmarkSummary, DRSMinimalResolutionPercentage, 0x20C);
RED4EXT_ASSERT_OFFSET(BenchmarkSummary, DRSMaximalResolutionPercentage, 0x210);
RED4EXT_ASSERT_OFFSET(BenchmarkSummary, CASSharpeningEnabled, 0x214);
RED4EXT_ASSERT_OFFSET(BenchmarkSummary, FSREnabled, 0x215);
RED4EXT_ASSERT_OFFSET(BenchmarkSummary, FSRQuality, 0x218);
RED4EXT_ASSERT_OFFSET(BenchmarkSummary, rayTracingEnabled, 0x21C);
RED4EXT_ASSERT_OFFSET(BenchmarkSummary, rayTracedReflections, 0x21D);
RED4EXT_ASSERT_OFFSET(BenchmarkSummary, rayTracedSunShadows, 0x21E);
RED4EXT_ASSERT_OFFSET(BenchmarkSummary, rayTracedLocalShadows, 0x21F);
RED4EXT_ASSERT_OFFSET(BenchmarkSummary, rayTracedLightingQuality, 0x220);
RED4EXT_ASSERT_OFFSET(BenchmarkSummary, rayTracedPathTracingEnabled, 0x224);
#else
RED4EXT_ASSERT_SIZE(BenchmarkSummary, 0x200);
#endif
} // namespace world
using worldBenchmarkSummary = world::BenchmarkSummary;
} // namespace RED4ext

// clang-format on
