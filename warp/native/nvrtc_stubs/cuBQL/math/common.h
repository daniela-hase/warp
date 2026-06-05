// NVRTC-safe stub for cuBQL/math/common.h.
// Replaces the real header (which pulls in math.h, iostream, string, etc.)
// with only the macros/types the traversal code actually needs.
#pragma once

#if defined(__CUDACC__)
# define __cubql_device   __device__
# define __cubql_host     __host__
#else
# define __cubql_device
# define __cubql_host
#endif
#define __cubql_both __cubql_host __cubql_device

#ifdef _MSC_VER
# define CUBQL_ALIGN(a) __declspec(align(a))
#else
# define CUBQL_ALIGN(a) __attribute__((aligned(a)))
#endif

#ifdef __GNUC__
# define MAYBE_UNUSED __attribute__((unused))
#else
# define MAYBE_UNUSED
#endif

#ifndef PRIu64
# define PRIu64 "llu"
#endif
#ifndef PRId64
# define PRId64 "lld"
#endif

// Pull in stub headers that vec.h and box.h use through std:: (they get them
// transitively from <iostream>/<string> in the real common.h).
#include <string>
#include <ostream>

// Minimal dbgout — routes to device printf, no host iostream needed.
namespace cuBQL {
  using longlong = long long;

  inline __cubql_both int32_t  divRoundUp(int32_t  a, int32_t  b) { return (a+b-1)/b; }
  inline __cubql_both uint32_t divRoundUp(uint32_t a, uint32_t b) { return (a+b-1)/b; }
  inline __cubql_both int64_t  divRoundUp(int64_t  a, int64_t  b) { return (a+b-1)/b; }
  inline __cubql_both uint64_t divRoundUp(uint64_t a, uint64_t b) { return (a+b-1)/b; }

  struct dbgout {
    static constexpr const char* const endl = "\n";
  };
  static constexpr const char* const endl = "\n";
  static constexpr dbgout dout = {};
  inline __cubql_both dbgout operator<<(dbgout o, const char* s) { printf("%s", s); return o; }
  inline __cubql_both dbgout operator<<(dbgout o, int i)         { printf("%d", i); return o; }
  inline __cubql_both dbgout operator<<(dbgout o, unsigned u)    { printf("%u", u); return o; }
  inline __cubql_both dbgout operator<<(dbgout o, float f)       { printf("%f", f); return o; }
  inline __cubql_both dbgout operator<<(dbgout o, double d)      { printf("%lf", d); return o; }

  inline __cubql_both float  abst(float  f) { return f < 0.f ? -f : f; }
  inline __cubql_both double abst(double f) { return f < 0.  ? -f : f; }
}

// CUBQL_INTERFACE / DLL export — not needed for device-only use
#define CUBQL_INTERFACE
#define CUBQL_DLL_EXPORT
#define CUBQL_DLL_IMPORT

#ifndef __PRETTY_FUNCTION__
# ifdef __func__
#  define __PRETTY_FUNCTION__ __func__
# else
#  define __PRETTY_FUNCTION__ __FUNCTION__
# endif
#endif
