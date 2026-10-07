#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/DynArray.hpp>
#include <RED4ext/Scripting/Natives/Generated/ent/IComponent.hpp>
#include <RED4ext/Scripting/Natives/Generated/game/NetrunnerPrototypeStruct.hpp>

namespace RED4ext
{
namespace game
{
struct NetrunnerPrototypeComponent : ent::IComponent
{
    static constexpr const char* NAME = "gameNetrunnerPrototypeComponent";
    static constexpr const char* ALIAS = "NetrunnerPrototypeComponent";

#ifdef __APPLE__
    uint8_t unk8D[0x90 - 0x8D]; // 8D
    DynArray<game::NetrunnerPrototypeStruct> structs; // 90
    uint8_t unkA0[0x118 - 0xA0]; // A0
#else
    DynArray<game::NetrunnerPrototypeStruct> structs; // 90
    uint8_t unkA0[0x118 - 0xA0]; // A0
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(NetrunnerPrototypeComponent, 0x118);
RED4EXT_ASSERT_OFFSET(NetrunnerPrototypeComponent, structs, 0x90);
#else
RED4EXT_ASSERT_SIZE(NetrunnerPrototypeComponent, 0x118);
#endif
} // namespace game
using gameNetrunnerPrototypeComponent = game::NetrunnerPrototypeComponent;
using NetrunnerPrototypeComponent = game::NetrunnerPrototypeComponent;
} // namespace RED4ext

// clang-format on
