#ifndef MATRIX_SIMD_H
#define MATRIX_SIMD_H

#include "Vect4D_SIMD.h"

#include <xmmintrin.h>
#include <smmintrin.h> 

#define UNUSED_VAR(v) ((void )v)

class Matrix_SIMD
{
public:
	Matrix_SIMD()
	{
		this->v0._m = _mm_setzero_ps();
		this->v1._m = _mm_setzero_ps();
		this->v2._m = _mm_setzero_ps();
		this->v2._m = _mm_setzero_ps();
	}

	Matrix_SIMD(const Vect4D_SIMD &tV0, const Vect4D_SIMD &tV1, const Vect4D_SIMD &tV2, const Vect4D_SIMD &tV3)
	{
		this->v0._m = _mm_setr_ps(tV0.x, tV0.y, tV0.z, tV0.w);
		this->v1._m = _mm_setr_ps(tV1.x, tV1.y, tV1.z, tV1.w);
		this->v2._m = _mm_setr_ps(tV2.x, tV2.y, tV2.z, tV2.w);
		this->v3._m = _mm_setr_ps(tV3.x, tV3.y, tV3.z, tV3.w);

	}

	~Matrix_SIMD()
	{
	}

	Matrix_SIMD(const Matrix_SIMD &tmp)
	{
		this->v0._m = _mm_setr_ps(tmp.v0.x, tmp.v0.y, tmp.v0.z, tmp.v0.w);
		this->v1._m = _mm_setr_ps(tmp.v1.x, tmp.v1.y, tmp.v1.z, tmp.v1.w);
		this->v2._m = _mm_setr_ps(tmp.v2.x, tmp.v2.y, tmp.v2.z, tmp.v2.w);
		this->v3._m = _mm_setr_ps(tmp.v3.x, tmp.v3.y, tmp.v3.z, tmp.v3.w);
	}

	Matrix_SIMD &operator=(const Matrix_SIMD &tmp)
	{
		this->v0._m = _mm_setr_ps(tmp.v0.x, tmp.v0.y, tmp.v0.z, tmp.v0.w);
		this->v1._m = _mm_setr_ps(tmp.v1.x, tmp.v1.y, tmp.v1.z, tmp.v1.w);
		this->v2._m = _mm_setr_ps(tmp.v2.x, tmp.v2.y, tmp.v2.z, tmp.v2.w);
		this->v3._m = _mm_setr_ps(tmp.v3.x, tmp.v3.y, tmp.v3.z, tmp.v3.w);
		return *this;
	}

	// Vect * Matrix
	Vect4D_SIMD operator * (const Vect4D_SIMD &v) const;


	/* 
	*
	*  Begin M * M * M * M * M * V  Proxy Structs 
	*
	*/


	// First Proxy MmultM
	struct MmultM
	{
		const Matrix_SIMD &mA;
		const Matrix_SIMD &mB;

		MmultM()
			: mA(Matrix_SIMD()), mB(Matrix_SIMD())
		{
		}

		MmultM(const MmultM &in)
			: mA(in.mA), mB(in.mB)
		{
		}

		MmultM & operator = (const MmultM &)
		{
			return *this;
		}

		MmultM(const Matrix_SIMD &t1, const Matrix_SIMD &t2)
			: mA(t1), mB(t2)
		{
		};

		operator Matrix_SIMD()
		{
			Matrix_SIMD m;
			// mA.v0 * mB
			m.v0._m = _mm_add_ps(_mm_mul_ps(_mm_set_ps1(mA.v0.x), mB.v0._m),
							_mm_add_ps(_mm_mul_ps(_mm_set_ps1(mA.v0.y), mB.v1._m),
							_mm_add_ps(_mm_mul_ps(_mm_set_ps1(mA.v0.z), mB.v2._m), _mm_mul_ps(_mm_set_ps1(mA.v0.w), mB.v3._m))));
			// mA.v1 * mB
			m.v1._m = _mm_add_ps(_mm_mul_ps(_mm_set_ps1(mA.v1.x), mB.v0._m),
							_mm_add_ps(_mm_mul_ps(_mm_set_ps1(mA.v1.y), mB.v1._m),
							_mm_add_ps(_mm_mul_ps(_mm_set_ps1(mA.v1.z), mB.v2._m), _mm_mul_ps(_mm_set_ps1(mA.v1.w), mB.v3._m))));
			// mA.v2 * mB
			m.v2._m = _mm_add_ps(_mm_mul_ps(_mm_set_ps1(mA.v2.x), mB.v0._m),
							_mm_add_ps(_mm_mul_ps(_mm_set_ps1(mA.v2.y), mB.v1._m),
							_mm_add_ps(_mm_mul_ps(_mm_set_ps1(mA.v2.z), mB.v2._m), _mm_mul_ps(_mm_set_ps1(mA.v2.w), mB.v3._m))));
			// mA.v3 * mB
			m.v3._m = _mm_add_ps(_mm_mul_ps(_mm_set_ps1(mA.v3.x), mB.v0._m),
							_mm_add_ps(_mm_mul_ps(_mm_set_ps1(mA.v3.y), mB.v1._m),
							_mm_add_ps(_mm_mul_ps(_mm_set_ps1(mA.v3.z), mB.v2._m), _mm_mul_ps(_mm_set_ps1(mA.v3.w), mB.v3._m))));
			return m;
		}
	};
	
	friend inline MmultM operator * (const Matrix_SIMD &t1, const Matrix_SIMD &t2)
	{
		return MmultM(t1, t2);
	}


	// Second Proxy MmultMM
	struct MmultMM
	{
		const Matrix_SIMD &mA;
		const Matrix_SIMD &mB;
		const Matrix_SIMD &mC;

		MmultMM()
			: mA(Matrix_SIMD()), mB(Matrix_SIMD()), mC(Matrix_SIMD())
		{
		}

		MmultMM(const MmultMM &in)
			: mA(in.mA), mB(in.mB), mC(in.mC)
		{
		}

		MmultMM & operator = (const MmultMM &)
		{
			return *this;
		}

		MmultMM(const MmultM &t1, const Matrix_SIMD &t2)
			: mA(t1.mA), mB(t1.mB), mC(t2)
		{
		};

	};

	friend inline MmultMM operator * (const MmultM &t1, const Matrix_SIMD &t2)
	{
		return MmultMM(t1, t2);
	}


	// Third Proxy MmultMMM
	struct MmultMMM
	{
		const Matrix_SIMD &mA;
		const Matrix_SIMD &mB;
		const Matrix_SIMD &mC;
		const Matrix_SIMD &mD;

		MmultMMM()
			: mA(Matrix_SIMD()), mB(Matrix_SIMD()), mC(Matrix_SIMD()), mD(Matrix_SIMD())
		{
		}

		MmultMMM(const MmultMMM &in)
			: mA(in.mA), mB(in.mB), mC(in.mC), mD(in.mD)
		{
		}

		MmultMMM & operator = (const MmultMMM &)
		{
			return *this;
		}

		MmultMMM(const MmultMM &t1, const Matrix_SIMD &t2)
			: mA(t1.mA), mB(t1.mB), mC(t1.mC), mD(t2)
		{
		};

	};

	friend inline MmultMMM operator * (const MmultMM &t1, const Matrix_SIMD &t2)
	{
		return MmultMMM(t1, t2);
	}

	// Fourth Proxy MmultMMMM
	struct MmultMMMM
	{
		const Matrix_SIMD &mA;
		const Matrix_SIMD &mB;
		const Matrix_SIMD &mC;
		const Matrix_SIMD &mD;
		const Matrix_SIMD &mE;

		MmultMMMM()
			: mA(Matrix_SIMD()), mB(Matrix_SIMD()), mC(Matrix_SIMD()),
			mD(Matrix_SIMD()), mE(Matrix_SIMD())
		{
		}

		MmultMMMM(const MmultMMMM &in)
			: mA(in.mA), mB(in.mB), mC(in.mC), mD(in.mD), mE(in.mE)
		{
		}

		MmultMMMM & operator = (const MmultMMMM &)
		{
			return *this;
		}

		MmultMMMM(const MmultMMM &t1, const Matrix_SIMD &t2)
			: mA(t1.mA), mB(t1.mB), mC(t1.mC), mD(t1.mD), mE(t2)
		{
		};

	};

	friend inline MmultMMMM operator * (const MmultMMM &t1, const Matrix_SIMD &t2)
	{
		return MmultMMMM(t1, t2);
	}

	// Fifth Proxy MmultMMMMV
	struct MmultMMMMV
	{
		const Matrix_SIMD &mA;
		const Matrix_SIMD &mB;
		const Matrix_SIMD &mC;
		const Matrix_SIMD &mD;
		const Matrix_SIMD &mE;
		const Vect4D_SIMD &vA;

		MmultMMMMV()
			: mA(Matrix_SIMD()), mB(Matrix_SIMD()), mC(Matrix_SIMD()),
			mD(Matrix_SIMD()), mE(Matrix_SIMD()), vA(Vect4D_SIMD())
		{
		}

		MmultMMMMV(const MmultMMMMV &in)
			: mA(in.mA), mB(in.mB), mC(in.mC), mD(in.mB), mE(in.mA), vA(in.vA)
		{
		}

		MmultMMMMV & operator = (const MmultMMMMV &)
		{
			return *this;
		}

		MmultMMMMV(const MmultMMMM &t1, const Vect4D_SIMD &t2)
			: mA(t1.mA), mB(t1.mB), mC(t1.mC), mD(t1.mD), mE(t1.mE), vA(t2)
		{
		};


		operator Vect4D_SIMD()
		{
			Vect4D_SIMD v;
			// mE * vA
			v._m = _mm_hadd_ps(_mm_hadd_ps(_mm_mul_ps(vA._m, mE.v0._m), _mm_mul_ps(vA._m, mE.v1._m)),
					_mm_hadd_ps(_mm_mul_ps(vA._m, mE.v2._m), _mm_mul_ps(vA._m, mE.v3._m)));
			// mD * (mE * vA)
			v._m = _mm_hadd_ps(_mm_hadd_ps(_mm_mul_ps(v._m, mD.v0._m), _mm_mul_ps(v._m, mD.v1._m)),
					_mm_hadd_ps(_mm_mul_ps(v._m, mD.v2._m), _mm_mul_ps(v._m, mD.v3._m)));
			// mC * (mD * mE * vA)
			v._m = _mm_hadd_ps(_mm_hadd_ps(_mm_mul_ps(v._m, mC.v0._m), _mm_mul_ps(v._m, mC.v1._m)),
					_mm_hadd_ps(_mm_mul_ps(v._m, mC.v2._m), _mm_mul_ps(v._m, mC.v3._m)));
			// mB * (mC * mD * mE * vA)
			v._m = _mm_hadd_ps(_mm_hadd_ps(_mm_mul_ps(v._m, mB.v0._m), _mm_mul_ps(v._m, mB.v1._m)),
					_mm_hadd_ps(_mm_mul_ps(v._m, mB.v2._m), _mm_mul_ps(v._m, mB.v3._m)));
			// mA * (mB * mC * mD * mE * vA)
			v._m = _mm_hadd_ps(_mm_hadd_ps(_mm_mul_ps(v._m, mA.v0._m), _mm_mul_ps(v._m, mA.v1._m)),
					_mm_hadd_ps(_mm_mul_ps(v._m, mA.v2._m), _mm_mul_ps(v._m, mA.v3._m)));
			return v;
		}

	};

	friend inline MmultMMMMV operator * (const MmultMMMM &t1, const Vect4D_SIMD &t2)
	{
		return MmultMMMMV(t1, t2);
	}

	/*
	*
	*  End  M * M * M * M * M * V  Proxy Structs
	*
	*/

	/*
	*
	*  Begin V * M * M * M * M * M  Proxy Structs
	*
	*/


	// First Proxy VmultM
	struct VmultM
	{
		const Vect4D_SIMD &vA;
		const Matrix_SIMD &mA;

		VmultM()
			: vA(Vect4D_SIMD()), mA(Matrix_SIMD())
		{
		}

		VmultM(const VmultM &in)
			: vA(in.vA), mA(in.mA)
		{
		}

		VmultM & operator = (const VmultM &)
		{
			return *this;
		}

		VmultM(const Vect4D_SIMD &t1, const Matrix_SIMD &t2)
			: vA(t1), mA(t2)
		{
		}

		operator Vect4D_SIMD()
		{
			Vect4D_SIMD vectResult;
			vectResult._m = _mm_add_ps(_mm_mul_ps(_mm_set_ps1(vA.x), mA.v0._m),
								_mm_add_ps(_mm_mul_ps(_mm_set_ps1(vA.y), mA.v1._m),
								_mm_add_ps(_mm_mul_ps(_mm_set_ps1(vA.z), mA.v2._m),
											_mm_mul_ps(_mm_set_ps1(vA.w), mA.v3._m))));
			return vectResult;
		}
	};

	friend inline VmultM operator * (const Vect4D_SIMD &t1, const Matrix_SIMD &t2)
	{
		return VmultM(t1, t2);
	}

	// Second Proxy VmultMM
	struct VmultMM
	{
		const Vect4D_SIMD &vA;
		const Matrix_SIMD &mA;
		const Matrix_SIMD &mB;

		VmultMM()
			: vA(Vect4D_SIMD()), mA(Matrix_SIMD()), mB(Matrix_SIMD())
		{
		}

		VmultMM(const VmultMM &in)
			: vA(in.vA), mA(in.mA), mB(in.mB)
		{
		}

		VmultMM & operator = (const VmultMM &)
		{
			return *this;
		}

		VmultMM(const VmultM &t1, const Matrix_SIMD &t2)
			: vA(t1.vA), mA(t1.mA), mB(t2)
		{
		}
	};

	friend inline VmultMM operator * (const VmultM &t1, const Matrix_SIMD &t2)
	{
		return VmultMM(t1, t2);
	}

	// Third Proxy VmultMMM
	struct VmultMMM
	{
		const Vect4D_SIMD &vA;
		const Matrix_SIMD &mA;
		const Matrix_SIMD &mB;
		const Matrix_SIMD &mC;

		VmultMMM()
			: vA(Vect4D_SIMD()), mA(Matrix_SIMD()), mB(Matrix_SIMD()), mC(Matrix_SIMD())
		{
		}

		VmultMMM(const VmultMMM &in)
			: vA(in.vA), mA(in.mA), mB(in.mB), mC(in.mC)
		{
		}

		VmultMMM & operator = (const VmultMMM &)
		{
			return *this;
		}

		VmultMMM(const VmultMM &t1, const Matrix_SIMD &t2)
			: vA(t1.vA), mA(t1.mA), mB(t1.mB), mC(t2)
		{
		}
	};

	friend inline VmultMMM operator * (const VmultMM &t1, const Matrix_SIMD &t2)
	{
		return VmultMMM(t1, t2);
	}

	// Fourth Proxy VmultMMMM
	struct VmultMMMM
	{
		const Vect4D_SIMD &vA;
		const Matrix_SIMD &mA;
		const Matrix_SIMD &mB;
		const Matrix_SIMD &mC;
		const Matrix_SIMD &mD;

		VmultMMMM()
			: vA(Vect4D_SIMD()), mA(Matrix_SIMD()), mB(Matrix_SIMD()),
			mC(Matrix_SIMD()), mD(Matrix_SIMD())
		{
		}

		VmultMMMM(const VmultMMMM &in)
			: vA(in.vA), mA(in.mA), mB(in.mB), mC(in.mC), mD(in.mD)
		{
		}

		VmultMMMM & operator = (const VmultMMMM &)
		{
			return *this;
		}

		VmultMMMM(const VmultMMM &t1, const Matrix_SIMD &t2)
			: vA(t1.vA), mA(t1.mA), mB(t1.mB), mC(t1.mC), mD(t2)
		{
		}
	};

	friend inline VmultMMMM operator * (const VmultMMM &t1, const Matrix_SIMD &t2)
	{
		return VmultMMMM(t1, t2);
	}

	// Fifth Proxy VmultMMMMM
	struct VmultMMMMM
	{
		const Vect4D_SIMD &vA;
		const Matrix_SIMD &mA;
		const Matrix_SIMD &mB;
		const Matrix_SIMD &mC;
		const Matrix_SIMD &mD;
		const Matrix_SIMD &mE;

		VmultMMMMM()
			: vA(Vect4D_SIMD()), mA(Matrix_SIMD()), mB(Matrix_SIMD()),
			mC(Matrix_SIMD()), mD(Matrix_SIMD()), mE(Matrix_SIMD())
		{
		}

		VmultMMMMM(const VmultMMMMM &in)
			: vA(in.vA), mA(in.mA), mB(in.mB), mC(in.mC), mD(in.mD), mE(in.mE)
		{
		}

		VmultMMMMM & operator = (const VmultMMMMM &)
		{
			return *this;
		}

		VmultMMMMM(const VmultMMMM &t1, const Matrix_SIMD &t2)
			: vA(t1.vA), mA(t1.mA), mB(t1.mB), mC(t1.mC), mD(t1.mD), mE(t2)
		{
		}

		operator Vect4D_SIMD()
		{
			Vect4D_SIMD v;

			// vA * mA
			v._m = _mm_add_ps(_mm_mul_ps(_mm_set_ps1(vA.x), mA.v0._m),
					_mm_add_ps(_mm_mul_ps(_mm_set_ps1(vA.y), mA.v1._m),
					_mm_add_ps(_mm_mul_ps(_mm_set_ps1(vA.z), mA.v2._m),
								_mm_mul_ps(_mm_set_ps1(vA.w), mA.v3._m))));

			// (vA * mA) * mB
			v._m = _mm_add_ps(_mm_mul_ps(_mm_set_ps1(v.x), mB.v0._m),
					_mm_add_ps(_mm_mul_ps(_mm_set_ps1(v.y), mB.v1._m),
					_mm_add_ps(_mm_mul_ps(_mm_set_ps1(v.z), mB.v2._m),
								_mm_mul_ps(_mm_set_ps1(v.w), mB.v3._m))));

			// (vA * mA * mB) * mC
			v._m = _mm_add_ps(_mm_mul_ps(_mm_set_ps1(v.x), mC.v0._m),
					_mm_add_ps(_mm_mul_ps(_mm_set_ps1(v.y), mC.v1._m),
					_mm_add_ps(_mm_mul_ps(_mm_set_ps1(v.z), mC.v2._m),
								_mm_mul_ps(_mm_set_ps1(v.w), mC.v3._m))));

			// (vA * mA * mB * mC) * mD
			v._m = _mm_add_ps(_mm_mul_ps(_mm_set_ps1(v.x), mD.v0._m),
					_mm_add_ps(_mm_mul_ps(_mm_set_ps1(v.y), mD.v1._m),
					_mm_add_ps(_mm_mul_ps(_mm_set_ps1(v.z), mD.v2._m),
								_mm_mul_ps(_mm_set_ps1(v.w), mD.v3._m))));

			// (vA * mA * mB * mC * mD) * mE
			v._m = _mm_add_ps(_mm_mul_ps(_mm_set_ps1(v.x), mE.v0._m),
					_mm_add_ps(_mm_mul_ps(_mm_set_ps1(v.y), mE.v1._m),
					_mm_add_ps(_mm_mul_ps(_mm_set_ps1(v.z), mE.v2._m),
								_mm_mul_ps(_mm_set_ps1(v.w), mE.v3._m))));

			return v;
		}
	};

	friend inline VmultMMMMM operator * (const VmultMMMM &t1, const Matrix_SIMD &t2)
	{
		return VmultMMMMM(t1, t2);
	}





public:

	union
	{
		struct
		{
			Vect4D_SIMD v0;
			Vect4D_SIMD v1;
			Vect4D_SIMD v2;
			Vect4D_SIMD v3;
		};

		struct
		{
			float m0;
			float m1;
			float m2;
			float m3;
			float m4;
			float m5;
			float m6;
			float m7;
			float m8;
			float m9;
			float m10;
			float m11;
			float m12;
			float m13;
			float m14;
			float m15;
		};
	};
};

#endif