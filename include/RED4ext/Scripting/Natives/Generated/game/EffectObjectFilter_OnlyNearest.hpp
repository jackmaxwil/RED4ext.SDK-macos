#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/Scripting/Natives/Generated/game/EffectObjectGroupFilter.hpp>

namespace RED4ext
{
namespace game
{
struct EffectObjectFilter_OnlyNearest : game::EffectObjectGroupFilter
{
    static constexpr const char* NAME = "gameEffectObjectFilter_OnlyNearest";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    uint32_t count; // 40
    uint8_t unk44[0x45 - 0x44]; // 44
#else
    uint32_t count; // 40
    uint8_t unk44[0x48 - 0x44]; // 44
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(EffectObjectFilter_OnlyNearest, 0x48);
RED4EXT_ASSERT_OFFSET(EffectObjectFilter_OnlyNearest, count, 0x40);
#else
RED4EXT_ASSERT_SIZE(EffectObjectFilter_OnlyNearest, 0x48);
#endif
} // namespace game
using gameEffectObjectFilter_OnlyNearest = game::EffectObjectFilter_OnlyNearest;
} // namespace RED4ext

// clang-format on
