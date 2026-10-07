#pragma once

#ifdef RED4EXT_STATIC_LIB
#include <RED4ext/SharedSpinLock.hpp>
#endif

#include <cstdint>

#if defined(_WIN32) || defined(_WIN64)
#include <intrin.h>
#include <Windows.h>
#else
#include <RED4ext/Detail/WinCompat.hpp>
#endif

#ifdef __APPLE__
#include <sched.h>
#endif

RED4EXT_INLINE RED4ext::SharedSpinLock::SharedSpinLock()
    : state(0)
{
}

#ifdef __APPLE__
// macOS build (verified against the game's own lock routines at 0x100002098-0x100002128 and their inlined unlocks):
// bit 7 is the writer flag and the low 7 bits count readers. A reader increments first and then waits for the writer
// to leave; a writer waits for 0, takes 0x80, and releases by clearing only bit 7 so pending reader counts survive.
// This differs from the Windows encoding (-1 = writer), so the two must never be mixed on one lock.
RED4EXT_INLINE bool RED4ext::SharedSpinLock::TryLock()
{
    char expected = 0;
    return __atomic_compare_exchange_n(&state, &expected, static_cast<char>(0x80), false, __ATOMIC_ACQ_REL,
                                       __ATOMIC_ACQUIRE);
}

RED4EXT_INLINE void RED4ext::SharedSpinLock::Lock()
{
    while (true)
    {
        while (__atomic_load_n(&state, __ATOMIC_ACQUIRE) != 0)
        {
            sched_yield();
        }
        if (TryLock())
            break;
    }
}

RED4EXT_INLINE void RED4ext::SharedSpinLock::Unlock()
{
    __atomic_fetch_and(&state, static_cast<char>(0x7F), __ATOMIC_RELEASE);
}

RED4EXT_INLINE bool RED4ext::SharedSpinLock::TryLockShared()
{
    char current = __atomic_load_n(&state, __ATOMIC_ACQUIRE);
    if (current & 0x80)
        return false;
    return __atomic_compare_exchange_n(&state, &current, static_cast<char>(current + 1), false, __ATOMIC_ACQ_REL,
                                       __ATOMIC_ACQUIRE);
}

RED4EXT_INLINE void RED4ext::SharedSpinLock::LockShared()
{
    if (__atomic_fetch_add(&state, 1, __ATOMIC_ACQ_REL) & 0x80)
    {
        while (__atomic_load_n(&state, __ATOMIC_ACQUIRE) & 0x80)
        {
            sched_yield();
        }
    }
}

RED4EXT_INLINE void RED4ext::SharedSpinLock::UnlockShared()
{
    __atomic_fetch_sub(&state, 1, __ATOMIC_RELEASE);
}
#else
RED4EXT_INLINE bool RED4ext::SharedSpinLock::TryLock()
{
    return _InterlockedCompareExchange8(&state, -1, 0) == 0;
}

RED4EXT_INLINE void RED4ext::SharedSpinLock::Lock()
{
    int32_t loopCount = 0;
    while (true)
    {
        if (TryLock())
            break;

        ++loopCount;
        if (loopCount == 0x4000)
            loopCount = 0;
        else if (!(loopCount & 511))
            SwitchToThread();
    }
}

RED4EXT_INLINE void RED4ext::SharedSpinLock::Unlock()
{
    InterlockedExchange8(&state, 0);
}

RED4EXT_INLINE bool RED4ext::SharedSpinLock::TryLockShared()
{
    char currentState = state;
    if (currentState != -1)
    {
        return _InterlockedCompareExchange8(&state, currentState + 1, currentState) == currentState;
    }
    return false;
}

RED4EXT_INLINE void RED4ext::SharedSpinLock::LockShared()
{
    int32_t loopCount = 0;
    while (true)
    {
        if (TryLockShared())
            break;

        ++loopCount;
        if (loopCount == 0x4000)
            loopCount = 0;
        else if (!(loopCount & 511))
            SwitchToThread();
    }
}

RED4EXT_INLINE void RED4ext::SharedSpinLock::UnlockShared()
{
    _InterlockedExchangeAdd8(&state, -1);
}

#endif

// --------------------------------------------
// -- support for lock_guard and shared_lock --
// --------------------------------------------

RED4EXT_INLINE bool RED4ext::SharedSpinLock::try_lock()
{
    return TryLock();
}

RED4EXT_INLINE void RED4ext::SharedSpinLock::lock()
{
    Lock();
}

RED4EXT_INLINE void RED4ext::SharedSpinLock::unlock()
{
    Unlock();
}

RED4EXT_INLINE bool RED4ext::SharedSpinLock::try_lock_shared()
{
    return TryLockShared();
}

RED4EXT_INLINE void RED4ext::SharedSpinLock::lock_shared()
{
    LockShared();
}

RED4EXT_INLINE void RED4ext::SharedSpinLock::unlock_shared()
{
    UnlockShared();
}
