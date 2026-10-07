#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/CName.hpp>
#include <RED4ext/Scripting/Natives/Generated/ink/CompoundWidgetReference.hpp>
#include <RED4ext/Scripting/Natives/Generated/ink/ILoadingLogicController.hpp>
#include <RED4ext/Scripting/Natives/Generated/ink/WidgetReference.hpp>

namespace RED4ext
{
namespace ink
{
struct InitialLoadingScreenLogicController : ink::ILoadingLogicController
{
    static constexpr const char* NAME = "inkInitialLoadingScreenLogicController";
    static constexpr const char* ALIAS = "InitialLoadingScreenLogicController";

#ifdef __APPLE__
    CName afterSkipAnimation; // 190
    CName loadingFinishedAudioStopEvent; // 198
    uint8_t unk1A0[0x1C0 - 0x1A0]; // 1A0
    ink::WidgetReference skipButtonPanel; // 1C0
    ink::CompoundWidgetReference loadingPartsContainer; // 1D8
    uint8_t unk1F0[0x388 - 0x1F0]; // 1F0
#else
    CName afterSkipAnimation; // 190
    CName loadingFinishedAudioStopEvent; // 198
    uint8_t unk1A0[0x1C0 - 0x1A0]; // 1A0
    ink::WidgetReference skipButtonPanel; // 1C0
    ink::CompoundWidgetReference loadingPartsContainer; // 1D8
    uint8_t unk1F0[0x2C8 - 0x1F0]; // 1F0
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(InitialLoadingScreenLogicController, 0x388);
RED4EXT_ASSERT_OFFSET(InitialLoadingScreenLogicController, afterSkipAnimation, 0x190);
RED4EXT_ASSERT_OFFSET(InitialLoadingScreenLogicController, loadingFinishedAudioStopEvent, 0x198);
RED4EXT_ASSERT_OFFSET(InitialLoadingScreenLogicController, skipButtonPanel, 0x1C0);
RED4EXT_ASSERT_OFFSET(InitialLoadingScreenLogicController, loadingPartsContainer, 0x1D8);
#else
RED4EXT_ASSERT_SIZE(InitialLoadingScreenLogicController, 0x2C8);
#endif
} // namespace ink
using inkInitialLoadingScreenLogicController = ink::InitialLoadingScreenLogicController;
using InitialLoadingScreenLogicController = ink::InitialLoadingScreenLogicController;
} // namespace RED4ext

// clang-format on
