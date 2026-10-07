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
struct NarrationPlateComponent : ent::IComponent
{
    static constexpr const char* NAME = "gameNarrationPlateComponent";
    static constexpr const char* ALIAS = "NarrationPlateComponent";

#ifdef __APPLE__
    uint8_t unk8D[0x90 - 0x8D]; // 8D
    CName narrationText; // 90
    CName narrationCaption; // 98
#else
    CName narrationText; // 90
    CName narrationCaption; // 98
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(NarrationPlateComponent, 0xA0);
RED4EXT_ASSERT_OFFSET(NarrationPlateComponent, narrationText, 0x90);
RED4EXT_ASSERT_OFFSET(NarrationPlateComponent, narrationCaption, 0x98);
#else
RED4EXT_ASSERT_SIZE(NarrationPlateComponent, 0xA0);
#endif
} // namespace game
using gameNarrationPlateComponent = game::NarrationPlateComponent;
using NarrationPlateComponent = game::NarrationPlateComponent;
} // namespace RED4ext

// clang-format on
