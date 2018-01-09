#ifndef VECT4D_SIMD_H
#define VECT4D_SIMD_H

#include <xmmintrin.h>
#include <smmintrin.h>  

#define UNUSED_VAR(v) ((void )v)

class Matrix_SIMD;

class Vect4D_SIMD
{
public:

	Vect4D_SIMD()
	{
		this->_m = _mm_setzero_ps();
	};

	Vect4D_SIMD(const Vect4D_SIMD &tmp)
	{
		this->_m = _mm_setr_ps(tmp.x, tmp.y, tmp.z, tmp.w);
	}

	Vect4D_SIMD(const float tx, const float ty, const float tz, const float tw)
	{
		this->_m = _mm_setr_ps(tx, ty, tz, tw);
	}

	~Vect4D_SIMD()
	{
	};

	void operator = (const Vect4D_SIMD &tmp)
	{
		this->_m = _mm_setr_ps(tmp.x, tmp.y, tmp.z, tmp.w);
	}

	void set(const float xVal, const float yVal, const float zVal, const float wVal)
	{
		this->_m = _mm_setr_ps(xVal, yVal, zVal, wVal);
	}

	friend inline Vect4D_SIMD operator + (const Vect4D_SIMD &tmp1, const Vect4D_SIMD &tmp2)
	{
		Vect4D_SIMD result;
		result._m = _mm_add_ps(tmp1._m, tmp2._m);
		return result;
	}

	void operator += (const Vect4D_SIMD &tmp)
	{
		this->_m = _mm_add_ps(this->_m, tmp._m);
	}

	friend inline Vect4D_SIMD operator - (const Vect4D_SIMD &tmp1, const Vect4D_SIMD &tmp2)
	{
		Vect4D_SIMD result;
		result._m = _mm_sub_ps(tmp1._m, tmp2._m);
		return result;
	}

	void operator -= (const Vect4D_SIMD &tmp)
	{
		this->_m = _mm_sub_ps(this->_m, tmp._m);
	}

	friend inline Vect4D_SIMD operator * (const Vect4D_SIMD &tmp1, const Vect4D_SIMD &tmp2)
	{
		Vect4D_SIMD result; 
		result._m =_mm_mul_ps(tmp1._m, tmp2._m);
		return result;
	}

	void operator *= (const Vect4D_SIMD &tmp)
	{
		this->_m = _mm_mul_ps(this->_m, tmp._m);
	}

	friend inline Vect4D_SIMD operator / (const Vect4D_SIMD &tmp1, const Vect4D_SIMD &tmp2)
	{
		Vect4D_SIMD result; 
		result._m = _mm_div_ps(tmp1._m, tmp2._m);
		return result;
	}

	void operator /= (const Vect4D_SIMD &tmp)
	{
		this->_m = _mm_div_ps(this->_m, tmp._m);
	}

	const float dot(const Vect4D_SIMD &tmp) const
	{
		//return _mm_dp_ps(this->_m, tmp._m, 0xF1).m128_f32[0];
		return _mm_hadd_ps(_mm_hadd_ps(_mm_mul_ps(this->_m, tmp._m), _mm_setzero_ps()), _mm_setzero_ps()).m128_f32[0];
	}

	
	// Vect * Matrix done in Matrix_SIMD.h in VmultM proxy struct
	//Vect4D_SIMD Vect4D_SIMD::operator * (const Matrix_SIMD &M);


public:

	// anonymous union
	union
	{
		__m128	_m;

		// anonymous struct
		struct
		{
			float x;
			float y;
			float z;
			float w;
		};

	};
};

#endif



