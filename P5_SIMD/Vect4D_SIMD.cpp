#include "Vect4D_SIMD.h"
#include "Matrix_SIMD.h"

#include <xmmintrin.h>
#include <smmintrin.h> 


// Vect * Matrix done in Matrix_SIMD.h in VmultM proxy struct

//Vect4D_SIMD Vect4D_SIMD::operator * (const Matrix_SIMD &M)
//{
//	return Vect4D_SIMD(_mm_add_ps(_mm_mul_ps(_mm_set_ps1(this->x), M.v0._m),
//						_mm_add_ps(_mm_mul_ps(_mm_set_ps1(this->y), M.v1._m),
//						_mm_add_ps(_mm_mul_ps(_mm_set_ps1(this->z), M.v2._m),
//									_mm_mul_ps(_mm_set_ps1(this->w), M.v3._m)))));
//}

