#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/Containers/StaticArray.hpp>
#include <RED4ext/Scripting/Natives/Generated/game/state/MachineConsumableParameterBool.hpp>
#include <RED4ext/Scripting/Natives/Generated/game/state/MachineConsumableParameterCName.hpp>
#include <RED4ext/Scripting/Natives/Generated/game/state/MachineConsumableParameterDouble.hpp>
#include <RED4ext/Scripting/Natives/Generated/game/state/MachineConsumableParameterFloat.hpp>
#include <RED4ext/Scripting/Natives/Generated/game/state/MachineConsumableParameterIScriptable.hpp>
#include <RED4ext/Scripting/Natives/Generated/game/state/MachineConsumableParameterInt.hpp>
#include <RED4ext/Scripting/Natives/Generated/game/state/MachineConsumableParameterTweakDBID.hpp>
#include <RED4ext/Scripting/Natives/Generated/game/state/MachineConsumableParameterVector.hpp>
#include <RED4ext/Scripting/Natives/Generated/game/state/MachineConsumableParameterWeakIScriptable.hpp>

namespace RED4ext
{
namespace game::state
{
struct __declspec(align(0x10)) MachineStateContextConsumableParameters
{
    static constexpr const char* NAME = "gamestateMachineStateContextConsumableParameters";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
#pragma warning(suppress : 4324)
    alignas(8) StaticArray<game::state::MachineConsumableParameterBool, 128> boolParameters; // 00
#pragma warning(suppress : 4324)
    alignas(8) StaticArray<game::state::MachineConsumableParameterInt, 128> intParameters; // C08
#pragma warning(suppress : 4324)
    alignas(8) StaticArray<game::state::MachineConsumableParameterFloat, 128> floatParameters; // 1810
#pragma warning(suppress : 4324)
    alignas(8) StaticArray<game::state::MachineConsumableParameterDouble, 128> doubleParameters; // 2418
#pragma warning(suppress : 4324)
    alignas(16) StaticArray<game::state::MachineConsumableParameterVector, 128> vectorParameters; // 3420
#pragma warning(suppress : 4324)
    alignas(8) StaticArray<game::state::MachineConsumableParameterCName, 128> CNameParameters; // 4C30
#pragma warning(suppress : 4324)
    alignas(8) StaticArray<game::state::MachineConsumableParameterIScriptable, 128> IScriptableParameters; // 5C38
#pragma warning(suppress : 4324)
    alignas(8) StaticArray<game::state::MachineConsumableParameterWeakIScriptable, 128> weakIScriptableParameters; // 7040
#pragma warning(suppress : 4324)
    alignas(8) StaticArray<game::state::MachineConsumableParameterTweakDBID, 128> tweakDBIDParameters; // 8448
#else
#pragma warning(suppress : 4324)
    alignas(8) StaticArray<game::state::MachineConsumableParameterBool, 128> boolParameters; // 00
#pragma warning(suppress : 4324)
    alignas(8) StaticArray<game::state::MachineConsumableParameterInt, 128> intParameters; // 1008
#pragma warning(suppress : 4324)
    alignas(8) StaticArray<game::state::MachineConsumableParameterFloat, 128> floatParameters; // 2010
#pragma warning(suppress : 4324)
    alignas(8) StaticArray<game::state::MachineConsumableParameterDouble, 128> doubleParameters; // 3018
#pragma warning(suppress : 4324)
    alignas(16) StaticArray<game::state::MachineConsumableParameterVector, 128> vectorParameters; // 4020
#pragma warning(suppress : 4324)
    alignas(8) StaticArray<game::state::MachineConsumableParameterCName, 128> CNameParameters; // 6030
#pragma warning(suppress : 4324)
    alignas(8) StaticArray<game::state::MachineConsumableParameterIScriptable, 128> IScriptableParameters; // 7038
#pragma warning(suppress : 4324)
    alignas(8) StaticArray<game::state::MachineConsumableParameterWeakIScriptable, 128> weakIScriptableParameters; // 8440
#pragma warning(suppress : 4324)
    alignas(8) StaticArray<game::state::MachineConsumableParameterTweakDBID, 128> tweakDBIDParameters; // 9848
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(MachineStateContextConsumableParameters, 0x9450);
RED4EXT_ASSERT_OFFSET(MachineStateContextConsumableParameters, boolParameters, 0x0);
RED4EXT_ASSERT_OFFSET(MachineStateContextConsumableParameters, intParameters, 0xC08);
RED4EXT_ASSERT_OFFSET(MachineStateContextConsumableParameters, floatParameters, 0x1810);
RED4EXT_ASSERT_OFFSET(MachineStateContextConsumableParameters, doubleParameters, 0x2418);
RED4EXT_ASSERT_OFFSET(MachineStateContextConsumableParameters, vectorParameters, 0x3420);
RED4EXT_ASSERT_OFFSET(MachineStateContextConsumableParameters, CNameParameters, 0x4C30);
RED4EXT_ASSERT_OFFSET(MachineStateContextConsumableParameters, IScriptableParameters, 0x5C38);
RED4EXT_ASSERT_OFFSET(MachineStateContextConsumableParameters, weakIScriptableParameters, 0x7040);
RED4EXT_ASSERT_OFFSET(MachineStateContextConsumableParameters, tweakDBIDParameters, 0x8448);
#else
RED4EXT_ASSERT_SIZE(MachineStateContextConsumableParameters, 0xA850);
#endif
} // namespace game::state
using gamestateMachineStateContextConsumableParameters = game::state::MachineStateContextConsumableParameters;
} // namespace RED4ext

// clang-format on
