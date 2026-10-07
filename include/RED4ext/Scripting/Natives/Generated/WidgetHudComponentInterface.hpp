#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/Handle.hpp>
#include <RED4ext/NativeTypes.hpp>
#include <RED4ext/Scripting/Natives/Generated/WidgetBaseComponent.hpp>

namespace RED4ext
{
struct CMaterialTemplate;
namespace ink { struct HudEntriesResource; }
namespace world::ui { struct MeshTargetBinding; }

struct __declspec(align(0x10)) WidgetHudComponentInterface : WidgetBaseComponent
{
    static constexpr const char* NAME = "WidgetHudComponentInterface";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    Ref<CMaterialTemplate> externalMaterial; // 198
    Handle<world::ui::MeshTargetBinding> meshTargetBinding; // 1B0
    uint8_t unk1C0[0x1D0 - 0x1C0]; // 1C0
    Ref<ink::HudEntriesResource> hudEntriesResource; // 1D0
    uint8_t unk1E8[0x1F0 - 0x1E8]; // 1E8
#else
    Ref<CMaterialTemplate> externalMaterial; // 1A0
    Handle<world::ui::MeshTargetBinding> meshTargetBinding; // 1B8
    uint8_t unk1C8[0x1D8 - 0x1C8]; // 1C8
    Ref<ink::HudEntriesResource> hudEntriesResource; // 1D8
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(WidgetHudComponentInterface, 0x1F0);
RED4EXT_ASSERT_OFFSET(WidgetHudComponentInterface, externalMaterial, 0x198);
RED4EXT_ASSERT_OFFSET(WidgetHudComponentInterface, meshTargetBinding, 0x1B0);
RED4EXT_ASSERT_OFFSET(WidgetHudComponentInterface, hudEntriesResource, 0x1D0);
#else
RED4EXT_ASSERT_SIZE(WidgetHudComponentInterface, 0x1F0);
#endif
} // namespace RED4ext

// clang-format on
