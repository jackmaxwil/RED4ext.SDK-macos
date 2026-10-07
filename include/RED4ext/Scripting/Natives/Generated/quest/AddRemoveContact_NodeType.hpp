#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/DynArray.hpp>
#include <RED4ext/Scripting/Natives/Generated/quest/ChangeContactList_NodeTypeParams.hpp>
#include <RED4ext/Scripting/Natives/Generated/quest/IPhoneManagerNodeType.hpp>

namespace RED4ext
{
namespace quest
{
struct AddRemoveContact_NodeType : quest::IPhoneManagerNodeType
{
    static constexpr const char* NAME = "questAddRemoveContact_NodeType";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    uint8_t unk34[0x38 - 0x34]; // 34
    DynArray<quest::ChangeContactList_NodeTypeParams> params; // 38
#else
    DynArray<quest::ChangeContactList_NodeTypeParams> params; // 38
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(AddRemoveContact_NodeType, 0x48);
RED4EXT_ASSERT_OFFSET(AddRemoveContact_NodeType, params, 0x38);
#else
RED4EXT_ASSERT_SIZE(AddRemoveContact_NodeType, 0x48);
#endif
} // namespace quest
using questAddRemoveContact_NodeType = quest::AddRemoveContact_NodeType;
} // namespace RED4ext

// clang-format on
