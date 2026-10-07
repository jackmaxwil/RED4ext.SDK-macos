#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/Containers/DynArray.hpp>
#include <RED4ext/Handle.hpp>
#include <RED4ext/Scripting/Natives/Generated/CResource.hpp>
#include <RED4ext/Scripting/Natives/Generated/scn/ActorDef.hpp>
#include <RED4ext/Scripting/Natives/Generated/scn/DebugSymbols.hpp>
#include <RED4ext/Scripting/Natives/Generated/scn/EffectDef.hpp>
#include <RED4ext/Scripting/Natives/Generated/scn/EffectInstance.hpp>
#include <RED4ext/Scripting/Natives/Generated/scn/EntryPoint.hpp>
#include <RED4ext/Scripting/Natives/Generated/scn/ExecutionTag.hpp>
#include <RED4ext/Scripting/Natives/Generated/scn/ExecutionTagEntry.hpp>
#include <RED4ext/Scripting/Natives/Generated/scn/ExitPoint.hpp>
#include <RED4ext/Scripting/Natives/Generated/scn/InterruptionScenario.hpp>
#include <RED4ext/Scripting/Natives/Generated/scn/LocalMarker.hpp>
#include <RED4ext/Scripting/Natives/Generated/scn/NotablePoint.hpp>
#include <RED4ext/Scripting/Natives/Generated/scn/PlayerActorDef.hpp>
#include <RED4ext/Scripting/Natives/Generated/scn/PropDef.hpp>
#include <RED4ext/Scripting/Natives/Generated/scn/ReferencePointDef.hpp>
#include <RED4ext/Scripting/Natives/Generated/scn/RidResourceHandler.hpp>
#include <RED4ext/Scripting/Natives/Generated/scn/SRRefCollection.hpp>
#include <RED4ext/Scripting/Natives/Generated/scn/SceneCategoryTag.hpp>
#include <RED4ext/Scripting/Natives/Generated/scn/SceneSolutionHash.hpp>
#include <RED4ext/Scripting/Natives/Generated/scn/SceneVOInfo.hpp>
#include <RED4ext/Scripting/Natives/Generated/scn/WorkspotInstance.hpp>
#include <RED4ext/Scripting/Natives/Generated/scn/loc/LocStoreEmbedded.hpp>
#include <RED4ext/Scripting/Natives/Generated/scn/screenplay/Store.hpp>

namespace RED4ext
{
namespace scn { struct SceneGraph; }
namespace scn { struct WorkspotData; }

namespace scn
{
struct SceneResource : CResource
{
    static constexpr const char* NAME = "scnSceneResource";
    static constexpr const char* ALIAS = NAME;

#ifdef __APPLE__
    uint8_t unk39[0x40 - 0x39]; // 39
    DynArray<scn::EntryPoint> entryPoints; // 40
    DynArray<scn::ExitPoint> exitPoints; // 50
    DynArray<scn::NotablePoint> notablePoints; // 60
    DynArray<scn::ExecutionTagEntry> executionTagEntries; // 70
    DynArray<scn::ActorDef> actors; // 80
    DynArray<scn::PlayerActorDef> playerActors; // 90
    DynArray<scn::LocalMarker> localMarkers; // A0
    DynArray<scn::PropDef> props; // B0
    DynArray<scn::RidResourceHandler> ridResources; // C0
    DynArray<Handle<scn::WorkspotData>> workspots; // D0
    DynArray<scn::WorkspotInstance> workspotInstances; // E0
    DynArray<scn::SceneVOInfo> voInfo; // F0
    DynArray<scn::EffectDef> effectDefinitions; // 100
    DynArray<scn::EffectInstance> effectInstances; // 110
    DynArray<scn::ExecutionTag> executionTags; // 120
    DynArray<scn::ReferencePointDef> referencePoints; // 130
    DynArray<scn::InterruptionScenario> interruptionScenarios; // 140
    scn::SRRefCollection resouresReferences; // 150
    Handle<scn::SceneGraph> sceneGraph; // 230
    scn::screenplay::Store screenplayStore; // 240
    scn::loc::LocStoreEmbedded locStore; // 260
    uint32_t version; // 280
    uint8_t unk284[0x288 - 0x284]; // 284
    scn::SceneSolutionHash sceneSolutionHash; // 288
    scn::SceneCategoryTag sceneCategoryTag; // 290
    uint8_t unk291[0x298 - 0x291]; // 291
    scn::DebugSymbols debugSymbols; // 298
#else
    DynArray<scn::EntryPoint> entryPoints; // 40
    DynArray<scn::ExitPoint> exitPoints; // 50
    DynArray<scn::NotablePoint> notablePoints; // 60
    DynArray<scn::ExecutionTagEntry> executionTagEntries; // 70
    DynArray<scn::ActorDef> actors; // 80
    DynArray<scn::PlayerActorDef> playerActors; // 90
    DynArray<scn::LocalMarker> localMarkers; // A0
    DynArray<scn::PropDef> props; // B0
    DynArray<scn::RidResourceHandler> ridResources; // C0
    DynArray<Handle<scn::WorkspotData>> workspots; // D0
    DynArray<scn::WorkspotInstance> workspotInstances; // E0
    DynArray<scn::SceneVOInfo> voInfo; // F0
    DynArray<scn::EffectDef> effectDefinitions; // 100
    DynArray<scn::EffectInstance> effectInstances; // 110
    DynArray<scn::ExecutionTag> executionTags; // 120
    DynArray<scn::ReferencePointDef> referencePoints; // 130
    DynArray<scn::InterruptionScenario> interruptionScenarios; // 140
    scn::SRRefCollection resouresReferences; // 150
    Handle<scn::SceneGraph> sceneGraph; // 230
    scn::screenplay::Store screenplayStore; // 240
    scn::loc::LocStoreEmbedded locStore; // 260
    uint32_t version; // 280
    uint8_t unk284[0x288 - 0x284]; // 284
    scn::SceneSolutionHash sceneSolutionHash; // 288
    scn::SceneCategoryTag sceneCategoryTag; // 290
    uint8_t unk291[0x298 - 0x291]; // 291
    scn::DebugSymbols debugSymbols; // 298
#endif
};
#ifdef __APPLE__
RED4EXT_ASSERT_SIZE(SceneResource, 0x2D8);
RED4EXT_ASSERT_OFFSET(SceneResource, entryPoints, 0x40);
RED4EXT_ASSERT_OFFSET(SceneResource, exitPoints, 0x50);
RED4EXT_ASSERT_OFFSET(SceneResource, notablePoints, 0x60);
RED4EXT_ASSERT_OFFSET(SceneResource, executionTagEntries, 0x70);
RED4EXT_ASSERT_OFFSET(SceneResource, actors, 0x80);
RED4EXT_ASSERT_OFFSET(SceneResource, playerActors, 0x90);
RED4EXT_ASSERT_OFFSET(SceneResource, localMarkers, 0xA0);
RED4EXT_ASSERT_OFFSET(SceneResource, props, 0xB0);
RED4EXT_ASSERT_OFFSET(SceneResource, ridResources, 0xC0);
RED4EXT_ASSERT_OFFSET(SceneResource, workspots, 0xD0);
RED4EXT_ASSERT_OFFSET(SceneResource, workspotInstances, 0xE0);
RED4EXT_ASSERT_OFFSET(SceneResource, voInfo, 0xF0);
RED4EXT_ASSERT_OFFSET(SceneResource, effectDefinitions, 0x100);
RED4EXT_ASSERT_OFFSET(SceneResource, effectInstances, 0x110);
RED4EXT_ASSERT_OFFSET(SceneResource, executionTags, 0x120);
RED4EXT_ASSERT_OFFSET(SceneResource, referencePoints, 0x130);
RED4EXT_ASSERT_OFFSET(SceneResource, interruptionScenarios, 0x140);
RED4EXT_ASSERT_OFFSET(SceneResource, resouresReferences, 0x150);
RED4EXT_ASSERT_OFFSET(SceneResource, sceneGraph, 0x230);
RED4EXT_ASSERT_OFFSET(SceneResource, screenplayStore, 0x240);
RED4EXT_ASSERT_OFFSET(SceneResource, locStore, 0x260);
RED4EXT_ASSERT_OFFSET(SceneResource, version, 0x280);
RED4EXT_ASSERT_OFFSET(SceneResource, sceneSolutionHash, 0x288);
RED4EXT_ASSERT_OFFSET(SceneResource, sceneCategoryTag, 0x290);
RED4EXT_ASSERT_OFFSET(SceneResource, debugSymbols, 0x298);
#else
RED4EXT_ASSERT_SIZE(SceneResource, 0x2D8);
#endif
} // namespace scn
using scnSceneResource = scn::SceneResource;
} // namespace RED4ext

// clang-format on
