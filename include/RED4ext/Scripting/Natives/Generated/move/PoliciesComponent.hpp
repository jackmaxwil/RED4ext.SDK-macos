#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/Scripting/Natives/Generated/ent/IComponent.hpp>

namespace RED4ext
{
namespace move
{
struct __declspec(align(0x10)) PoliciesComponent : ent::IComponent
{
    static constexpr const char* NAME = "movePoliciesComponent";
    static constexpr const char* ALIAS = "MovePoliciesComponent";

#ifdef __APPLE__
    uint8_t unk8D[0x610 - 0x8D]; // 8D
#else
    uint8_t unk90[0x5E0 - 0x90]; // 90
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(PoliciesComponent, 0x610);
#else
RED4EXT_ASSERT_SIZE(PoliciesComponent, 0x5E0);
#endif
} // namespace move
using movePoliciesComponent = move::PoliciesComponent;
using MovePoliciesComponent = move::PoliciesComponent;
} // namespace RED4ext

// clang-format on
