#include "Matrix_SIMD.h"	



Vect4D_SIMD Matrix_SIMD::operator * (const Vect4D_SIMD &v) const
{
	Vect4D_SIMD vectResult;
	vectResult._m = _mm_hadd_ps(_mm_hadd_ps(_mm_mul_ps(v._m, this->v0._m), _mm_mul_ps(v._m, this->v1._m)),
								_mm_hadd_ps(_mm_mul_ps(v._m, this->v2._m), _mm_mul_ps(v._m, this->v3._m)));
	return vectResult;
}
