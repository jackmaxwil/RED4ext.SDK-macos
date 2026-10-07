#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/CName.hpp>
#include <RED4ext/Containers/DynArray.hpp>
#include <RED4ext/Handle.hpp>
#include <RED4ext/Scripting/Natives/Generated/effect/LoopData.hpp>
#include <RED4ext/Scripting/Natives/Generated/res/StreamedResource.hpp>

namespace RED4ext
{
namespace effect { struct TrackGroup; }
namespace effect { struct TrackItem; }

namespace world
{
struct Effect : res::StreamedResource
{
    static constexpr const char* NAME = "worldEffect";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    uint8_t unk39[0x40 - 0x39]; // 39
    CName name; // 40
    float length; // 48
    uint8_t unk4C[0x50 - 0x4C]; // 4C
    Handle<effect::TrackGroup> trackRoot; // 50
    DynArray<Handle<effect::TrackItem>> events; // 60
    DynArray<effect::LoopData> effectLoops; // 70
    DynArray<CName> inputParameterNames; // 80
#else
    CName name; // 40
    float length; // 48
    uint8_t unk4C[0x50 - 0x4C]; // 4C
    Handle<effect::TrackGroup> trackRoot; // 50
    DynArray<Handle<effect::TrackItem>> events; // 60
    DynArray<effect::LoopData> effectLoops; // 70
    DynArray<CName> inputParameterNames; // 80
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(Effect, 0x90);
RED4EXT_ASSERT_OFFSET(Effect, name, 0x40);
RED4EXT_ASSERT_OFFSET(Effect, length, 0x48);
RED4EXT_ASSERT_OFFSET(Effect, trackRoot, 0x50);
RED4EXT_ASSERT_OFFSET(Effect, events, 0x60);
RED4EXT_ASSERT_OFFSET(Effect, effectLoops, 0x70);
RED4EXT_ASSERT_OFFSET(Effect, inputParameterNames, 0x80);
#else
RED4EXT_ASSERT_SIZE(Effect, 0x90);
#endif
} // namespace world
using worldEffect = world::Effect;
} // namespace RED4ext

// clang-format on
