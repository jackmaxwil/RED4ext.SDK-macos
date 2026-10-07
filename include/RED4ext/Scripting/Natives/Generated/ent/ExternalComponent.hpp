#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/CName.hpp>
#include <RED4ext/Scripting/Natives/Generated/ent/IComponent.hpp>

namespace RED4ext
{
namespace ent
{
struct ExternalComponent : ent::IComponent
{
    static constexpr const char* NAME = "entExternalComponent";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    uint8_t unk8D[0x90 - 0x8D]; // 8D
    CName externalComponentName; // 90
#else
    CName externalComponentName; // 90
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(ExternalComponent, 0x98);
RED4EXT_ASSERT_OFFSET(ExternalComponent, externalComponentName, 0x90);
#else
RED4EXT_ASSERT_SIZE(ExternalComponent, 0x98);
#endif
} // namespace ent
using entExternalComponent = ent::ExternalComponent;
} // namespace RED4ext

// clang-format on
