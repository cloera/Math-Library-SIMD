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

TEST(vect4d, SIMD_TESTS)
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
	Vect4D E;
	E = A + B;

	Vect4D F;
	F = B;
	F -= A;
	Vect4D G;
	G = A - B;

	Vect4D H;
	H = B;
	H *= A;
	Vect4D I;
	I = A * B;

	Vect4D J;
	J = B;
	J /= A;
	Vect4D K;
	K = A / B;


	Vect4D a(1, 2, 3, 4);
	Vect4D b(10, 10, 10, 10);


	float t = a.dot(b);

	Vect4D_SIMD A_simd;
	Vect4D_SIMD B_simd;

	A_simd.x = 5.0f;
	A_simd.y = 6.0f;
	A_simd.z = 7.0f;
	A_simd.w = 8.0f;

	B_simd.x = 10.0f;
	B_simd.y = 20.0f;
	B_simd.z = 30.0f;
	B_simd.w = 40.0f;

	CHECK(V_EQ(A, A_simd));
	CHECK(V_EQ(B, B_simd));

	Vect4D_SIMD D_simd;

	D_simd = B_simd;
	D_simd += A_simd;

	CHECK(V_EQ(D, D_simd));

	Vect4D_SIMD E_simd;
	E_simd = A_simd + B_simd;

	CHECK(V_EQ(E, E_simd));

	Vect4D_SIMD F_simd;
	F_simd = B_simd;
	F_simd -= A_simd;

	CHECK(V_EQ(F, F_simd));

	Vect4D_SIMD G_simd;
	G_simd = A_simd - B_simd;

	CHECK(V_EQ(G, G_simd));

	Vect4D_SIMD H_simd;
	H_simd = B_simd;
	H_simd *= A_simd;


	CHECK(V_EQ(H, H_simd));

	Vect4D_SIMD I_simd;
	I_simd = A_simd * B_simd;


	CHECK(V_EQ(I, I_simd));

	Vect4D_SIMD J_simd;
	J_simd = B_simd;
	J_simd /= A_simd;

	CHECK(V_EQ(J, J_simd));

	Vect4D_SIMD K_simd;
	K_simd = A_simd / B_simd;

	CHECK(V_EQ(K, K_simd));

	Vect4D_SIMD a_simd;
	a_simd = Vect4D_SIMD(1, 2, 3, 4);
	Vect4D_SIMD b_simd;
	b_simd = Vect4D_SIMD(10, 10, 10, 10);

	CHECK(V_EQ(a, a_simd));
	CHECK(V_EQ(b, b_simd));

	float t_simd = a_simd.dot(b_simd);

	CHECK(t == t_simd);
}

TEST(Matrix, SIMD_Tests)
{
	// bang
	Vect4D VA0(-1, -2, -3, -4);
	Vect4D VA1(4, 5, 6, 7);
	Vect4D VA2(1, 2, 3, 4);
	Vect4D VA3(-4, -3, -2, -1);
	Vect4D VB0(-0.1f, -0.2f, -0.3f, -0.4f);
	Vect4D VB1(0.4f, 0.5f, 0.6f, 0.7f);
	Vect4D VB2(0.1f, 0.2f, 0.3f, 0.4f);
	Vect4D VB3(-0.4f, -0.3f, -0.2f, -0.1f);

	CHECK(VA0.x == -1.0f);
	CHECK(VA0.y == -2.0f);
	CHECK(VA0.z == -3.0f);
	CHECK(VA0.w == -4.0f);

	Matrix A(VA0, VA1, VA2, VA3);
	Matrix B(VB0, VB1, VB2, VB3);
	Matrix C;

	C = A * B;

	Vect4D_SIMD VA0_simd(-1, -2, -3, -4);
	Vect4D_SIMD VA1_simd(4, 5, 6, 7);
	Vect4D_SIMD VA2_simd(1, 2, 3, 4);
	Vect4D_SIMD VA3_simd(-4, -3, -2, -1);
	Vect4D_SIMD VB0_simd(-0.1f, -0.2f, -0.3f, -0.4f);
	Vect4D_SIMD VB1_simd(0.4f, 0.5f, 0.6f, 0.7f);
	Vect4D_SIMD VB2_simd(0.1f, 0.2f, 0.3f, 0.4f);
	Vect4D_SIMD VB3_simd(-0.4f, -0.3f, -0.2f, -0.1f);

	Matrix_SIMD A_simd(VA0_simd, VA1_simd, VA2_simd, VA3_simd);
	Matrix_SIMD B_simd(VB0_simd, VB1_simd, VB2_simd, VB3_simd);
	Matrix_SIMD C_simd;

	CHECK(VA0_simd.x == -1.0f);
	CHECK(VA0_simd.y == -2.0f);
	CHECK(VA0_simd.z == -3.0f);
	CHECK(VA0_simd.w == -4.0f);

	C_simd = A_simd * B_simd;


	CHECK(V_EQ(A.v0, A_simd.v0));
	CHECK(V_EQ(A.v1, A_simd.v1));
	CHECK(V_EQ(A.v2, A_simd.v2));
	CHECK(V_EQ(A.v3, A_simd.v3));

	CHECK(V_EQ(B.v0, B_simd.v0));
	CHECK(V_EQ(B.v1, B_simd.v1));
	CHECK(V_EQ(B.v2, B_simd.v2));
	CHECK(V_EQ(B.v3, B_simd.v3));

	CHECK(V_EQ(C.v0, C_simd.v0));
	CHECK(V_EQ(C.v1, C_simd.v1));
	CHECK(V_EQ(C.v2, C_simd.v2));
	CHECK(V_EQ(C.v3, C_simd.v3));
}

TEST(Vect_Matrix, SIMD_Tests)
{
	Vect4D A(1, 2, 3, 4);
	Vect4D B(11, 12, 13, 14);
	Vect4D C(21, 22, 23, 24);

	Vect4D MV0(1, 2, 3, 4);
	Vect4D MV1(5, 6, 7, 8);
	Vect4D MV2(9, 10, 11, 12);
	Vect4D MV3(13, 14, 15, 16);

	Matrix M(MV0, MV1, MV2, MV3);

	Vect4D vout1;
	Vect4D vout2;
	Vect4D vout3;

	vout1 = A * M;
	vout2 = B * M;
	vout3 = C * M;

	Vect4D_SIMD A_simd;
	A_simd = Vect4D_SIMD(1, 2, 3, 4);
	Vect4D_SIMD B_simd;
	B_simd = Vect4D_SIMD(11, 12, 13, 14);
	Vect4D_SIMD C_simd;
	C_simd = Vect4D_SIMD(21, 22, 23, 24);

	Vect4D_SIMD MV0_simd(1, 2, 3, 4);
	Vect4D_SIMD MV1_simd(5, 6, 7, 8);
	Vect4D_SIMD MV2_simd(9, 10, 11, 12);
	Vect4D_SIMD MV3_simd(13, 14, 15, 16);

	CHECK(M.v0.x == 1.0f);

	Matrix_SIMD M_simd;
	M_simd = Matrix_SIMD(MV0_simd, MV1_simd, MV2_simd, MV3_simd);

	Vect4D_SIMD vout1_simd;
	Vect4D_SIMD vout2_simd;
	Vect4D_SIMD vout3_simd;

	vout1_simd = A_simd * M_simd;
	vout2_simd = B_simd * M_simd;
	vout3_simd = C_simd * M_simd;


	CHECK(V_EQ(M.v0, M_simd.v0));
	CHECK(V_EQ(M.v1, M_simd.v1));
	CHECK(V_EQ(M.v2, M_simd.v2));
	CHECK(V_EQ(M.v3, M_simd.v3));

	CHECK(V_EQ(A, A_simd));
	CHECK(V_EQ(B, B_simd));
	CHECK(V_EQ(C, C_simd));

	CHECK(V_EQ(vout1, vout1_simd));
	CHECK(V_EQ(vout2, vout2_simd));
	CHECK(V_EQ(vout3, vout3_simd));
}

TEST(Matrix_Vect, SIMD_Tests)
{
	Vect4D A(1, 2, 3, 4);
	Vect4D B(11, 12, 13, 14);
	Vect4D C(21, 22, 23, 24);

	Vect4D MV0(1, 5, 9, 13);
	Vect4D MV1(2, 6, 10, 14);
	Vect4D MV2(3, 7, 11, 15);
	Vect4D MV3(4, 8, 12, 16);

	Matrix M(MV0, MV1, MV2, MV3);

	Vect4D vout1;
	Vect4D vout2;
	Vect4D vout3;

	vout1 = M * A;
	vout2 = M * B;
	vout3 = M * C;

	Vect4D_SIMD A_simd;
	A_simd = Vect4D_SIMD(1, 2, 3, 4);
	Vect4D_SIMD B_simd;
	B_simd = Vect4D_SIMD(11, 12, 13, 14);
	Vect4D_SIMD C_simd;
	C_simd = Vect4D_SIMD(21, 22, 23, 24);

	Vect4D_SIMD MV0_simd(1, 5, 9, 13);
	Vect4D_SIMD MV1_simd(2, 6, 10, 14);
	Vect4D_SIMD MV2_simd(3, 7, 11, 15);
	Vect4D_SIMD MV3_simd(4, 8, 12, 16);

	CHECK(M.v0.x == 1.0f);

	Matrix_SIMD M_simd;
	M_simd = Matrix_SIMD(MV0_simd, MV1_simd, MV2_simd, MV3_simd);

	Vect4D_SIMD vout1_simd;
	Vect4D_SIMD vout2_simd;
	Vect4D_SIMD vout3_simd;

	vout1_simd = M_simd * A_simd;
	vout2_simd = M_simd * B_simd;
	vout3_simd = M_simd * C_simd;


	CHECK(V_EQ(M.v0, M_simd.v0));
	CHECK(V_EQ(M.v1, M_simd.v1));
	CHECK(V_EQ(M.v2, M_simd.v2));
	CHECK(V_EQ(M.v3, M_simd.v3));

	CHECK(V_EQ(A, A_simd));
	CHECK(V_EQ(B, B_simd));
	CHECK(V_EQ(C, C_simd));

	CHECK(V_EQ(vout1, vout1_simd));
	CHECK(V_EQ(vout2, vout2_simd));
	CHECK(V_EQ(vout3, vout3_simd));
}

TEST(LERP, SIMD_Tests)
{
	Vect4D va(0.0f, 0.0f, 0.0f, 0.0f);
	Vect4D vb(10.0f, 20.0f, 30.0f, 40.0f);
	Vect4D vout;

	VectApp::Lerp(vout, va, vb, 0.0f);

	CHECK((vout.x == 0.0f));
	CHECK((vout.y == 0.0f));
	CHECK((vout.z == 0.0f));
	CHECK((vout.w == 0.0f));


	va.set(0.0f, 0.0f, 0.0f, 0.0f);
	vb.set(10.0f, 20.0f, 30.0f, 40.0f);

	VectApp::Lerp(vout, va, vb, 0.5f);

	CHECK((vout.x == 5.0f));
	CHECK((vout.y == 10.0f));
	CHECK((vout.z == 15.0f));
	CHECK((vout.w == 20.0f));

	va.set(0.0f, 0.0f, 0.0f, 0.0f);
	vb.set(10.0f, 20.0f, 30.0f, 40.0f);

	VectApp::Lerp(vout, va, vb, 0.25f);

	CHECK((vout.x == 2.5f));
	CHECK((vout.y == 5.0f));
	CHECK((vout.z == 7.50f));
	CHECK((vout.w == 10.0f));

	va.set(0.0f, 0.0f, 0.0f, 0.0f);
	vb.set(10.0f, 20.0f, 30.0f, 40.0f);

	VectApp::Lerp(vout, va, vb, 1.0f);

	CHECK((vout.x == 10.0f));
	CHECK((vout.y == 20.0f));
	CHECK((vout.z == 30.0f));
	CHECK((vout.w == 40.0f));

	Vect4D_SIMD va_simd(0.0f, 0.0f, 0.0f, 0.0f);
	Vect4D_SIMD vb_simd(10.0f, 20.0f, 30.0f, 40.0f);
	Vect4D_SIMD vout_simd;

	VectApp_SIMD::Lerp(vout_simd, va_simd, vb_simd, 0.0f);

	CHECK((vout_simd.x == 0.0f));
	CHECK((vout_simd.y == 0.0f));
	CHECK((vout_simd.z == 0.0f));
	CHECK((vout_simd.w == 0.0f));

	va_simd.set(0.0f, 0.0f, 0.0f, 0.0f);
	vb_simd.set(10.0f, 20.0f, 30.0f, 40.0f);

	VectApp_SIMD::Lerp(vout_simd, va_simd, vb_simd, 0.5f);

	CHECK((vout_simd.x == 5.0f));
	CHECK((vout_simd.y == 10.0f));
	CHECK((vout_simd.z == 15.0f));
	CHECK((vout_simd.w == 20.0f));

	va_simd.set(0.0f, 0.0f, 0.0f, 0.0f);
	vb_simd.set(10.0f, 20.0f, 30.0f, 40.0f);

	VectApp_SIMD::Lerp(vout_simd, va_simd, vb_simd, 0.25f);

	CHECK((vout_simd.x == 2.5f));
	CHECK((vout_simd.y == 5.0f));
	CHECK((vout_simd.z == 7.50f));
	CHECK((vout_simd.w == 10.0f));

	va_simd.set(0.0f, 0.0f, 0.0f, 0.0f);
	vb_simd.set(10.0f, 20.0f, 30.0f, 40.0f);

	VectApp_SIMD::Lerp(vout_simd, va_simd, vb_simd, 1.0f);

	CHECK((vout_simd.x == 10.0f));
	CHECK((vout_simd.y == 20.0f));
	CHECK((vout_simd.z == 30.0f));
	CHECK((vout_simd.w == 40.0f));

	Vect4D_SIMD vOut;
	Vect4D_SIMD A(1.00f, 2.0f, 3.0f, 4.0f);
	Vect4D_SIMD B(21.00f, 12.0f, 23.0f, 40.0f);

	VectApp_SIMD::Lerp(vOut, A, B, 0.5f);

	CHECK((vOut.x == 11.0f));
	CHECK((vOut.y == 7.0f));
	CHECK((vOut.z == 13.0f));
	CHECK((vOut.w == 22.0f));

	VectApp_SIMD::Lerp(vOut, A, vOut, 0.5f);

	CHECK((vOut.x == 6.0f));
	CHECK((vOut.y == 4.5f));
	CHECK((vOut.z == 8.0f));
	CHECK((vOut.w == 13.0f));

	Vect4D_SIMD vOut_SIMD;
	Vect4D_SIMD A_SIMD(1.00f, 2.0f, 3.0f, 4.0f);
	Vect4D_SIMD B_SIMD(21.00f, 12.0f, 23.0f, 40.0f);

	VectApp_SIMD::Lerp(vOut_SIMD, A_SIMD, B_SIMD, 0.5f);

	CHECK((vOut_SIMD.x == 11.0f));
	CHECK((vOut_SIMD.y == 7.0f));
	CHECK((vOut_SIMD.z == 13.0f));
	CHECK((vOut_SIMD.w == 22.0f))

		VectApp_SIMD::Lerp(vOut_SIMD, A_SIMD, vOut_SIMD, 0.5f);

	CHECK((vOut_SIMD.x == 6.0f));
	CHECK((vOut_SIMD.y == 4.5f));
	CHECK((vOut_SIMD.z == 8.0f));
	CHECK((vOut_SIMD.w == 13.0f));
}

TEST(rowMajor, SIMD_Tests)
{
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
		Vect4D  vOut;

		vOut = v * S * Rx *Ry * Rz * T;

		CHECK(S.m0 == 1.0f);

		Vect4D Ans;
		Ans = Vect4D(2.688213f, 2.448028f, 4.739550f, 0.747000f);

		CHECK(V_EQ(vOut, Ans));
	}
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

		vOut = v * S * Rx *Ry * Rz * T;

		Vect4D_SIMD Ans;
		Ans = Vect4D_SIMD(2.688213f, 2.448028f, 4.739550f, 0.747000f);

		CHECK(V_EQ(vOut, Ans));
	}
}

TEST(colMajor, SIMD_Tests)
{
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

		vOut = T * Rz * Ry * Rx * S * v;

		CHECK(S.m0 == 1.0f);

		Vect4D Ans;
		Ans = Vect4D(2.688213f, 2.448028f, 4.739550f, 0.747000f);

		CHECK(V_EQ(vOut, Ans));
	}
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

		vOut = T * Rz * Ry * Rx * S * v;
		Vect4D_SIMD Ans;
		Ans = Vect4D_SIMD(2.688213f, 2.448028f, 4.739550f, 0.747000f);

		CHECK(V_EQ(vOut, Ans));
	}
}


