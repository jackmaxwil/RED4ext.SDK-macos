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
struct ScanningActivatorComponent : ent::IComponent
{
    static constexpr const char* NAME = "gameScanningActivatorComponent";
    static constexpr const char* ALIAS = "ScanningActivatorComponent";

#ifdef __APPLE__
    uint8_t unk8D[0x180 - 0x8D]; // 8D
#else
    uint8_t unk90[0x180 - 0x90]; // 90
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(ScanningActivatorComponent, 0x180);
#else
RED4EXT_ASSERT_SIZE(ScanningActivatorComponent, 0x180);
#endif
} // namespace game
using gameScanningActivatorComponent = game::ScanningActivatorComponent;
using ScanningActivatorComponent = game::ScanningActivatorComponent;
} // namespace RED4ext

// clang-format on
