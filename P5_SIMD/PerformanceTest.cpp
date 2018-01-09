#include <math.h> 
#include <stdio.h>
#include "Vect4D_Simd.h"
#include "Vect4D.h"
#include "Matrix.h"
#include "Matrix_SIMD.h"
#include "LERP.h"
#include "LERP_SIMD.h"

#include "UnitTest.h"

#define f_eq(A,B) (  fabs(A - B) < 0.001f)
#define V_EQ( A, B) ((f_eq(A.x,B.x) ) && ( f_eq(A.y, B.y)) && (f_eq(A.z,B.z)) && (f_eq(A.w,B.w) ))

Vect4D_SIMD LERP_SIMD_Tests()
{
	Vect4D_SIMD vOut;
	Vect4D_SIMD A(1.00f, 2.0f, 3.0f, 4.0f);
	Vect4D_SIMD B(21.00f, 12.0f, 23.0f, 40.0f);
	Vect4D_SIMD C(13.00f, 24.0f, 33.0f, 40.0f);
	Vect4D_SIMD D(0.50f, 22.0f, 43.0f, 40.0f);
	Vect4D_SIMD E(1.30f, 23.0f, 35.0f, 40.0f);
	Vect4D_SIMD F(15.00f, 72.0f, 35.0f, 40.0f);
	Vect4D_SIMD G(21.00f, 92.0f, 33.0f, 40.0f);

	VectApp_SIMD::Lerp(vOut, A, B, 0.65f);
	VectApp_SIMD::Lerp(vOut, A, vOut, 0.65f);
	VectApp_SIMD::Lerp(vOut, B, vOut, 0.15f);
	VectApp_SIMD::Lerp(vOut, C, vOut, 0.25f);
	VectApp_SIMD::Lerp(vOut, D, vOut, 0.35f);
	VectApp_SIMD::Lerp(vOut, E, vOut, 0.45f);
	VectApp_SIMD::Lerp(vOut, F, vOut, 0.55f);
	VectApp_SIMD::Lerp(vOut, G, vOut, 0.65f);
	VectApp_SIMD::Lerp(vOut, A, vOut, 0.75f);
	VectApp_SIMD::Lerp(vOut, A, vOut, 0.85f);
	VectApp_SIMD::Lerp(vOut, B, vOut, 0.95f);
	VectApp_SIMD::Lerp(vOut, C, vOut, 0.05f);
	VectApp_SIMD::Lerp(vOut, D, vOut, 0.15f);
	VectApp_SIMD::Lerp(vOut, E, vOut, 0.25f);
	VectApp_SIMD::Lerp(vOut, F, vOut, 0.35f);
	VectApp_SIMD::Lerp(vOut, G, vOut, 0.45f);
	VectApp_SIMD::Lerp(vOut, A, vOut, 0.65f);
	VectApp_SIMD::Lerp(vOut, B, vOut, 0.15f);
	VectApp_SIMD::Lerp(vOut, C, vOut, 0.25f);
	VectApp_SIMD::Lerp(vOut, D, vOut, 0.35f);
	VectApp_SIMD::Lerp(vOut, E, vOut, 0.45f);
	VectApp_SIMD::Lerp(vOut, F, vOut, 0.55f);
	VectApp_SIMD::Lerp(vOut, G, vOut, 0.65f);
	VectApp_SIMD::Lerp(vOut, A, vOut, 0.75f);
	VectApp_SIMD::Lerp(vOut, A, vOut, 0.85f);
	VectApp_SIMD::Lerp(vOut, B, vOut, 0.95f);
	VectApp_SIMD::Lerp(vOut, C, vOut, 0.05f);
	VectApp_SIMD::Lerp(vOut, D, vOut, 0.15f);
	VectApp_SIMD::Lerp(vOut, E, vOut, 0.25f);
	VectApp_SIMD::Lerp(vOut, F, vOut, 0.35f);
	VectApp_SIMD::Lerp(vOut, G, vOut, 0.45f);
	VectApp_SIMD::Lerp(vOut, A, vOut, 0.65f);
	VectApp_SIMD::Lerp(vOut, B, vOut, 0.15f);
	VectApp_SIMD::Lerp(vOut, C, vOut, 0.25f);
	VectApp_SIMD::Lerp(vOut, D, vOut, 0.35f);
	VectApp_SIMD::Lerp(vOut, E, vOut, 0.45f);
	VectApp_SIMD::Lerp(vOut, F, vOut, 0.55f);
	VectApp_SIMD::Lerp(vOut, G, vOut, 0.65f);
	VectApp_SIMD::Lerp(vOut, A, vOut, 0.75f);
	VectApp_SIMD::Lerp(vOut, A, vOut, 0.85f);
	VectApp_SIMD::Lerp(vOut, B, vOut, 0.95f);
	VectApp_SIMD::Lerp(vOut, C, vOut, 0.05f);
	VectApp_SIMD::Lerp(vOut, D, vOut, 0.15f);
	VectApp_SIMD::Lerp(vOut, E, vOut, 0.25f);
	VectApp_SIMD::Lerp(vOut, F, vOut, 0.35f);
	VectApp_SIMD::Lerp(vOut, G, vOut, 0.45f);

	return vOut;
}

Vect4D LERP_Tests()
{
	Vect4D vOut;
	Vect4D A(1.00f, 2.0f, 3.0f, 4.0f);
	Vect4D B(21.00f, 12.0f, 23.0f, 40.0f);
	Vect4D C(13.00f, 24.0f, 33.0f, 40.0f);
	Vect4D D(0.50f, 22.0f, 43.0f, 40.0f);
	Vect4D E(1.30f, 23.0f, 35.0f, 40.0f);
	Vect4D F(15.00f, 72.0f, 35.0f, 40.0f);
	Vect4D G(21.00f, 92.0f, 33.0f, 40.0f);

	VectApp::Lerp(vOut, A, B, 0.65f);
	VectApp::Lerp(vOut, A, vOut, 0.65f);
	VectApp::Lerp(vOut, B, vOut, 0.15f);
	VectApp::Lerp(vOut, C, vOut, 0.25f);
	VectApp::Lerp(vOut, D, vOut, 0.35f);
	VectApp::Lerp(vOut, E, vOut, 0.45f);
	VectApp::Lerp(vOut, F, vOut, 0.55f);
	VectApp::Lerp(vOut, G, vOut, 0.65f);
	VectApp::Lerp(vOut, A, vOut, 0.75f);
	VectApp::Lerp(vOut, A, vOut, 0.85f);
	VectApp::Lerp(vOut, B, vOut, 0.95f);
	VectApp::Lerp(vOut, C, vOut, 0.05f);
	VectApp::Lerp(vOut, D, vOut, 0.15f);
	VectApp::Lerp(vOut, E, vOut, 0.25f);
	VectApp::Lerp(vOut, F, vOut, 0.35f);
	VectApp::Lerp(vOut, G, vOut, 0.45f);
	VectApp::Lerp(vOut, A, vOut, 0.65f);
	VectApp::Lerp(vOut, B, vOut, 0.15f);
	VectApp::Lerp(vOut, C, vOut, 0.25f);
	VectApp::Lerp(vOut, D, vOut, 0.35f);
	VectApp::Lerp(vOut, E, vOut, 0.45f);
	VectApp::Lerp(vOut, F, vOut, 0.55f);
	VectApp::Lerp(vOut, G, vOut, 0.65f);
	VectApp::Lerp(vOut, A, vOut, 0.75f);
	VectApp::Lerp(vOut, A, vOut, 0.85f);
	VectApp::Lerp(vOut, B, vOut, 0.95f);
	VectApp::Lerp(vOut, C, vOut, 0.05f);
	VectApp::Lerp(vOut, D, vOut, 0.15f);
	VectApp::Lerp(vOut, E, vOut, 0.25f);
	VectApp::Lerp(vOut, F, vOut, 0.35f);
	VectApp::Lerp(vOut, G, vOut, 0.45f);
	VectApp::Lerp(vOut, A, vOut, 0.65f);
	VectApp::Lerp(vOut, B, vOut, 0.15f);
	VectApp::Lerp(vOut, C, vOut, 0.25f);
	VectApp::Lerp(vOut, D, vOut, 0.35f);
	VectApp::Lerp(vOut, E, vOut, 0.45f);
	VectApp::Lerp(vOut, F, vOut, 0.55f);
	VectApp::Lerp(vOut, G, vOut, 0.65f);
	VectApp::Lerp(vOut, A, vOut, 0.75f);
	VectApp::Lerp(vOut, A, vOut, 0.85f);
	VectApp::Lerp(vOut, B, vOut, 0.95f);
	VectApp::Lerp(vOut, C, vOut, 0.05f);
	VectApp::Lerp(vOut, D, vOut, 0.15f);
	VectApp::Lerp(vOut, E, vOut, 0.25f);
	VectApp::Lerp(vOut, F, vOut, 0.35f);
	VectApp::Lerp(vOut, G, vOut, 0.45f);

	return vOut;
}

Vect4D_SIMD test_simd()
{
	Vect4D_SIMD A;
	Vect4D_SIMD B;
	Vect4D_SIMD C;

	A.x = 5.0f;
	A.y = 6.0f;
	A.z = 7.0f;
	A.w = 8.0f;

	B.x = 10.0f;
	B.y = 20.0f;
	B.z = 30.0f;
	B.w = 40.0f;

	Vect4D_SIMD D;
	D = B;
	D += A;
	Vect4D_SIMD E = A + B;

	Vect4D_SIMD F;
	F = B;
	F -= A;
	Vect4D_SIMD G = A - B;

	Vect4D_SIMD H;
	H = B;
	H *= A;
	Vect4D_SIMD I = A * B;

	Vect4D_SIMD J;
	J = B;
	J /= A;
	Vect4D_SIMD K = A / B;

	Vect4D_SIMD a(1, 2, 3, 4);
	Vect4D_SIMD b(10, 10, 10, 10);

	Vect4D_SIMD c;

	float t = a.dot(b);
	B.x += t;
	A += B;
	A += C;
	A += D;
	A += E;
	A += F;
	A += G;
	A += H;
	A += I;
	A += a;
	A += b;
	A += c;

	return A;
}

Vect4D test()
{
	Vect4D A;
	Vect4D B;
	Vect4D C;

	A.x = 5.0f;
	A.y = 6.0f;
	A.z = 7.0f;
	A.w = 8.0f;

	B.x = 10.0f;
	B.y = 20.0f;
	B.z = 30.0f;
	B.w = 40.0f;

	Vect4D D;
	D = B;
	D += A;
	Vect4D E = A + B;

	Vect4D F;
	F = B;
	F -= A;
	Vect4D G = A - B;

	Vect4D H;
	H = B;
	H *= A;
	Vect4D I = A * B;

	Vect4D J;
	J = B;
	J /= A;
	Vect4D K = A / B;

	Vect4D a(1, 2, 3, 4);
	Vect4D b(10, 10, 10, 10);

	Vect4D c;

	float t = a.dot(b);
	B.x += t;

	A += B;
	A += C;
	A += D;
	A += E;
	A += F;
	A += G;
	A += H;
	A += I;
	A += a;
	A += b;
	A += c;

	return A;
}

Vect4D matrix_test()
{
	Vect4D VA0(-1, -2, -3, -4);
	Vect4D VA1(4, 5, 6, 7);
	Vect4D VA2(1, 2, 3, 4);
	Vect4D VA3(-4, -3, -2, -1);
	Vect4D VB0(-0.1f, -0.2f, -0.3f, -0.4f);
	Vect4D VB1(0.4f, 0.5f, 0.6f, 0.7f);
	Vect4D VB2(0.1f, 0.2f, 0.3f, 0.4f);
	Vect4D VB3(-0.4f, -0.3f, -0.2f, -0.1f);

	Matrix A(VA0, VA1, VA2, VA3);
	Matrix B(VB0, VB1, VB2, VB3);
	Matrix C;

	for (int i = 0; i < 10000; i++)
	{
		C = A * B;
	}
	return C.v1;
}

Vect4D_SIMD matrix_SIMD_test()
{
	Vect4D_SIMD VA0(-1, -2, -3, -4);
	Vect4D_SIMD VA1(4, 5, 6, 7);
	Vect4D_SIMD VA2(1, 2, 3, 4);
	Vect4D_SIMD VA3(-4, -3, -2, -1);
	Vect4D_SIMD VB0(-0.1f, -0.2f, -0.3f, -0.4f);
	Vect4D_SIMD VB1(0.4f, 0.5f, 0.6f, 0.7f);
	Vect4D_SIMD VB2(0.1f, 0.2f, 0.3f, 0.4f);
	Vect4D_SIMD VB3(-0.4f, -0.3f, -0.2f, -0.1f);

	Matrix_SIMD A(VA0, VA1, VA2, VA3);
	Matrix_SIMD B(VB0, VB1, VB2, VB3);
	Matrix_SIMD C;

	for (int i = 0; i < 10000; i++)
	{
		C = A * B;
	}
	return C.v1;
}

Vect4D vectMultMatrix_test(void)
{
	Vect4D A(1, 2, 3, 4);
	Vect4D B(11, 12, 13, 14);
	Vect4D C(21, 22, 23, 24);

	Vect4D MV0(1, 2, 3, 4);
	Vect4D MV1(5, 6, 7, 8);
	Vect4D MV2(9, 10, 11, 12);
	Vect4D MV3(13, 14, 15, 16);

	Matrix M(MV0, MV1, MV2, MV3);

	Vect4D vout;

	for (int i = 0; i < 1000; i++)
	{
		vout = A * M;
		vout = B * M;
		vout = C * M;
	}

	return vout;
}

Vect4D_SIMD vectMultMatrix_SIMD_test(void)
{
	Vect4D_SIMD A(1, 2, 3, 4);
	Vect4D_SIMD B(11, 12, 13, 14);
	Vect4D_SIMD C(21, 22, 23, 24);


	Vect4D_SIMD MV0(1, 2, 3, 4);
	Vect4D_SIMD MV1(5, 6, 7, 8);
	Vect4D_SIMD MV2(9, 10, 11, 12);
	Vect4D_SIMD MV3(13, 14, 15, 16);

	Matrix_SIMD M(MV0, MV1, MV2, MV3);

	Vect4D_SIMD vout;

	for (int i = 0; i < 1000; i++)
	{
		vout = A * M;
		vout = B * M;
		vout = C * M;
	}

	return vout;
}

Vect4D matrixMultVect_test(void)
{
	Vect4D A(1, 2, 3, 4);
	Vect4D B(11, 12, 13, 14);
	Vect4D C(21, 22, 23, 24);

	Vect4D MV0(1, 5, 9, 13);
	Vect4D MV1(2, 6, 10, 14);
	Vect4D MV2(3, 7, 11, 15);
	Vect4D MV3(4, 8, 12, 16);

	Matrix M(MV0, MV1, MV2, MV3);

	Vect4D vout;

	for (int i = 0; i < 1000; i++)
	{
		vout = M * A;
		vout = M * B;
		vout = M * C;
	}

	return vout;
}

Vect4D_SIMD matrixMultVect_SIMD_test(void)
{
	Vect4D_SIMD A(1, 2, 3, 4);
	Vect4D_SIMD B(11, 12, 13, 14);
	Vect4D_SIMD C(21, 22, 23, 24);


	Vect4D_SIMD MV0(1, 5, 9, 13);
	Vect4D_SIMD MV1(2, 6, 10, 14);
	Vect4D_SIMD MV2(3, 7, 11, 15);
	Vect4D_SIMD MV3(4, 8, 12, 16);

	Matrix_SIMD M(MV0, MV1, MV2, MV3);

	Vect4D_SIMD vout;

	for (int i = 0; i < 1000; i++)
	{
		vout = M * A;
		vout = M * B;
		vout = M * C;
	}

	return vout;
}

Vect4D rowMajor_test()
{
	Matrix Rx(Vect4D(1.000000f, 0.000000f, 0.000000f, 0.000000f),
			  Vect4D(0.000000f, -0.500000f, 0.866025f, 0.000000f),
			  Vect4D(0.000000f, -0.866025f, -0.500000f, 0.000000f),
			  Vect4D(0.000000f, 0.000000f, 0.000000f, 1.000000f));

	Matrix Ry(Vect4D(0.707107f, 0.000000f, -0.707107f, 0.000000f),
			  Vect4D(0.000000f, 1.000000f, 0.000000f, 0.000000f),
			  Vect4D(0.707107f, 0.000000f, 0.707107f, 0.000000f),
			  Vect4D(0.000000f, 0.000000f, 0.000000f, 1.000000f));

	Matrix Rz(Vect4D(0.500000f, -0.866025f, 0.000000f, 0.000000f),
			  Vect4D(0.866025f, 0.500000f, 0.000000f, 0.000000f),
			  Vect4D(0.000000f, 0.000000f, 1.000000f, 0.000000f),
			  Vect4D(0.000000f, 0.000000f, 0.000000f, 1.000000f));

	Matrix  T(Vect4D(1.000000f, 0.000000f, 0.000000f, 0.000000f),
			  Vect4D(0.000000f, 1.000000f, 0.000000f, 0.000000f),
			  Vect4D(0.000000f, 0.000000f, 1.000000f, 0.000000f),
			  Vect4D(4.000000f, 5.000000f, 6.000000f, 1.000000f));

	Matrix  S(Vect4D(1.000000f, 0.000000f, 0.000000f, 0.200000f),
			  Vect4D(0.000000f, 2.000000f, 0.000000f, 0.300000f),
			  Vect4D(0.000000f, 0.000000f, 0.500000f, 0.500000f),
			  Vect4D(0.000000f, 0.000000f, 0.000000f, 0.130000f));

	Vect4D  v(0.500000f, 0.600000f, 0.700000f, 0.900000f);
	Vect4D vOut;

	for (int i = 0; i < 1000; i++)
	{
		vOut = v * S * Rx *Ry * Rz * T;
	}
	return vOut;

}

Vect4D_SIMD rowMajor_SIMD_test()
{
	Matrix_SIMD Rx(Vect4D_SIMD(1.000000f, 0.000000f, 0.000000f, 0.000000f),
				   Vect4D_SIMD(0.000000f, -0.500000f, 0.866025f, 0.000000f),
				   Vect4D_SIMD(0.000000f, -0.866025f, -0.500000f, 0.000000f),
				   Vect4D_SIMD(0.000000f, 0.000000f, 0.000000f, 1.000000f));

	Matrix_SIMD Ry(Vect4D_SIMD(0.707107f, 0.000000f, -0.707107f, 0.000000f),
				   Vect4D_SIMD(0.000000f, 1.000000f, 0.000000f, 0.000000f),
				   Vect4D_SIMD(0.707107f, 0.000000f, 0.707107f, 0.000000f),
				   Vect4D_SIMD(0.000000f, 0.000000f, 0.000000f, 1.000000f));

	Matrix_SIMD Rz(Vect4D_SIMD(0.500000f, -0.866025f, 0.000000f, 0.000000f),
				   Vect4D_SIMD(0.866025f, 0.500000f, 0.000000f, 0.000000f),
				   Vect4D_SIMD(0.000000f, 0.000000f, 1.000000f, 0.000000f),
				   Vect4D_SIMD(0.000000f, 0.000000f, 0.000000f, 1.000000f));

	Matrix_SIMD  T(Vect4D_SIMD(1.000000f, 0.000000f, 0.000000f, 0.000000f),
				   Vect4D_SIMD(0.000000f, 1.000000f, 0.000000f, 0.000000f),
				   Vect4D_SIMD(0.000000f, 0.000000f, 1.000000f, 0.000000f),
				   Vect4D_SIMD(4.000000f, 5.000000f, 6.000000f, 1.000000f));

	Matrix_SIMD  S(Vect4D_SIMD(1.000000f, 0.000000f, 0.000000f, 0.200000f),
				   Vect4D_SIMD(0.000000f, 2.000000f, 0.000000f, 0.300000f),
				   Vect4D_SIMD(0.000000f, 0.000000f, 0.500000f, 0.500000f),
				   Vect4D_SIMD(0.000000f, 0.000000f, 0.000000f, 0.130000f));

	Vect4D_SIMD  v(0.500000f, 0.600000f, 0.700000f, 0.900000f);
	Vect4D_SIMD  vOut;

	for (int i = 0; i < 1000; i++)
	{
		vOut = v * S * Rx *Ry * Rz * T;
	}

	return vOut;
}

Vect4D colMajor_test()
{
	Matrix Rx(Vect4D(1.000000f, 0.000000f, 0.000000f, 0.000000f),
			  Vect4D(0.000000f, -0.500000f, -0.866025f, 0.000000f),
			  Vect4D(0.000000f, 0.866025f, -0.500000f, 0.000000f),
			  Vect4D(0.000000f, 0.000000f, 0.000000f, 1.000000f));

	Matrix Ry(Vect4D(0.707107f, 0.000000f, 0.707107f, 0.000000f),
			  Vect4D(0.000000f, 1.000000f, 0.000000f, 0.000000f),
			  Vect4D(-0.707107f, 0.000000f, 0.707107f, 0.000000f),
			  Vect4D(0.000000f, 0.000000f, 0.000000f, 1.000000f));

	Matrix Rz(Vect4D(0.500000f, 0.866025f, 0.000000f, 0.000000f),
			  Vect4D(-0.866025f, 0.500000f, 0.000000f, 0.000000f),
			  Vect4D(0.000000f, 0.000000f, 1.000000f, 0.000000f),
			  Vect4D(0.000000f, 0.000000f, 0.000000f, 1.000000f));

	Matrix  T(Vect4D(1.000000f, 0.000000f, 0.000000f, 4.000000f),
			  Vect4D(0.000000f, 1.000000f, 0.000000f, 5.000000f),
			  Vect4D(0.000000f, 0.000000f, 1.000000f, 6.000000f),
			  Vect4D(0.000000f, 0.000000f, 0.000000f, 1.000000f));

	Matrix  S(Vect4D(1.000000f, 0.000000f, 0.000000f, 0.000000f),
			  Vect4D(0.000000f, 2.000000f, 0.000000f, 0.000000f),
			  Vect4D(0.000000f, 0.000000f, 0.500000f, 0.000000f),
			  Vect4D(0.200000f, 0.300000f, 0.500000f, 0.130000f));

	Vect4D  v(0.500000f, 0.600000f, 0.700000f, 0.900000f);
	Vect4D vOut;

	for (int i = 0; i < 1000; i++)
	{
		vOut = T * Rz * Ry * Rx * S * v;
	}
	return vOut;
}

Vect4D_SIMD colMajor_SIMD_test()
{
	Matrix_SIMD Rx(Vect4D_SIMD(1.000000f, 0.000000f, 0.000000f, 0.000000f),
				   Vect4D_SIMD(0.000000f, -0.500000f, -0.866025f, 0.000000f),
				   Vect4D_SIMD(0.000000f, 0.866025f, -0.500000f, 0.000000f),
				   Vect4D_SIMD(0.000000f, 0.000000f, 0.000000f, 1.000000f));

	Matrix_SIMD Ry(Vect4D_SIMD(0.707107f, 0.000000f, 0.707107f, 0.000000f),
				   Vect4D_SIMD(0.000000f, 1.000000f, 0.000000f, 0.000000f),
				   Vect4D_SIMD(-0.707107f, 0.000000f, 0.707107f, 0.000000f),
				   Vect4D_SIMD(0.000000f, 0.000000f, 0.000000f, 1.000000f));

	Matrix_SIMD Rz(Vect4D_SIMD(0.500000f, 0.866025f, 0.000000f, 0.000000f),
				   Vect4D_SIMD(-0.866025f, 0.500000f, 0.000000f, 0.000000f),
				   Vect4D_SIMD(0.000000f, 0.000000f, 1.000000f, 0.000000f),
				   Vect4D_SIMD(0.000000f, 0.000000f, 0.000000f, 1.000000f));

	Matrix_SIMD  T(Vect4D_SIMD(1.000000f, 0.000000f, 0.000000f, 4.000000f),
				   Vect4D_SIMD(0.000000f, 1.000000f, 0.000000f, 5.000000f),
				   Vect4D_SIMD(0.000000f, 0.000000f, 1.000000f, 6.000000f),
				   Vect4D_SIMD(0.000000f, 0.000000f, 0.000000f, 1.000000f));

	Matrix_SIMD  S(Vect4D_SIMD(1.000000f, 0.000000f, 0.000000f, 0.000000f),
				   Vect4D_SIMD(0.000000f, 2.000000f, 0.000000f, 0.000000f),
				   Vect4D_SIMD(0.000000f, 0.000000f, 0.500000f, 0.000000f),
				   Vect4D_SIMD(0.200000f, 0.300000f, 0.500000f, 0.130000f));

	Vect4D_SIMD  v(0.500000f, 0.600000f, 0.700000f, 0.900000f);
	Vect4D_SIMD vOut;

	for (int i = 0; i < 1000; i++)
	{
		vOut = T * Rz * Ry * Rx * S * v;
	}
	return vOut;
}