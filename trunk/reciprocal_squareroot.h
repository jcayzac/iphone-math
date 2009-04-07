#if !defined(RECIPROCAL_SQUAREROOT_INCLUDED)
#define RECIPROCAL_SQUAREROOT_INCLUDED

/// Compute 1.f/sqrtf(x)
/// Maximum relative error: 3.44%
/// (Good enough for vector normalization)
///
/// @return 1.f/sqrt(x)
static inline float reciprocal_squareroot_fast(float x) { 
	union { float f; int b; } z;
	z.f = x;
	z.b = 0x5f3759df - (z.b>>1);
	return z.f;
}

/// Compute 1.f/sqrtf(x)
/// Maximum relative error: 0.17%
///
/// @return 1.f/sqrt(x)
static inline float reciprocal_squareroot_fast(float x) { 
	float coarse = reciprocal_squareroot_fast(x);
	return coarse*(1.5f-0.5f*x*coarse*coarse);
}

#endif // RECIPROCAL_SQUAREROOT_INCLUDED

