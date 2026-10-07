#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/CName.hpp>
#include <RED4ext/DynArray.hpp>
#include <RED4ext/Handle.hpp>
#include <RED4ext/NativeTypes.hpp>
#include <RED4ext/Scripting/Natives/Generated/game/data/DataNode.hpp>
#include <RED4ext/Scripting/Natives/Generated/game/data/GroupNodeGroupVariable.hpp>
#include <RED4ext/Scripting/Natives/Generated/game/data/GroupNodeInheritanceState.hpp>

namespace RED4ext
{
namespace game::data { struct FileNode; }
namespace game::data { struct PackageNode; }

namespace game::data
{
struct GroupNode : game::data::DataNode
{
    static constexpr const char* NAME = "gamedataGroupNode";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    uint8_t unk94[0x98 - 0x94]; // 94
    CString name; // 98
    CString base; // B8
    CString schema; // D8
    bool isInline; // F8
    uint8_t unkF9[0x130 - 0xF9]; // F9
    WeakHandle<game::data::GroupNode> baseGroup; // 130
    WeakHandle<game::data::GroupNode> schemaGroup; // 140
    WeakHandle<game::data::PackageNode> package; // 150
    Handle<game::data::FileNode> fileNode; // 160
    uint32_t inlineGroupId; // 170
    game::data::GroupNodeInheritanceState inheritanceState; // 174
    uint8_t unk178[0x1E8 - 0x178]; // 178
    DynArray<game::data::GroupNodeGroupVariable> serializedVariables; // 1E8
    DynArray<CName> tags; // 1F8
    uint8_t unk208[0x278 - 0x208]; // 208
#else
    CString name; // 98
    CString base; // B8
    CString schema; // D8
    bool isInline; // F8
    uint8_t unkF9[0x130 - 0xF9]; // F9
    WeakHandle<game::data::GroupNode> baseGroup; // 130
    WeakHandle<game::data::GroupNode> schemaGroup; // 140
    WeakHandle<game::data::PackageNode> package; // 150
    Handle<game::data::FileNode> fileNode; // 160
    uint32_t inlineGroupId; // 170
    game::data::GroupNodeInheritanceState inheritanceState; // 174
    uint8_t unk178[0x1E8 - 0x178]; // 178
    DynArray<game::data::GroupNodeGroupVariable> serializedVariables; // 1E8
    DynArray<CName> tags; // 1F8
    uint8_t unk208[0x278 - 0x208]; // 208
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(GroupNode, 0x278);
RED4EXT_ASSERT_OFFSET(GroupNode, name, 0x98);
RED4EXT_ASSERT_OFFSET(GroupNode, base, 0xB8);
RED4EXT_ASSERT_OFFSET(GroupNode, schema, 0xD8);
RED4EXT_ASSERT_OFFSET(GroupNode, isInline, 0xF8);
RED4EXT_ASSERT_OFFSET(GroupNode, baseGroup, 0x130);
RED4EXT_ASSERT_OFFSET(GroupNode, schemaGroup, 0x140);
RED4EXT_ASSERT_OFFSET(GroupNode, package, 0x150);
RED4EXT_ASSERT_OFFSET(GroupNode, fileNode, 0x160);
RED4EXT_ASSERT_OFFSET(GroupNode, inlineGroupId, 0x170);
RED4EXT_ASSERT_OFFSET(GroupNode, inheritanceState, 0x174);
RED4EXT_ASSERT_OFFSET(GroupNode, serializedVariables, 0x1E8);
RED4EXT_ASSERT_OFFSET(GroupNode, tags, 0x1F8);
#else
RED4EXT_ASSERT_SIZE(GroupNode, 0x278);
#endif
} // namespace game::data
using gamedataGroupNode = game::data::GroupNode;
} // namespace RED4ext

// clang-format on
