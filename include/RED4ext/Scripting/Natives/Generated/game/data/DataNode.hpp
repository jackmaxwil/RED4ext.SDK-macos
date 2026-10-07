#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/Handle.hpp>
#include <RED4ext/ISerializable.hpp>
#include <RED4ext/NativeTypes.hpp>
#include <RED4ext/Scripting/Natives/Generated/game/data/DataNodeType.hpp>

namespace RED4ext
{

namespace game::data
{
struct DataNode : ISerializable
{
    static constexpr const char* NAME = "gamedataDataNode";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    game::data::DataNodeType nodeType; // 30
    uint8_t unk34[0x38 - 0x34]; // 34
    CString fileName; // 38
    WeakHandle<game::data::DataNode> parent; // 58
    uint8_t unk68[0x94 - 0x68]; // 68
#else
    game::data::DataNodeType nodeType; // 30
    uint8_t unk34[0x38 - 0x34]; // 34
    CString fileName; // 38
    WeakHandle<game::data::DataNode> parent; // 58
    uint8_t unk68[0x98 - 0x68]; // 68
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(DataNode, 0x98);
RED4EXT_ASSERT_OFFSET(DataNode, nodeType, 0x30);
RED4EXT_ASSERT_OFFSET(DataNode, fileName, 0x38);
RED4EXT_ASSERT_OFFSET(DataNode, parent, 0x58);
#else
RED4EXT_ASSERT_SIZE(DataNode, 0x98);
#endif
} // namespace game::data
using gamedataDataNode = game::data::DataNode;
} // namespace RED4ext

// clang-format on
