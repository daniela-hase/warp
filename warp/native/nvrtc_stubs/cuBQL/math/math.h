// NVRTC stub for cuBQL/math/math.h — device-only, no C++ stdlib dependencies.
// Mirrors the real math.h API but avoids <cuda/std/limits> and <limits>.
#pragma once

#include "cuBQL/math/common.h"

namespace cuBQL {

#ifdef __CUDACC__
  using ::min;
  using ::max;
#else
  using std::min;
  using std::max;
#endif

// Under __CUDA_ARCH__ (NVRTC device code), express infinity via a bit pattern
// so we don't need <cuda/std/limits> or <limits> at all.
#ifdef __CUDA_ARCH__
# define CUBQL_INF __int_as_float(0x7f800000)
#else
# define CUBQL_INF std::numeric_limits<float>::infinity()
#endif

#if !defined(__CUDACC__)
  inline float __int_as_float(int i) { return (const float &)i; }
  inline int   __float_as_int(float f) { return (const int &)f; }
#endif

  inline __cubql_both float squareOf(float f) { return f * f; }

  template<int N> struct log_of { enum { value = -1 }; };
  template<> struct log_of< 2> { enum { value = 1 }; };
  template<> struct log_of< 4> { enum { value = 2 }; };
  template<> struct log_of< 8> { enum { value = 3 }; };
  template<> struct log_of<16> { enum { value = 4 }; };
  template<> struct log_of<32> { enum { value = 5 }; };

  inline __cubql_both float  sqr(float f)    { return f * f; }
  inline __cubql_both float  rcp(float f)    { return 1.f / f; }
  inline __cubql_both double rcp(double d)   { return 1. / d; }

  template<typename T>
  inline __cubql_both T clamp(T t, T lo = T(0), T hi = T(1))
  { return min(max(t, lo), hi); }

  inline __cubql_both float  saturate(float f)  { return clamp(f, 0.f, 1.f); }
  inline __cubql_both double saturate(double f) { return clamp(f, 0., 1.); }

} // ::cuBQL
