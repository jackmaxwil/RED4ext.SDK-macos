#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/CName.hpp>
#include <RED4ext/Scripting/Natives/Generated/game/ui/SideScrollerMiniGamePlayerController.hpp>
#include <RED4ext/Scripting/Natives/Generated/ink/ImageWidgetReference.hpp>

namespace RED4ext
{
namespace game::ui
{
struct QuadRacerPlayer : game::ui::SideScrollerMiniGamePlayerController
{
    static constexpr const char* NAME = "gameuiQuadRacerPlayer";
    static constexpr const char* ALIAS = "QuadRacerPlayer";

#ifdef __APPLE__
    uint8_t unk88[0x98 - 0x88]; // 88
    CName leftTurnAtlasRegion; // 98
    CName rightTurnAtlasRegion; // A0
    CName straightTurnAtlasRegion; // A8
    ink::ImageWidgetReference playerImage; // B0
    ink::ImageWidgetReference leftTireSmoke; // C8
    ink::ImageWidgetReference rightTireSmoke; // E0
    ink::ImageWidgetReference rightFlame; // F8
    ink::ImageWidgetReference leftFlame; // 110
#else
    uint8_t unk88[0xA0 - 0x88]; // 88
    CName leftTurnAtlasRegion; // A0
    CName rightTurnAtlasRegion; // A8
    CName straightTurnAtlasRegion; // B0
    ink::ImageWidgetReference playerImage; // B8
    ink::ImageWidgetReference leftTireSmoke; // D0
    ink::ImageWidgetReference rightTireSmoke; // E8
    ink::ImageWidgetReference rightFlame; // 100
    ink::ImageWidgetReference leftFlame; // 118
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(QuadRacerPlayer, 0x128);
RED4EXT_ASSERT_OFFSET(QuadRacerPlayer, leftTurnAtlasRegion, 0x98);
RED4EXT_ASSERT_OFFSET(QuadRacerPlayer, rightTurnAtlasRegion, 0xA0);
RED4EXT_ASSERT_OFFSET(QuadRacerPlayer, straightTurnAtlasRegion, 0xA8);
RED4EXT_ASSERT_OFFSET(QuadRacerPlayer, playerImage, 0xB0);
RED4EXT_ASSERT_OFFSET(QuadRacerPlayer, leftTireSmoke, 0xC8);
RED4EXT_ASSERT_OFFSET(QuadRacerPlayer, rightTireSmoke, 0xE0);
RED4EXT_ASSERT_OFFSET(QuadRacerPlayer, rightFlame, 0xF8);
RED4EXT_ASSERT_OFFSET(QuadRacerPlayer, leftFlame, 0x110);
#else
RED4EXT_ASSERT_SIZE(QuadRacerPlayer, 0x130);
#endif
} // namespace game::ui
using gameuiQuadRacerPlayer = game::ui::QuadRacerPlayer;
using QuadRacerPlayer = game::ui::QuadRacerPlayer;
} // namespace RED4ext

// clang-format on
