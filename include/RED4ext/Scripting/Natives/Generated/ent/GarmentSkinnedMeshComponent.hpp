#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/Scripting/Natives/Generated/ent/SkinnedMeshComponent.hpp>

namespace RED4ext
{
namespace ent
{
struct __declspec(align(0x10)) GarmentSkinnedMeshComponent : ent::SkinnedMeshComponent
{
    static constexpr const char* NAME = "entGarmentSkinnedMeshComponent";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    uint8_t unk268[0x2C0 - 0x268]; // 268
#else
    uint8_t unk270[0x2D0 - 0x270]; // 270
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(GarmentSkinnedMeshComponent, 0x2C0);
#else
RED4EXT_ASSERT_SIZE(GarmentSkinnedMeshComponent, 0x2D0);
#endif
} // namespace ent
using entGarmentSkinnedMeshComponent = ent::GarmentSkinnedMeshComponent;
} // namespace RED4ext

// clang-format on
