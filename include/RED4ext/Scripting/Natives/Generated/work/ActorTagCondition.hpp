#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/CName.hpp>
#include <RED4ext/Scripting/Natives/Generated/work/IWorkspotCondition.hpp>

namespace RED4ext
{
namespace work
{
struct ActorTagCondition : work::IWorkspotCondition
{
    static constexpr const char* NAME = "workActorTagCondition";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    uint8_t unk35[0x38 - 0x35]; // 35
    CName tag; // 38
#else
    CName tag; // 38
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(ActorTagCondition, 0x40);
RED4EXT_ASSERT_OFFSET(ActorTagCondition, tag, 0x38);
#else
RED4EXT_ASSERT_SIZE(ActorTagCondition, 0x40);
#endif
} // namespace work
using workActorTagCondition = work::ActorTagCondition;
} // namespace RED4ext

// clang-format on
