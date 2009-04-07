#if !defined(SIN_INCLUDED)
#define SIN_INCLUDED

// Needed for fabsf()
#include <math.h>

/// Generic functions for computing sin(x), depending on angle unit.
/// Algorithm by Nicolas Capens
/// @sa http://www.devmaster.net/forums/showthread.php?t=5784
/// 
/// @param x an angle
/// @param a 4.0/(value for an angle of Pi radians)
/// @param b 4.0/(same value, squared)
/// @return sin(x)
static inline float sin_kernel(float x, float a, float b) {
        x = (a - b*fabsf(x))*x;
        return x*(0.225f*fabsf(x) + 0.775f);
}

/// Computes sin(x), for any x in degrees betweeb -180.f and 180.f.
/// Result is undefined outside this range.
/// @param x angle in degrees
/// @return sin(x)
static inline float sin_degrees(float x) {
        return sin_kernel(x,.02222222222222222222f,.00012345679012345679f);
}

/// Computes sin(x), for any x in radians betweeb -Pi and Pi.
/// Result is undefined outside this range.
/// @param x angle in radians
/// @return sin(x)
static inline float sin_radians(float x) {
        return sin_kernel(x,1.27323954473516268615f,.40528473456935108577f);
}

#endif // SIN_INCLUDED

