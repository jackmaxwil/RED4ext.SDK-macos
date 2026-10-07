#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/Scripting/Natives/Generated/attr/Attribute.hpp>

namespace RED4ext
{
namespace attr
{
struct DynamicChoice : attr::Attribute
{
    static constexpr const char* NAME = "attrDynamicChoice";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    uint8_t unk30[0x50 - 0x30]; // 30
#else
    uint8_t unk30[0x70 - 0x30]; // 30
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(DynamicChoice, 0x50);
#else
RED4EXT_ASSERT_SIZE(DynamicChoice, 0x70);
#endif
} // namespace attr
using attrDynamicChoice = attr::DynamicChoice;
} // namespace RED4ext

// clang-format on
