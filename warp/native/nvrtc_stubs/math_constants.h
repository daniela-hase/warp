// NVRTC stub for <math_constants.h>.
// Defines the CUDART_* constants that cuBQL uses. The real NVRTC built-in
// provides these; this stub ensures they're available even without the CUDA
// toolkit headers on the include path.
#pragma once

#ifndef CUDART_INF_F
# define CUDART_INF_F __int_as_float(0x7f800000)
#endif
#ifndef CUDART_NAN_F
# define CUDART_NAN_F __int_as_float(0x7fc00000)
#endif
#ifndef CUDART_INF
# define CUDART_INF  __longlong_as_double(0x7ff0000000000000LL)
#endif
#ifndef CUDART_NAN
# define CUDART_NAN  __longlong_as_double(0x7ff8000000000000LL)
#endif
#ifndef CUDART_PI_F
# define CUDART_PI_F 3.141592653589793f
#endif
#ifndef CUDART_PI
# define CUDART_PI   3.141592653589793
#endif
