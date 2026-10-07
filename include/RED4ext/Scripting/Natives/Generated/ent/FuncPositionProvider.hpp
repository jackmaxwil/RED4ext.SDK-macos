#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/Scripting/Natives/Generated/ent/IPositionProvider.hpp>

namespace RED4ext
{
namespace ent
{
struct FuncPositionProvider : ent::IPositionProvider
{
    static constexpr const char* NAME = "entFuncPositionProvider";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    uint8_t unk50[0x70 - 0x50]; // 50
#else
    uint8_t unk50[0x90 - 0x50]; // 50
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(FuncPositionProvider, 0x70);
#else
RED4EXT_ASSERT_SIZE(FuncPositionProvider, 0x90);
#endif
} // namespace ent
using entFuncPositionProvider = ent::FuncPositionProvider;
} // namespace RED4ext

// clang-format on
