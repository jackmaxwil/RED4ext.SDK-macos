#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/CName.hpp>
#include <RED4ext/Scripting/Natives/Generated/ent/BaseCameraComponent.hpp>

namespace RED4ext
{
namespace ent
{
struct __declspec(align(0x10)) VirtualCameraComponent : ent::BaseCameraComponent
{
    static constexpr const char* NAME = "entVirtualCameraComponent";
    static constexpr const char* ALIAS = "VirtualCameraComponent";

#ifdef __APPLE__
    CName virtualCameraName; // 1D8
    uint32_t resolutionWidth; // 1E0
    uint32_t resolutionHeight; // 1E4
    bool drawBackground; // 1E8
    uint8_t unk1E9[0x1F0 - 0x1E9]; // 1E9
#else
    CName virtualCameraName; // 1E0
    uint32_t resolutionWidth; // 1E8
    uint32_t resolutionHeight; // 1EC
    bool drawBackground; // 1F0
    uint8_t unk1F1[0x200 - 0x1F1]; // 1F1
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(VirtualCameraComponent, 0x1F0);
RED4EXT_ASSERT_OFFSET(VirtualCameraComponent, virtualCameraName, 0x1D8);
RED4EXT_ASSERT_OFFSET(VirtualCameraComponent, resolutionWidth, 0x1E0);
RED4EXT_ASSERT_OFFSET(VirtualCameraComponent, resolutionHeight, 0x1E4);
RED4EXT_ASSERT_OFFSET(VirtualCameraComponent, drawBackground, 0x1E8);
#else
RED4EXT_ASSERT_SIZE(VirtualCameraComponent, 0x200);
#endif
} // namespace ent
using entVirtualCameraComponent = ent::VirtualCameraComponent;
using VirtualCameraComponent = ent::VirtualCameraComponent;
} // namespace RED4ext

// clang-format on
