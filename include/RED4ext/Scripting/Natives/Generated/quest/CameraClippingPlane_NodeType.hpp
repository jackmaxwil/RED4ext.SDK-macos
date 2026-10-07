#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/Scripting/Natives/Generated/quest/CameraPlanesPreset.hpp>
#include <RED4ext/Scripting/Natives/Generated/quest/ISceneManagerNodeType.hpp>

namespace RED4ext
{
namespace quest
{
struct CameraClippingPlane_NodeType : quest::ISceneManagerNodeType
{
    static constexpr const char* NAME = "questCameraClippingPlane_NodeType";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    quest::CameraPlanesPreset preset; // 34
    uint8_t unk35[0x38 - 0x35]; // 35
#else
    quest::CameraPlanesPreset preset; // 38
    uint8_t unk39[0x40 - 0x39]; // 39
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(CameraClippingPlane_NodeType, 0x38);
RED4EXT_ASSERT_OFFSET(CameraClippingPlane_NodeType, preset, 0x34);
#else
RED4EXT_ASSERT_SIZE(CameraClippingPlane_NodeType, 0x40);
#endif
} // namespace quest
using questCameraClippingPlane_NodeType = quest::CameraClippingPlane_NodeType;
} // namespace RED4ext

// clang-format on
