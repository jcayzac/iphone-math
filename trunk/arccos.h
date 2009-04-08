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
//
// This is how I compute arccos(x):
// 	float u;
// 	if (abs(x)<0.75) {
// 		u=(pi/2 - 1.05199081698724154807*abs(x));
// 	}
// 	else {
// 		u=2*sqrt(1-sqrt(abs(x)));
// 	}
// 	if (x<0) return (pi-u);
// 	else return u;
static inline float arccos_radians(float x) {
	union { float f; unsigned int b; } z;
	z.f=x;
	bool x_is_negative = (z.b&0x80000000);
	z.b&=0x7fffffff;
	float s=sqrtf(z.f);
	float u=1.57079632679489661923f-1.05199081698724154807f*z.f;
	u=(z.b<0x3f400000)?u:2.f*sqrtf(1.f-s);
	return x_is_negative?3.14159265358979323846f-u:u;
}

static inline float arccos_degrees(float x) {
	return 57.29577951308232087684f*arccos_radians(x);
}

#endif // ARCCOS_INCLUDED

