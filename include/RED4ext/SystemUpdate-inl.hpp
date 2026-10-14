#pragma once

#ifdef RED4EXT_STATIC_LIB
#include <RED4ext/SystemUpdate.hpp>
#endif

#include <RED4ext/Detail/AddressHashes.hpp>
#include <RED4ext/NativeTypes.hpp>
#include <RED4ext/Relocation.hpp>

RED4EXT_INLINE void RED4ext::UpdateRegistrar::RegisterUpdate(UpdateTickGroup aGroup, IScriptable* aSystem,
                                                             const char* aName, GroupUpdateCallback&& aCallback)
{
    using func_t = void (*)(UpdateRegistrar*, UpdateTickGroup, CClass*, const char*, GroupUpdateCallback&&, uint32_t);
    static UniversalRelocFunc<func_t> func(Detail::AddressHashes::UpdateRegistrar_RegisterGroupUpdate);

#ifdef __APPLE__
    // macOS: the last argument (w5) is stored in the update entry (+0x68), where the Windows function writes the
    // constant 0xA itself. All 128 of the game's calls of 0x103D95800 pass 0xA.
    func(this, aGroup, aSystem->GetNativeType(), aName, std::forward<GroupUpdateCallback>(aCallback), 0xA);
#else
    func(this, aGroup, aSystem->GetNativeType(), aName, std::forward<GroupUpdateCallback>(aCallback), 0);
#endif
}

RED4EXT_INLINE void RED4ext::UpdateRegistrar::RegisterUpdate(UpdateBucketMask aBuckets, UpdateBucketStage aStage,
                                                             IScriptable* aSystem, const char* aName,
                                                             BucketUpdateCallback&& aCallback)
{
    using func_t = void (*)(UpdateRegistrar*, UpdateBucketMask, UpdateBucketStage, CClass*, const char*,
                            BucketUpdateCallback&&, uint32_t);
    static UniversalRelocFunc<func_t> func(Detail::AddressHashes::UpdateRegistrar_RegisterBucketUpdate);

#ifdef __APPLE__
    // macOS: the last argument (w6) is stored in the update entry (+0x68), where the Windows function writes the
    // constant 0xD itself. All 64 of the game's calls of 0x103D95924 pass 0xD.
    func(this, aBuckets, aStage, aSystem->GetNativeType(), aName, std::forward<BucketUpdateCallback>(aCallback), 0xD);
#else
    func(this, aBuckets, aStage, aSystem->GetNativeType(), aName, std::forward<BucketUpdateCallback>(aCallback), 0);
#endif
}
