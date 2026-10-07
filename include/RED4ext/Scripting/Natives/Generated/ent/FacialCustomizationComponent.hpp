#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/NativeTypes.hpp>
#include <RED4ext/Scripting/Natives/Generated/ent/IComponent.hpp>

namespace RED4ext
{
namespace anim { struct FacialCustomizationSet; }

namespace ent
{
struct FacialCustomizationComponent : ent::IComponent
{
    static constexpr const char* NAME = "entFacialCustomizationComponent";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    uint8_t unk8D[0x90 - 0x8D]; // 8D
    RaRef<anim::FacialCustomizationSet> customizationSet; // 90
    uint8_t unk98[0xF0 - 0x98]; // 98
    bool debugIgnoreComponent; // F0
    uint8_t unkF1[0xF4 - 0xF1]; // F1
    uint32_t eyes; // F4
    uint32_t nose; // F8
    uint32_t mouth; // FC
    uint32_t jaw; // 100
    uint32_t ears; // 104
    uint8_t unk108[0x148 - 0x108]; // 108
#else
    RaRef<anim::FacialCustomizationSet> customizationSet; // 90
    uint8_t unk98[0xF0 - 0x98]; // 98
    bool debugIgnoreComponent; // F0
    uint8_t unkF1[0xF4 - 0xF1]; // F1
    uint32_t eyes; // F4
    uint32_t nose; // F8
    uint32_t mouth; // FC
    uint32_t jaw; // 100
    uint32_t ears; // 104
    uint8_t unk108[0x148 - 0x108]; // 108
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(FacialCustomizationComponent, 0x148);
RED4EXT_ASSERT_OFFSET(FacialCustomizationComponent, customizationSet, 0x90);
RED4EXT_ASSERT_OFFSET(FacialCustomizationComponent, debugIgnoreComponent, 0xF0);
RED4EXT_ASSERT_OFFSET(FacialCustomizationComponent, eyes, 0xF4);
RED4EXT_ASSERT_OFFSET(FacialCustomizationComponent, nose, 0xF8);
RED4EXT_ASSERT_OFFSET(FacialCustomizationComponent, mouth, 0xFC);
RED4EXT_ASSERT_OFFSET(FacialCustomizationComponent, jaw, 0x100);
RED4EXT_ASSERT_OFFSET(FacialCustomizationComponent, ears, 0x104);
#else
RED4EXT_ASSERT_SIZE(FacialCustomizationComponent, 0x148);
#endif
} // namespace ent
using entFacialCustomizationComponent = ent::FacialCustomizationComponent;
} // namespace RED4ext

// clang-format on
