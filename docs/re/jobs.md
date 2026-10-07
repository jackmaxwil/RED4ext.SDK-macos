# RE results: group "jobs" (macOS 2.3.1 arm64)

All 11 old DB values are wrong. Four of them (0x9D7D00, 0x9D7BF8, 0x9D7CD4, 0x9D7D18) are not even function starts. The rest point at unrelated functions in the Dispatcher dtor/dump/deadlock-assert cluster (0x1009d7b24..0x1009d7f08). None of these functions is exported (nm only has job:: templates such as JobShim::RunJob, DispatchJob<>::s_instrumentationObject and PoolStorageProxy). The evidence is structural: the dispatcher global's init/shutdown, the jobDispatcher.cpp assert strings, the struct layouts that match the SDK, and call-site patterns. Every new function address is in LC_FUNCTION_STARTS of the Steam binary (`dyld_info -function_starts`).

| name | hash | old | new seg:off (absolute) | verdict | arm64 signature vs plugin declaration |
|---|---|---|---|---|---|
| JobDispatcher | 1508445968 | 1:0x9D7D00 (code, mid-fn) | **3:0x1A33FF0** (0x108DC7FF0, `__DATA,__common`) | confirmed | data: `job::Dispatcher*` global. SDK `UniversalRelocPtr<void*>` dereferences it, OK |
| JobDispatcher_DispatchJob | 2621709954 | 1:0x9D7D70 | **1:0x9D8690** (0x1009D8690) | confirmed | `(Dispatcher*, const JobInstance&, u8 prio, Counter* wait, Counter* signal)` matches SDK. Returns void; SDK says uint32, which is harmless because the result is ignored |
| JobHandle_Join | 2627471740 | 1:0x9D7CD4 (mid-fn) | **1:0x9D4A3C** (0x1009D4A3C) | confirmed | `void(Counter* this, const Counter& other)` matches |
| JobHandle_Wait | 1576079097 | 1:0x22575C0 (unrelated fn) | **1:0x9D479C** (0x1009D479C) | confirmed | `bool(Counter&)` matches. Callee brk-asserts unless called on the main thread and not from a job |
| JobHandle_dtor | 2655521326 | 1:0x9D7BF8 (mid-fn) | **1:0x9D4A00** (0x1009D4A00) | confirmed | `Counter* (Counter* this)` (Apple ABI dtor returns this); SDK `void(JobHandle*)` is OK |
| JobInternalHandle_Acquire | 1862212562 | 1:0x9D7D18 (mid-fn) | **1:0x9D8388** (0x1009D8388) | confirmed | **MISMATCH**: arm64 is `Counter* (Dispatcher* unused, const char* name, uintptr unk)`. SDK calls `(nullptr, aUnk)`, so aUnk lands in `name` and garbage x2 is stored at internal+0x10 |
| JobQueue_Capture | 69014212 | 1:0x9D7E88 | **1:0x9D4590** (0x1009D4590) | confirmed | **MISMATCH (dangerous)**: returns `job::Counter` by value through **x8** (sret, non-trivially-copyable 8-byte class). SDK passes the out-pointer in x1, leaving x8 undefined |
| JobQueue_SyncWait | 3651996672 | 1:0x9D7E88 (shared) | **1:0x9D451C** (0x1009D451C) | confirmed | `void(Builder*)` matches |
| JobQueue_ctor_FromGroup | 242552139 | 1:0x9D7DD4 | **1:0x9D4374** (0x1009D4374) | confirmed | `Builder* (Builder*, const RunContext&)` matches |
| JobQueue_ctor_FromParams | 2193429752 | 1:0x9D7DD4 (shared) | **1:0x9D40C8** (0x1009D40C8) | confirmed | `Builder* (Builder*, u8 prio, u8 threadParam, uintptr unk)` matches `(JobQueue*, u8, u8, u64)` |
| JobQueue_dtor | 1525942140 | 1:0x9D7E88 (shared) | **1:0x9D4660** (0x1009D4660) | confirmed | `Builder* (Builder*)`; SDK `void(JobQueue*)` is OK |

Identical-body twins exist (Apple emits C1/C2 or D1/D2, and ICF did not fold them). I picked the twin the game actually calls. Either twin is functionally equivalent:
- FromParams 0x1009D4020 / **0x1009D40C8** (0 / 2 callers)
- FromGroup 0x1009D42A8 / **0x1009D4374** (0 / 283)
- SyncWait 0x1009D4440 / **0x1009D451C** (0 / 961)
- ~Counter 0x1009D49C4 / **0x1009D4A00** (0 / 448)
- ~Builder **0x1009D4660** / 0x1009D46EC (`b 0x1009D4660`, 508 callers)

## Evidence

**JobDispatcher → 0x108DC7FF0 (__common)**
- Init at 0x1009E5E68 calls the allocator with (0xB80, align 0x80), runs ctor 0x1009D7994, then `str x20, [0x108DC7FF0]`. Shutdown at 0x1009E5EBC calls the dtor 0x1009D7C04, frees, and stores xzr. The dispatcher field offsets used elsewhere (0xB0C thread count, 0xB2C) fit the 0xB80 size.
- 30 ADRP+ADD refs, all in the job module: 0x1009D46F0..0x1009D4AD4, 0x1009D6A80..0x1009D6F40, 0x1009E5E68..0x1009E5F24.

**DispatchJob → 0x1009D8690**
- Every inlined `job::DispatchJob<…>` instantiation builds a JobInstance on the stack: handler = `JobShim<…>::RunJob` (via GOT), target, family = `DispatchJob<…>::s_instrumentationObject` (0x40 bytes, guard at +0x40), and unk18 = 0. This is the SDK JobInstance/JobFamily layout. Example: FlowAllocBatcher site 0x100EF6A14.
- That instance goes to wrapper 0x1009D46F0, which does `x0 = *0x108DC7FF0; x3 = *wait; x4 = *signal; b 0x1009D8690`.
- 0x1009D8690: if signal is set, it atomically increments signal+0x18 (pending) and, on 0→1, increments refcount +0x1C. It then tail-calls 0x1009D8720, which either parks the job on wait's list or pushes it to the priority queue at dispatcher+0x80.

**JobHandle_Join → 0x1009D4A3C**
- `(x0 = this Counter&, x1 = other)`. If `IsDone(*other)` (0x1009D8428 checks +0x18 == 0), it returns.
- Otherwise it builds an "EmptyJob" instance via 0x1009D8660 and calls `DispatchJob(disp, &inst, prio 3, wait = *other, signal = *this)`.
- `job::Builder::Wait` (0x1009D4588) is `add x0, x0, #0x10; b 0x1009D4A3C`, which is exactly the SDK's inline `JobQueue::Wait` (`unk10.Join`). 161 + 328 callers.

**JobHandle_Wait → 0x1009D479C**
- `(Counter& x0)`: computes n = `[disp+0xB0C]`, then tail-calls 0x1009D885C(disp, *x0, 1, -1, n < 3).
- 0x1009D885C is `Dispatcher::FlushCounter`. Its failure path 0x1009DA860 asserts jobDispatcher.cpp:1720 "Can only FlushCounter() from the main thread BUT NOT from any job…" (0x106C48FE9), and on success it returns w0 = 1.
- It is the only one-argument Counter wait wrapper (0x1009D475C and 0x1009D477C take 3 args).
- The old 0x1022575C0 is an unrelated function that builds a Builder on its stack: refuted.

**JobHandle_dtor → 0x1009D4A00**
- `ldr x1, [x0]; if (x1) Release(disp, x1); str xzr, [x0]; return x0`.
- Release 0x1009D80EC decrements +0x1C and frees on zero.
- 448 callers, including the stack Counter in the job runner at 0x1009D81D4.

**JobInternalHandle_Acquire → 0x1009D8388**
- Allocates 0x28 bytes (the size of SDK JobInternalHandle), zeroes it, sets refcount +0x1C = 1 and byte +0x21 = 0xFF, and stores `[+0x8] = x1` (name) and `[+0x10] = x2` (unk). x0 is ignored.
- Only callers are the Counter ctors 0x1009D47E4/0x1009D4824/0x1009D4884/0x1009D48E0. These always pass `(disp, "" @0x106C16670, unk)`.

**JobQueue_Capture → 0x1009D4590**
- The prologue does `mov x19, x8` before any write to x8, so this is an sret.
- It finalizes the same way as 0x1009D44AC, then `*x8 = move(this->wait @+0x10)` (0x1009D4874: `[x0] = [x1]; [x1] = 0`) and sets `this+0x30 (captured) = 1`.
- If a parent Counter* is at +0x20, it builds a temporary Counter, Joins it to the parent and move-assigns it into *x8.
- 129 callers.

**JobQueue_SyncWait → 0x1009D451C**
- If `!IsDone(signal@+0x18)`: `wait@+0x10 = move(signal)`, then `signal = Counter(this->unk08)`, then copies the param byte from +0x29.
- Call sites always show `bl 0x1009D46F0` (dispatch with `[b+0x28]`, b+0x10, b+0x18) immediately followed by `bl 0x1009D451C` on the same Builder (e.g. 0x100946BF0/0x100946BF8). This is the SDK `Dispatch()` = `DispatchJob + SyncWait` pattern. 961 callers.

**JobQueue_ctor_FromGroup → 0x1009D4374**
- Reads `ctx+0x30` (prio byte) and `Counter* ctx+0x20`, and takes the thread param from counter+0x21 and unk from counter+0x10.
- Fills the Builder: name "", unk08, Counter wait@0x10, Counter signal@0x18, parent@0x20, prio@0x28, param@0x29, 0@0x2C, captured@0x30. This is exactly the SDK JobQueue 0x38 layout.

**JobQueue_ctor_FromParams → 0x1009D40C8**
- `(this, w1 → +0x28, w2 → +0x29 (0xFF means read the TLS job param via 0x1009E5FBC), x3 → +0x08 and both Counter ctors)`.
- The one-byte variant 0x1009D420C `(this, prio, unk)` with param fixed at 0xFF is a different overload. The game uses it (224 callers), but it is not the SDK one.

**JobQueue_dtor → 0x1009D4660**
- If not captured (+0x30 == 0), it runs the same finalize and Joins the parent. It then runs `~Counter(+0x18)`, `~Counter(+0x10)` and returns this.

## Signature problems / dangers (SDK `include/RED4ext/JobQueue-inl.hpp`)
1. **JobQueue_Capture (crash/corruption).** The SDK calls `JobHandle* (*)(JobQueue*, JobHandle*)` as `func(this, &handle)`. On arm64 the game writes the result through x8, which the SDK never sets. ArchiveXL calls this in Mesh/Extension.cpp:258 and :261. Fix on macOS: `using func_t = JobHandle (*)(JobQueue*); return func(this);`. clang passes sret in x8 because JobHandle is non-trivial, and the destination must be uninitialized storage because the game move-constructs into it.
2. **JobInternalHandle_Acquire.** The SDK calls `(nullptr, aUnk)`, but the game reads `(x0 ignored, x1 = name, x2 = unk)`. The result is name = aUnk (usually NULL rather than "") and a garbage x2 stored at +0x10, which `ctor_FromGroup` later copies into the Builder and its new Counters. Fix: `func(nullptr, "", aUnk)` with `JobInternalHandle* (*)(void*, const char*, uintptr_t)`. Alternatively call the Counter ctor 0x1009D4824 `(JobHandle* this, uintptr unk)` directly.
3. **Not in the DB, but related: `JobClosure::HandleTarget`.** It calls `SetLocalThreadParam(aGroup.params.unk02)`, which reads RunContext+0x32. On macOS the RunContext built by the runner 0x1009D812C writes only one byte at +0x30, so +0x32 is uninitialized stack. The game's own shims instead read the byte at `(*(Counter*)(ctx+0x20))+0x21` (0x1009D4AF8) and write it to the thread-local byte at `__thread_vars` 0x1074BCF50 (0x1009E5F94).
   - 2026-10-07: 0x1009E5F94 is now `JobInternals_SetLocalThreadParam` (verified, evidence in `docs/ADDRESS_AUDIT.md`), and the SDK's `SetLocalThreadParam` calls it on macOS. `HandleTarget` still passes RunContext+0x32 and must be changed to pass Counter+0x21 on macOS.
4. JobHandle_Wait asserts (brk) when not on the main thread or when called from inside a job.
