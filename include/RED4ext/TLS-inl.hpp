#pragma once

#ifdef RED4EXT_STATIC_LIB
#include <RED4ext/TLS.hpp>
#endif

#if defined(_WIN32) || defined(_WIN64)
#include <intrin.h>

RED4EXT_INLINE RED4ext::TLS* RED4ext::TLS::Get()
{
    return *reinterpret_cast<TLS**>(__readgsqword(0x58));
}

RED4EXT_INLINE bool RED4ext::TLS::IsInitialized()
{
    return Get() != nullptr;
}

#elif defined(__APPLE__)
// The macOS game keeps its per-thread engine state in C++ thread_local variables (__thread_vars), not in a block
// reachable from a fixed register like the Windows TEB slot, so there is no TLS block with the Windows layout to
// return. Guessing one (e.g. by scanning pthread keys) would let callers write into unrelated memory.
RED4EXT_INLINE RED4ext::TLS* RED4ext::TLS::Get()
{
    return nullptr;
}

RED4EXT_INLINE bool RED4ext::TLS::IsInitialized()
{
    return false;
}

#else

RED4EXT_INLINE RED4ext::TLS* RED4ext::TLS::Get()
{
    return nullptr;
}

RED4EXT_INLINE bool RED4ext::TLS::IsInitialized()
{
    return false;
}

#endif
