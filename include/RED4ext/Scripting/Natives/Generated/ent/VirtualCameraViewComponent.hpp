#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/CName.hpp>
#include <RED4ext/Scripting/Natives/Generated/Vector2.hpp>
#include <RED4ext/Scripting/Natives/Generated/ent/IVisualComponent.hpp>

namespace RED4ext
{
namespace ent
{
struct __declspec(align(0x10)) VirtualCameraViewComponent : ent::IVisualComponent
{
    static constexpr const char* NAME = "entVirtualCameraViewComponent";
    static constexpr const char* ALIAS = "VirtualCameraViewComponent";

#ifdef __APPLE__
    uint8_t unk13C[0x140 - 0x13C]; // 13C
    CName virtualCameraName; // 140
    Vector2 targetPlaneSize; // 148
    uint8_t unk150[0x170 - 0x150]; // 150
#else
    CName virtualCameraName; // 140
    Vector2 targetPlaneSize; // 148
    uint8_t unk150[0x170 - 0x150]; // 150
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(VirtualCameraViewComponent, 0x170);
RED4EXT_ASSERT_OFFSET(VirtualCameraViewComponent, virtualCameraName, 0x140);
RED4EXT_ASSERT_OFFSET(VirtualCameraViewComponent, targetPlaneSize, 0x148);
#else
RED4EXT_ASSERT_SIZE(VirtualCameraViewComponent, 0x170);
#endif
} // namespace ent
using entVirtualCameraViewComponent = ent::VirtualCameraViewComponent;
using VirtualCameraViewComponent = ent::VirtualCameraViewComponent;
} // namespace RED4ext

// clang-format on
