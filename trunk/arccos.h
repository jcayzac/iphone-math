#if !defined(ARCCOS_INCLUDED)
#define ARCCOS_INCLUDED

// Needed for fabsf() and sqrtf()
#include <math.h>

// iPhone timings:
//     fast_acos(): 157.5μs
//     acosf(): 435.12μs
// fast_acos() is 2.76268 times faster than acosf()
// 
// Maximum error: 0.035195 radians
// Average error: 0.010294 radians
static inline float arccos_radians(float x) {
	float u=(fabsf(x)<.5f)
		?(1.57079632679489661923-1.05199081698724154807*fabsf(x))
		:2.f*sqrtf(1.f-sqrtf(fabsf(x)));
	return (x<.0f)?3.14159265358979323846f-u:u;
}

static inline float arccos_degrees(float x) {
	return 57.29577951308232087684f*arccos_radians(x);
}

#endif // ARCCOS_INCLUDED

