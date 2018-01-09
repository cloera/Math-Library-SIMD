#ifndef MATRIX_H
#define MATRIX_H

#include "Vect4D.h"

#define UNUSED_VAR(v) ((void )v)

class Matrix
{
public:

	Matrix(const Vect4D &tv0,const Vect4D &tv1, const Vect4D &tv2,const Vect4D &tv3)
		:v0(tv0),v1(tv1),v2(tv2),v3(tv3)
	{
	};

	Matrix()
	{
	};

	~Matrix()
	{

	}
	
	Matrix(const Matrix &tmp)
	{
		this->v0 = tmp.v0;
		this->v1 = tmp.v1;
		this->v2 = tmp.v2;
		this->v3 = tmp.v3;
	}

	Matrix &operator=(const Matrix &tmp)
	{
		if (this != &tmp)
		{
			this->v0 = tmp.v0;
			this->v1 = tmp.v1;
			this->v2 = tmp.v2;
			this->v3 = tmp.v3;
		}
		return *this;
	}

	Vect4D operator * (const Vect4D &v);

	Matrix operator * (const Matrix &t);


// Level 4 complains nameless struct/union ...
#pragma warning( disable : 4201)

union 
	{
	struct 
		{
		Vect4D v0;
		Vect4D v1;
		Vect4D v2;
		Vect4D v3;
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