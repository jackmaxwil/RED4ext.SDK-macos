#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/NativeTypes.hpp>
#include <RED4ext/Scripting/Natives/Generated/ent/IComponent.hpp>

namespace RED4ext
{
namespace game
{
struct PhotoModeBackgroundViewComponent : ent::IComponent
{
    static constexpr const char* NAME = "gamePhotoModeBackgroundViewComponent";
    static constexpr const char* ALIAS = "PhotoModeBackgroundViewComponent";

#ifdef __APPLE__
    uint8_t unk8D[0xC0 - 0x8D]; // 8D
    NodeRef backgroundPrefabRef; // C0
    NodeRef targetPointRef; // C8
    uint8_t unkD0[0xE0 - 0xD0]; // D0
#else
    uint8_t unk90[0xC0 - 0x90]; // 90
    NodeRef backgroundPrefabRef; // C0
    NodeRef targetPointRef; // C8
    uint8_t unkD0[0xE0 - 0xD0]; // D0
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(PhotoModeBackgroundViewComponent, 0xE0);
RED4EXT_ASSERT_OFFSET(PhotoModeBackgroundViewComponent, backgroundPrefabRef, 0xC0);
RED4EXT_ASSERT_OFFSET(PhotoModeBackgroundViewComponent, targetPointRef, 0xC8);
#else
RED4EXT_ASSERT_SIZE(PhotoModeBackgroundViewComponent, 0xE0);
#endif
} // namespace game
using gamePhotoModeBackgroundViewComponent = game::PhotoModeBackgroundViewComponent;
using PhotoModeBackgroundViewComponent = game::PhotoModeBackgroundViewComponent;
} // namespace RED4ext

// clang-format on
