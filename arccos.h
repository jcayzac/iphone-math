#if !defined(ARCCOS_INCLUDED)
#define ARCCOS_INCLUDED

// Needed for fabsf() and sqrtf()
#include <math.h>

// iPhone timings:
//     fast_acos(): 0.06ms
//     acosf():     0.44ms
// fast_acos() is 7.2 times faster than acosf()
// 
// Maximum error: 0.06 radians
// Average error: 0.01 radians
static inline float arccos_radians(float x) {
	union { float f; unsigned int b; } z;
	z.f=x;
	bool cond1 = (z.b&0x80000000); // negative?
	z.b&=0x7fffffff; // fabsf
	float s=sqrtf(z.f); // pipeline
	float u=1.57079632679489661923f-1.05199081698724154807f*z.f;
	bool cond2 = (z.b<0x3f400000); // <0.75?
	
	u=cond2?u:2.f*sqrtf(1.f-s);
	return cond1?3.14159265358979323846f-u:u;
}

static inline float arccos_degrees(float x) {
	return 57.29577951308232087684f*arccos_radians(x);
}

#endif // ARCCOS_INCLUDED

