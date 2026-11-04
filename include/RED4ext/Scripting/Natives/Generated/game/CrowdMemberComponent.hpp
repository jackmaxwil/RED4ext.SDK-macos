#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/Scripting/Natives/Generated/ent/IComponent.hpp>

namespace RED4ext
{
namespace game
{
struct __declspec(align(0x10)) CrowdMemberComponent : ent::IComponent
{
    static constexpr const char* NAME = "gameCrowdMemberComponent";
    static constexpr const char* ALIAS = "CrowdMemberComponent";

#ifdef __APPLE__
    bool forceCrowdToIgnore; // 8D
    uint8_t unk8E[0x1F0 - 0x8E]; // 8E
#else
    bool forceCrowdToIgnore; // 90
    uint8_t unk91[0x220 - 0x91]; // 91
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(CrowdMemberComponent, 0x1F0);
RED4EXT_ASSERT_OFFSET(CrowdMemberComponent, forceCrowdToIgnore, 0x8D);
#else
RED4EXT_ASSERT_SIZE(CrowdMemberComponent, 0x220);
#endif
} // namespace game
using gameCrowdMemberComponent = game::CrowdMemberComponent;
using CrowdMemberComponent = game::CrowdMemberComponent;
} // namespace RED4ext

// clang-format on
