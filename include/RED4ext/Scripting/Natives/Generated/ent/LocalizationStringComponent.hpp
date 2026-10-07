#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/DynArray.hpp>
#include <RED4ext/Scripting/Natives/Generated/ent/IComponent.hpp>
#include <RED4ext/Scripting/Natives/Generated/ent/LocalizationStringMapEntry.hpp>

namespace RED4ext
{
namespace ent
{
struct LocalizationStringComponent : ent::IComponent
{
    static constexpr const char* NAME = "entLocalizationStringComponent";
    static constexpr const char* ALIAS = "LocalizationStringComponent";

#ifdef __APPLE__
    uint8_t unk8D[0x90 - 0x8D]; // 8D
    DynArray<ent::LocalizationStringMapEntry> Strings; // 90
#else
    DynArray<ent::LocalizationStringMapEntry> Strings; // 90
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(LocalizationStringComponent, 0xA0);
RED4EXT_ASSERT_OFFSET(LocalizationStringComponent, Strings, 0x90);
#else
RED4EXT_ASSERT_SIZE(LocalizationStringComponent, 0xA0);
#endif
} // namespace ent
using entLocalizationStringComponent = ent::LocalizationStringComponent;
using LocalizationStringComponent = ent::LocalizationStringComponent;
} // namespace RED4ext

// clang-format on
