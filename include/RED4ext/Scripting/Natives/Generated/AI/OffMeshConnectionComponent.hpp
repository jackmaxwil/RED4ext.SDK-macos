#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/DynArray.hpp>
#include <RED4ext/NativeTypes.hpp>
#include <RED4ext/Scripting/Natives/Generated/NavGenAgentSize.hpp>
#include <RED4ext/Scripting/Natives/Generated/ent/IComponent.hpp>

namespace RED4ext
{
namespace AI
{
struct OffMeshConnectionComponent : ent::IComponent
{
    static constexpr const char* NAME = "AIOffMeshConnectionComponent";
    static constexpr const char* ALIAS = "OffMeshConnectionComponent";

#ifdef __APPLE__
    uint8_t unk8D[0x90 - 0x8D]; // 8D
    DynArray<NodeRef> offMeshConnectionNodesRefs; // 90
    uint8_t unkA0[0xE0 - 0xA0]; // A0
    NavGenAgentSize agentSize; // E0
    uint8_t unkE4[0xE8 - 0xE4]; // E4
#else
    DynArray<NodeRef> offMeshConnectionNodesRefs; // 90
    uint8_t unkA0[0xE0 - 0xA0]; // A0
    NavGenAgentSize agentSize; // E0
    uint8_t unkE4[0xE8 - 0xE4]; // E4
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(OffMeshConnectionComponent, 0xE8);
RED4EXT_ASSERT_OFFSET(OffMeshConnectionComponent, offMeshConnectionNodesRefs, 0x90);
RED4EXT_ASSERT_OFFSET(OffMeshConnectionComponent, agentSize, 0xE0);
#else
RED4EXT_ASSERT_SIZE(OffMeshConnectionComponent, 0xE8);
#endif
} // namespace AI
using AIOffMeshConnectionComponent = AI::OffMeshConnectionComponent;
using OffMeshConnectionComponent = AI::OffMeshConnectionComponent;
} // namespace RED4ext

// clang-format on
