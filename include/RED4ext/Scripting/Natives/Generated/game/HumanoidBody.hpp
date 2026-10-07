#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/CName.hpp>
#include <RED4ext/Scripting/Natives/Generated/ent/IComponent.hpp>

namespace RED4ext
{
namespace game
{
struct HumanoidBody : ent::IComponent
{
    static constexpr const char* NAME = "gameHumanoidBody";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    uint8_t unk8D[0x90 - 0x8D]; // 8D
    CName stanceAnimFeatureName; // 90
    CName aimAnimFeatureName; // 98
    float basePersonalSpace; // A0
    float baseHeight; // A4
    float baseEyesHeightRatio; // A8
    uint8_t unkAC[0xE0 - 0xAC]; // AC
#else
    CName stanceAnimFeatureName; // 90
    CName aimAnimFeatureName; // 98
    float basePersonalSpace; // A0
    float baseHeight; // A4
    float baseEyesHeightRatio; // A8
    uint8_t unkAC[0xE0 - 0xAC]; // AC
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(HumanoidBody, 0xE0);
RED4EXT_ASSERT_OFFSET(HumanoidBody, stanceAnimFeatureName, 0x90);
RED4EXT_ASSERT_OFFSET(HumanoidBody, aimAnimFeatureName, 0x98);
RED4EXT_ASSERT_OFFSET(HumanoidBody, basePersonalSpace, 0xA0);
RED4EXT_ASSERT_OFFSET(HumanoidBody, baseHeight, 0xA4);
RED4EXT_ASSERT_OFFSET(HumanoidBody, baseEyesHeightRatio, 0xA8);
#else
RED4EXT_ASSERT_SIZE(HumanoidBody, 0xE0);
#endif
} // namespace game
using gameHumanoidBody = game::HumanoidBody;
} // namespace RED4ext

// clang-format on
