#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/DynArray.hpp>
#include <RED4ext/ISerializable.hpp>
#include <RED4ext/NativeTypes.hpp>
#include <RED4ext/Scripting/Natives/Generated/FunctionalTestsDataMemoryPoolRuntimeData.hpp>
#include <RED4ext/Scripting/Natives/Generated/FunctionalTestsDataMemoryPoolStaticData.hpp>

namespace RED4ext
{
struct FunctionalTestsDataMemoryStatsData : ISerializable
{
    static constexpr const char* NAME = "FunctionalTestsDataMemoryStatsData";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    uint64_t totalPhysicalMemory; // 30
    uint64_t availablePhysicalMemory; // 38
    uint64_t runtimeTotalBytesAllocated; // 40
    uint64_t cpuBytesAllocated; // 48
    uint64_t gpuBytesAllocated; // 50
    uint8_t unk58[0x68 - 0x58]; // 58
    uint32_t totalAllocationCount; // 68
    uint32_t cpuAllocationCount; // 6C
    uint32_t gpuAllocationCount; // 70
    uint8_t unk74[0x80 - 0x74]; // 74
    uint64_t engineTick; // 80
    float lastTimeDelta; // 88
    uint8_t unk8C[0x90 - 0x8C]; // 8C
    double engineTime; // 90
    uint64_t rawLocalTime; // 98
    CString playerPosition; // A0
    CString playerOrientation; // C0
    DynArray<FunctionalTestsDataMemoryPoolRuntimeData> poolsRuntimeInfo; // E0
    DynArray<FunctionalTestsDataMemoryPoolStaticData> poolsCurrentInfo; // F0
    uint8_t unk100[0x140 - 0x100]; // 100
#else
    uint8_t unk30[0x38 - 0x30]; // 30
    uint64_t totalPhysicalMemory; // 38
    uint64_t availablePhysicalMemory; // 40
    uint64_t runtimeTotalBytesAllocated; // 48
    uint64_t cpuBytesAllocated; // 50
    uint64_t gpuBytesAllocated; // 58
    uint8_t unk60[0x70 - 0x60]; // 60
    uint32_t totalAllocationCount; // 70
    uint32_t cpuAllocationCount; // 74
    uint32_t gpuAllocationCount; // 78
    uint8_t unk7C[0x80 - 0x7C]; // 7C
    uint64_t engineTick; // 80
    float lastTimeDelta; // 88
    uint8_t unk8C[0x90 - 0x8C]; // 8C
    double engineTime; // 90
    uint64_t rawLocalTime; // 98
    CString playerPosition; // A0
    CString playerOrientation; // C0
    DynArray<FunctionalTestsDataMemoryPoolRuntimeData> poolsRuntimeInfo; // E0
    DynArray<FunctionalTestsDataMemoryPoolStaticData> poolsCurrentInfo; // F0
    uint8_t unk100[0x140 - 0x100]; // 100
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(FunctionalTestsDataMemoryStatsData, 0x140);
RED4EXT_ASSERT_OFFSET(FunctionalTestsDataMemoryStatsData, totalPhysicalMemory, 0x30);
RED4EXT_ASSERT_OFFSET(FunctionalTestsDataMemoryStatsData, availablePhysicalMemory, 0x38);
RED4EXT_ASSERT_OFFSET(FunctionalTestsDataMemoryStatsData, runtimeTotalBytesAllocated, 0x40);
RED4EXT_ASSERT_OFFSET(FunctionalTestsDataMemoryStatsData, cpuBytesAllocated, 0x48);
RED4EXT_ASSERT_OFFSET(FunctionalTestsDataMemoryStatsData, gpuBytesAllocated, 0x50);
RED4EXT_ASSERT_OFFSET(FunctionalTestsDataMemoryStatsData, totalAllocationCount, 0x68);
RED4EXT_ASSERT_OFFSET(FunctionalTestsDataMemoryStatsData, cpuAllocationCount, 0x6C);
RED4EXT_ASSERT_OFFSET(FunctionalTestsDataMemoryStatsData, gpuAllocationCount, 0x70);
RED4EXT_ASSERT_OFFSET(FunctionalTestsDataMemoryStatsData, engineTick, 0x80);
RED4EXT_ASSERT_OFFSET(FunctionalTestsDataMemoryStatsData, lastTimeDelta, 0x88);
RED4EXT_ASSERT_OFFSET(FunctionalTestsDataMemoryStatsData, engineTime, 0x90);
RED4EXT_ASSERT_OFFSET(FunctionalTestsDataMemoryStatsData, rawLocalTime, 0x98);
RED4EXT_ASSERT_OFFSET(FunctionalTestsDataMemoryStatsData, playerPosition, 0xA0);
RED4EXT_ASSERT_OFFSET(FunctionalTestsDataMemoryStatsData, playerOrientation, 0xC0);
RED4EXT_ASSERT_OFFSET(FunctionalTestsDataMemoryStatsData, poolsRuntimeInfo, 0xE0);
RED4EXT_ASSERT_OFFSET(FunctionalTestsDataMemoryStatsData, poolsCurrentInfo, 0xF0);
#else
RED4EXT_ASSERT_SIZE(FunctionalTestsDataMemoryStatsData, 0x140);
#endif
} // namespace RED4ext

// clang-format on
