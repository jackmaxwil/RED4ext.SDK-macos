#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/Handle.hpp>
#include <RED4ext/Scripting/Natives/Generated/ent/IVisualComponent.hpp>

namespace RED4ext
{
namespace ent { struct SkinningBinding; }

namespace ent
{
struct __declspec(align(0x10)) ISkinTargetComponent : ent::IVisualComponent
{
    static constexpr const char* NAME = "entISkinTargetComponent";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    uint8_t unk13C[0x180 - 0x13C]; // 13C
    float boundingBoxLocalBoundsOverride; // 180
    uint8_t unk184[0x188 - 0x184]; // 184
    Handle<ent::SkinningBinding> skinning; // 188
    uint8_t unk198[0x1D8 - 0x198]; // 198
    bool useSkinningLOD; // 1D8
    uint8_t unk1D9[0x1E0 - 0x1D9]; // 1D9
#else
    uint8_t unk140[0x180 - 0x140]; // 140
    float boundingBoxLocalBoundsOverride; // 180
    uint8_t unk184[0x188 - 0x184]; // 184
    Handle<ent::SkinningBinding> skinning; // 188
    uint8_t unk198[0x1D8 - 0x198]; // 198
    bool useSkinningLOD; // 1D8
    uint8_t unk1D9[0x1E0 - 0x1D9]; // 1D9
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(ISkinTargetComponent, 0x1E0);
RED4EXT_ASSERT_OFFSET(ISkinTargetComponent, boundingBoxLocalBoundsOverride, 0x180);
RED4EXT_ASSERT_OFFSET(ISkinTargetComponent, skinning, 0x188);
RED4EXT_ASSERT_OFFSET(ISkinTargetComponent, useSkinningLOD, 0x1D8);
#else
RED4EXT_ASSERT_SIZE(ISkinTargetComponent, 0x1E0);
#endif
} // namespace ent
using entISkinTargetComponent = ent::ISkinTargetComponent;
} // namespace RED4ext

// clang-format on
