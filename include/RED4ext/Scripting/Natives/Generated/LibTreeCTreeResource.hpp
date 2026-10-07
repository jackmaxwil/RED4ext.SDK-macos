#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/Scripting/Natives/Generated/CResource.hpp>
#include <RED4ext/Scripting/Natives/Generated/LibTreeDefTreeVariablesList.hpp>

namespace RED4ext
{
struct LibTreeCTreeResource : CResource
{
    static constexpr const char* NAME = "LibTreeCTreeResource";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    uint8_t unk39[0x40 - 0x39]; // 39
    LibTreeDefTreeVariablesList variables; // 40
    uint8_t unk58[0x68 - 0x58]; // 58
#else
    LibTreeDefTreeVariablesList variables; // 40
    uint8_t unk58[0x68 - 0x58]; // 58
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(LibTreeCTreeResource, 0x68);
RED4EXT_ASSERT_OFFSET(LibTreeCTreeResource, variables, 0x40);
#else
RED4EXT_ASSERT_SIZE(LibTreeCTreeResource, 0x68);
#endif
} // namespace RED4ext

// clang-format on
