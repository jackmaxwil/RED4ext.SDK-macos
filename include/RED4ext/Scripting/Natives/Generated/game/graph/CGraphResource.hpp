#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/Scripting/Natives/Generated/CResource.hpp>

namespace RED4ext
{
namespace game::graph
{
struct CGraphResource : CResource
{
    static constexpr const char* NAME = "gamegraphCGraphResource";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    uint8_t unk39[0x50 - 0x39]; // 39
#else
    uint8_t unk40[0x50 - 0x40]; // 40
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(CGraphResource, 0x50);
#else
RED4EXT_ASSERT_SIZE(CGraphResource, 0x50);
#endif
} // namespace game::graph
using gamegraphCGraphResource = game::graph::CGraphResource;
} // namespace RED4ext

// clang-format on
