#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/DynArray.hpp>
#include <RED4ext/Scripting/Natives/Generated/CResource.hpp>
#include <RED4ext/Scripting/Natives/Generated/MaterialLayerDef.hpp>
#include <RED4ext/Scripting/Natives/Generated/MicroblendDef.hpp>

namespace RED4ext
{
struct CMaterialLayerLibrary : CResource
{
    static constexpr const char* NAME = "CMaterialLayerLibrary";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    uint8_t unk39[0x3C - 0x39]; // 39
    float uvTiling; // 3C
    float mbTiling; // 40
    float microblendContrast; // 44
    uint8_t unk48[0x4C - 0x48]; // 48
    uint32_t paletteColorIndex; // 4C
    DynArray<MaterialLayerDef> layers; // 50
    DynArray<MicroblendDef> microblends; // 60
#else
    float uvTiling; // 40
    float mbTiling; // 44
    float microblendContrast; // 48
    uint8_t unk4C[0x50 - 0x4C]; // 4C
    uint32_t paletteColorIndex; // 50
    uint8_t unk54[0x58 - 0x54]; // 54
    DynArray<MaterialLayerDef> layers; // 58
    DynArray<MicroblendDef> microblends; // 68
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(CMaterialLayerLibrary, 0x70);
RED4EXT_ASSERT_OFFSET(CMaterialLayerLibrary, uvTiling, 0x3C);
RED4EXT_ASSERT_OFFSET(CMaterialLayerLibrary, mbTiling, 0x40);
RED4EXT_ASSERT_OFFSET(CMaterialLayerLibrary, microblendContrast, 0x44);
RED4EXT_ASSERT_OFFSET(CMaterialLayerLibrary, paletteColorIndex, 0x4C);
RED4EXT_ASSERT_OFFSET(CMaterialLayerLibrary, layers, 0x50);
RED4EXT_ASSERT_OFFSET(CMaterialLayerLibrary, microblends, 0x60);
#else
RED4EXT_ASSERT_SIZE(CMaterialLayerLibrary, 0x78);
#endif
} // namespace RED4ext

// clang-format on
