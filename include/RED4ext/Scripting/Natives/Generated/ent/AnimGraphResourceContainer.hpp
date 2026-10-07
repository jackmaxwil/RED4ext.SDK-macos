#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/Containers/DynArray.hpp>
#include <RED4ext/Scripting/Natives/Generated/ent/AnimGraphResourceContainerEntry.hpp>
#include <RED4ext/Scripting/Natives/Generated/ent/IComponent.hpp>

namespace RED4ext
{
namespace ent
{
struct AnimGraphResourceContainer : ent::IComponent
{
    static constexpr const char* NAME = "entAnimGraphResourceContainer";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    uint8_t unk8D[0x90 - 0x8D]; // 8D
    DynArray<ent::AnimGraphResourceContainerEntry> animGraphLookupTable; // 90
#else
    DynArray<ent::AnimGraphResourceContainerEntry> animGraphLookupTable; // 90
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(AnimGraphResourceContainer, 0xA0);
RED4EXT_ASSERT_OFFSET(AnimGraphResourceContainer, animGraphLookupTable, 0x90);
#else
RED4EXT_ASSERT_SIZE(AnimGraphResourceContainer, 0xA0);
#endif
} // namespace ent
using entAnimGraphResourceContainer = ent::AnimGraphResourceContainer;
} // namespace RED4ext

// clang-format on
