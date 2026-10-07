#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/Scripting/Natives/Generated/CResource.hpp>
#include <RED4ext/Scripting/Natives/Generated/ink/LayerDefinitionCollection.hpp>
#include <RED4ext/Scripting/Natives/Generated/ink/LayerDefinitionsSet.hpp>
#include <RED4ext/Scripting/Natives/Generated/ink/PermanentLayerDefinitionCollection.hpp>

namespace RED4ext
{
namespace ink
{
struct LayersResource : CResource
{
    static constexpr const char* NAME = "inkLayersResource";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    uint8_t unk39[0x40 - 0x39]; // 39
    ink::LayerDefinitionCollection layerDefinitions; // 40
    ink::LayerDefinitionCollection preGameLayerDefinitions; // 3B8
    ink::PermanentLayerDefinitionCollection permanentLayerDefinitions; // 730
    ink::LayerDefinitionsSet layerDefinitionsSet; // 878
#else
    ink::LayerDefinitionCollection layerDefinitions; // 40
    ink::LayerDefinitionCollection preGameLayerDefinitions; // 3B8
    ink::PermanentLayerDefinitionCollection permanentLayerDefinitions; // 730
    ink::LayerDefinitionsSet layerDefinitionsSet; // 878
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(LayersResource, 0x898);
RED4EXT_ASSERT_OFFSET(LayersResource, layerDefinitions, 0x40);
RED4EXT_ASSERT_OFFSET(LayersResource, preGameLayerDefinitions, 0x3B8);
RED4EXT_ASSERT_OFFSET(LayersResource, permanentLayerDefinitions, 0x730);
RED4EXT_ASSERT_OFFSET(LayersResource, layerDefinitionsSet, 0x878);
#else
RED4EXT_ASSERT_SIZE(LayersResource, 0x898);
#endif
} // namespace ink
using inkLayersResource = ink::LayersResource;
} // namespace RED4ext

// clang-format on
