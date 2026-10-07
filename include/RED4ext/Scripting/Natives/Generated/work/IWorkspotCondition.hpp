#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/ISerializable.hpp>
#include <RED4ext/Scripting/Natives/Generated/work/WorkspotLogic.hpp>

namespace RED4ext
{
namespace work
{
struct IWorkspotCondition : ISerializable
{
    static constexpr const char* NAME = "workIWorkspotCondition";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    work::WorkspotLogic expectedResult; // 30
    bool equals; // 34
#else
    work::WorkspotLogic expectedResult; // 30
    bool equals; // 34
    uint8_t unk35[0x38 - 0x35]; // 35
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(IWorkspotCondition, 0x38);
RED4EXT_ASSERT_OFFSET(IWorkspotCondition, expectedResult, 0x30);
RED4EXT_ASSERT_OFFSET(IWorkspotCondition, equals, 0x34);
#else
RED4EXT_ASSERT_SIZE(IWorkspotCondition, 0x38);
#endif
} // namespace work
using workIWorkspotCondition = work::IWorkspotCondition;
} // namespace RED4ext

// clang-format on
