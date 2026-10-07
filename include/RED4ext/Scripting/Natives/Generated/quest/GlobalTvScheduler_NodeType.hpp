#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/CName.hpp>
#include <RED4ext/NativeTypes.hpp>
#include <RED4ext/Scripting/Natives/Generated/quest/IUIManagerNodeType.hpp>

namespace RED4ext
{
struct Bink;
namespace ink { struct WidgetLibraryResource; }
namespace scn { struct SceneResource; }

namespace quest
{
struct GlobalTvScheduler_NodeType : quest::IUIManagerNodeType
{
    static constexpr const char* NAME = "questGlobalTvScheduler_NodeType";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    TweakDBID channelId; // 34
    uint8_t unk3C[0x40 - 0x3C]; // 3C
    RaRef<Bink> videoResource; // 40
    RaRef<ink::WidgetLibraryResource> overlayResource; // 48
    uint8_t unk50[0x58 - 0x50]; // 50
    RaRef<scn::SceneResource> VOScene; // 58
    CName audioEvent; // 60
    TweakDBID newsTitleTweak; // 68
    TweakDBID randomNewsFeedPack; // 70
#else
    TweakDBID channelId; // 38
    RaRef<Bink> videoResource; // 40
    RaRef<ink::WidgetLibraryResource> overlayResource; // 48
    uint8_t unk50[0x58 - 0x50]; // 50
    RaRef<scn::SceneResource> VOScene; // 58
    CName audioEvent; // 60
    TweakDBID newsTitleTweak; // 68
    TweakDBID randomNewsFeedPack; // 70
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(GlobalTvScheduler_NodeType, 0x78);
RED4EXT_ASSERT_OFFSET(GlobalTvScheduler_NodeType, channelId, 0x34);
RED4EXT_ASSERT_OFFSET(GlobalTvScheduler_NodeType, videoResource, 0x40);
RED4EXT_ASSERT_OFFSET(GlobalTvScheduler_NodeType, overlayResource, 0x48);
RED4EXT_ASSERT_OFFSET(GlobalTvScheduler_NodeType, VOScene, 0x58);
RED4EXT_ASSERT_OFFSET(GlobalTvScheduler_NodeType, audioEvent, 0x60);
RED4EXT_ASSERT_OFFSET(GlobalTvScheduler_NodeType, newsTitleTweak, 0x68);
RED4EXT_ASSERT_OFFSET(GlobalTvScheduler_NodeType, randomNewsFeedPack, 0x70);
#else
RED4EXT_ASSERT_SIZE(GlobalTvScheduler_NodeType, 0x78);
#endif
} // namespace quest
using questGlobalTvScheduler_NodeType = quest::GlobalTvScheduler_NodeType;
} // namespace RED4ext

// clang-format on
