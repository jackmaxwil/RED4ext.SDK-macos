#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/Scripting/Natives/Generated/ent/IComponent.hpp>

namespace RED4ext
{
namespace ent
{
struct TransformHistoryComponent : ent::IComponent
{
    static constexpr const char* NAME = "entTransformHistoryComponent";
    static constexpr const char* ALIAS = "TransformHistoryComponent";

#ifdef __APPLE__
    uint8_t unk8D[0xA8 - 0x8D]; // 8D
    float historyLength; // A8
    uint32_t samplesAmount; // AC
    uint8_t unkB0[0xC0 - 0xB0]; // B0
#else
    uint8_t unk90[0xA8 - 0x90]; // 90
    float historyLength; // A8
    uint32_t samplesAmount; // AC
    uint8_t unkB0[0xC0 - 0xB0]; // B0
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(TransformHistoryComponent, 0xC0);
RED4EXT_ASSERT_OFFSET(TransformHistoryComponent, historyLength, 0xA8);
RED4EXT_ASSERT_OFFSET(TransformHistoryComponent, samplesAmount, 0xAC);
#else
RED4EXT_ASSERT_SIZE(TransformHistoryComponent, 0xC0);
#endif
} // namespace ent
using entTransformHistoryComponent = ent::TransformHistoryComponent;
using TransformHistoryComponent = ent::TransformHistoryComponent;
} // namespace RED4ext

// clang-format on
