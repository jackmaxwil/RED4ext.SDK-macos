#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/DynArray.hpp>
#include <RED4ext/Scripting/Natives/Generated/ent/IComponent.hpp>
#include <RED4ext/Scripting/Natives/Generated/game/AnimParamSlotsOption.hpp>

namespace RED4ext
{
namespace game
{
struct AttachmentSlots : ent::IComponent
{
    static constexpr const char* NAME = "gameAttachmentSlots";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    uint8_t unk8D[0xE0 - 0x8D]; // 8D
    DynArray<game::AnimParamSlotsOption> animParams; // E0
    uint8_t unkF0[0x118 - 0xF0]; // F0
#else
    uint8_t unk90[0xE0 - 0x90]; // 90
    DynArray<game::AnimParamSlotsOption> animParams; // E0
    uint8_t unkF0[0x118 - 0xF0]; // F0
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(AttachmentSlots, 0x118);
RED4EXT_ASSERT_OFFSET(AttachmentSlots, animParams, 0xE0);
#else
RED4EXT_ASSERT_SIZE(AttachmentSlots, 0x118);
#endif
} // namespace game
using gameAttachmentSlots = game::AttachmentSlots;
} // namespace RED4ext

// clang-format on
