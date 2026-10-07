#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/Scripting/Natives/Generated/ink/ListController.hpp>

namespace RED4ext
{
namespace ink
{
struct RollingListController : ink::ListController
{
    static constexpr const char* NAME = "inkRollingListController";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    int32_t itemsToDisplay; // 124
    float convexity; // 128
    float verticalCompression; // 12C
    float scrollTime; // 130
    uint8_t unk134[0x138 - 0x134]; // 134
#else
    int32_t itemsToDisplay; // 128
    float convexity; // 12C
    float verticalCompression; // 130
    float scrollTime; // 134
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(RollingListController, 0x138);
RED4EXT_ASSERT_OFFSET(RollingListController, itemsToDisplay, 0x124);
RED4EXT_ASSERT_OFFSET(RollingListController, convexity, 0x128);
RED4EXT_ASSERT_OFFSET(RollingListController, verticalCompression, 0x12C);
RED4EXT_ASSERT_OFFSET(RollingListController, scrollTime, 0x130);
#else
RED4EXT_ASSERT_SIZE(RollingListController, 0x138);
#endif
} // namespace ink
using inkRollingListController = ink::RollingListController;
} // namespace RED4ext

// clang-format on
