#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/Containers/DynArray.hpp>
#include <RED4ext/Handle.hpp>
#include <RED4ext/Scripting/Natives/Generated/Vector4.hpp>
#include <RED4ext/Scripting/Natives/Generated/game/data/StimPropagation.hpp>
#include <RED4ext/Scripting/Natives/Generated/game/data/StimType.hpp>
#include <RED4ext/Scripting/Natives/Generated/sense/BaseStimuliEvent.hpp>
#include <RED4ext/Scripting/Natives/Generated/sense/StimInvestigateData.hpp>

namespace RED4ext
{
namespace game { struct Object; }
namespace game::data { struct Stim_Record; }
namespace sense { struct StimuliData; }

namespace sense
{
struct __declspec(align(0x10)) StimuliEvent : sense::BaseStimuliEvent
{
    static constexpr const char* NAME = "senseStimuliEvent";
    static constexpr const char* ALIAS = "StimuliEvent";

#ifdef __APPLE__
    uint8_t unk4C[0x50 - 0x4C]; // 4C
    sense::StimInvestigateData stimInvestigateData; // 50
    WeakHandle<game::Object> sourceObject; // D0
    WeakHandle<game::data::Stim_Record> stimRecord; // E0
    DynArray<Vector4> movePositions; // F0
    Vector4 sourcePosition; // 100
    float radius; // 110
    float detection; // 114
    game::data::StimPropagation stimPropagation; // 118
    uint8_t unk11C[0x120 - 0x11C]; // 11C
    Handle<sense::StimuliData> data; // 120
    game::data::StimType stimType; // 130
    bool purelyDirect; // 134
    uint8_t unk135[0x140 - 0x135]; // 135
#else
    sense::StimInvestigateData stimInvestigateData; // 50
    WeakHandle<game::Object> sourceObject; // D0
    WeakHandle<game::data::Stim_Record> stimRecord; // E0
    DynArray<Vector4> movePositions; // F0
    Vector4 sourcePosition; // 100
    float radius; // 110
    float detection; // 114
    game::data::StimPropagation stimPropagation; // 118
    uint8_t unk11C[0x120 - 0x11C]; // 11C
    Handle<sense::StimuliData> data; // 120
    game::data::StimType stimType; // 130
    bool purelyDirect; // 134
    uint8_t unk135[0x140 - 0x135]; // 135
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(StimuliEvent, 0x140);
RED4EXT_ASSERT_OFFSET(StimuliEvent, stimInvestigateData, 0x50);
RED4EXT_ASSERT_OFFSET(StimuliEvent, sourceObject, 0xD0);
RED4EXT_ASSERT_OFFSET(StimuliEvent, stimRecord, 0xE0);
RED4EXT_ASSERT_OFFSET(StimuliEvent, movePositions, 0xF0);
RED4EXT_ASSERT_OFFSET(StimuliEvent, sourcePosition, 0x100);
RED4EXT_ASSERT_OFFSET(StimuliEvent, radius, 0x110);
RED4EXT_ASSERT_OFFSET(StimuliEvent, detection, 0x114);
RED4EXT_ASSERT_OFFSET(StimuliEvent, stimPropagation, 0x118);
RED4EXT_ASSERT_OFFSET(StimuliEvent, data, 0x120);
RED4EXT_ASSERT_OFFSET(StimuliEvent, stimType, 0x130);
RED4EXT_ASSERT_OFFSET(StimuliEvent, purelyDirect, 0x134);
#else
RED4EXT_ASSERT_SIZE(StimuliEvent, 0x140);
#endif
} // namespace sense
using senseStimuliEvent = sense::StimuliEvent;
using StimuliEvent = sense::StimuliEvent;
} // namespace RED4ext

// clang-format on
