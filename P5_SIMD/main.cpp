#include <stdlib.h>
#include <stdio.h>

#include "Timer.h"
#include "output.h"
#include "UnitTest.h"

#include "Vect4D_SIMD.h"
#include "PerformanceTest.h"
#include "Vect4D.h"
#include "matrix.h"
#include "Matrix_SIMD.h"
#include "LERP.h"
#include "LERP_SIMD.h"

#ifdef _DEBUG
	#define FACTOR 1
#else
	#define FACTOR 10
#endif

int main()
{
	io::create("Christian Loera");

	// Leave the following functions allow
	// DO NOT reorder them
        // Any modification to unit test is an academic violation
        // all unit tests need to pass, for the test to run
	int testsPassed = TestRegistry::RunTests();

	
	// Performance tests
	printf("\nPerformance tests: Begin()\n");

	if (testsPassed != 7)
	{
		fprintf(io::getHandle(), "\n  ERROR---> didn't pass unit tests\n");
		fprintf(io::getHandle(), "\n    Cannot run performance tests\n\n\n");
	}
	else
	{
		timer::initTimer();
		timer t12, t11, t10, t9, t8, t7, t6, t5, t4, t3, t2, t1;

		// --------------- VECT 4D ----------------------------------------------

		Vect4D x;
		fprintf(io::getHandle(),"---------- Vect4D ----------------\n");
		printf("                 : Vect4D\n");
		t2.tic();
		for( int j = 0; j < 6000000 * FACTOR; j++)
		{
			x = test();
		}
		t2.toc();

		// --------------- VECT 4D SIMD ----------------------------------------------

		fprintf(io::getHandle(),"  Vect4D Orig: %f  (result):%f %f %f %f\n",t2.timeInSeconds(),x.x,x.y,x.z,x.w);
		printf("                 : Vect4D_SIMD\n");
		Vect4D_SIMD x_SIMD;
		t1.tic();
		for( int i = 0; i < 6000000* FACTOR; i++)
		{
			x_SIMD = test_simd();
		}
		t1.toc();
	
		fprintf(io::getHandle(),"  Vect4D_SIMD: %f  (result):%f %f %f %f\n",t1.timeInSeconds(),x_SIMD.x, x_SIMD.y, x_SIMD.z, x_SIMD.w );
		fprintf(io::getHandle(),"       Faster: %f\n",t2.timeInSeconds()/t1.timeInSeconds() );

		// --------------- MATRIX ----------------------------------------------

		fprintf(io::getHandle(),"\n\n---------- Matrix ----------------\n");
			printf("                 : Matrix\n");
		Vect4D y;
		t3.tic();
		for( int k = 0; k < 1000* FACTOR; k++)
		{
			y = matrix_test();
		}
		t3.toc();
	

		// --------------- Matrix SIMD ----------------------------------------------

		fprintf(io::getHandle(),"  Matrix Orig: %f  (result):%f %f %f %f\n",t3.timeInSeconds(),y.x,y.y,y.z,y.w);
		printf("                 : Matrix_SIMD\n");
		Vect4D_SIMD y_SIMD;
		t4.tic();
		for( int k = 0; k < 1000* FACTOR; k++)
		{
			y_SIMD = matrix_SIMD_test();
		}
		t4.toc();
	

		fprintf(io::getHandle(),"  Matrix SIMD: %f  (result):%f %f %f %f\n",t4.timeInSeconds(), y_SIMD.x, y_SIMD.y, y_SIMD.z, y_SIMD.w);
		fprintf(io::getHandle(),"       Faster: %f\n",t3.timeInSeconds()/t4.timeInSeconds());

		// --------------- Vect * Matrix ----------------------------------------------

		fprintf(io::getHandle(),"\n\n---------- Vect * Matrix ----------------\n");
		printf("                 : Vect * Matrix\n");
		t5.tic();
		for( int k=0; k<10000* FACTOR; k++)
		{
			Vect4D C = vectMultMatrix_test();
		}
		t5.toc();

		// --------------- Vect * Matrix (SIMD) ----------------------------------------------

		fprintf(io::getHandle(),"  Vect*Matrix Orig: %f\n",t5.timeInSeconds());
		printf("                 : Vect * Matrix (SIMD)\n");
		t6.tic();
		for( int k=0; k<10000* FACTOR; k++)
		{
			Vect4D_SIMD C = vectMultMatrix_SIMD_test();
		}
		t6.toc();
		fprintf(io::getHandle(),"  Vect*Matrix_SIMD: %f\n",t6.timeInSeconds());
		fprintf(io::getHandle(),"            Faster: %f\n",t5.timeInSeconds()/t6.timeInSeconds());



		// --------------- Matrix * Vector ----------------------------------------------

		fprintf(io::getHandle(), "\n\n---------- Matrix * Vect ----------------\n");
		printf("                 : Matrix * Vect\n");
		t5.tic();
		for (int k = 0; k < 10000 * FACTOR; k++)
		{
			Vect4D C = matrixMultVect_test();
		}
		t5.toc();

		// --------------- Vect * Matrix (SIMD) ----------------------------------------------

		fprintf(io::getHandle(), "  Matrix*Vect Orig: %f\n", t5.timeInSeconds());
		printf("                 : Matrix * Vect (SIMD)\n");
		t6.tic();
		for (int k = 0; k < 10000 * FACTOR; k++)
		{
			Vect4D_SIMD C = matrixMultVect_SIMD_test();
		}
		t6.toc();
		fprintf(io::getHandle(), "  Matrix*Vect_SIMD: %f\n", t6.timeInSeconds());
		fprintf(io::getHandle(), "            Faster: %f\n", t5.timeInSeconds() / t6.timeInSeconds());

		// --------------- LERP ----------------------------------------------

		fprintf(io::getHandle(),"\n\n---------- LERP ----------------\n");
		printf("                 : LERP\n");
		Vect4D LERP_C;
		t7.tic();
		for( int k=0; k<1000000* FACTOR; k++)
		{
			LERP_C = LERP_Tests();
		}
		t7.toc();
	
		fprintf(io::getHandle(),"  LERP Orig: %f   (result):%f %f %f %f\n",t7.timeInSeconds(),LERP_C.x,LERP_C.y,LERP_C.z,LERP_C.w);

		// --------------- LERP SIMD ----------------------------------------------

		printf("                 : LERP SIMD\n");
		Vect4D_SIMD LERP_SIMD_C;
		t8.tic();
		for( int k=0; k<1000000* FACTOR; k++)
		{
			LERP_SIMD_C = LERP_SIMD_Tests();
		}
		t8.toc();

		fprintf(io::getHandle(),"  LERP SIMD: %f   (result):%f %f %f %f\n",t8.timeInSeconds(), LERP_SIMD_C.x, LERP_SIMD_C.y,LERP_SIMD_C.z, LERP_SIMD_C.w);
		fprintf(io::getHandle(),"     Faster: %f\n",t7.timeInSeconds()/t8.timeInSeconds());


		// --------------- RowMajor ----------------------------------------------

		fprintf(io::getHandle(), "\n\n---------- rowMajor ----------------\n");
		printf("                 : rowMajor\n");
		Vect4D Row_C;
		t9.tic();
		for (int k = 0; k < 10000 * FACTOR; k++)
		{
			Row_C = rowMajor_test();
		}
		t9.toc();
		
		fprintf(io::getHandle(), " rowMajor Orig: %f   (result):%f %f %f %f\n", t9.timeInSeconds(), Row_C.x, Row_C.y, Row_C.z, Row_C.w);

		// --------------- RowMajor SIMD ----------------------------------------------
		printf("                 : rowMajor SIMD\n");
		Vect4D_SIMD Row_SIMD_C;
		t10.tic();
		for (int k = 0; k < 10000 * FACTOR; k++)
		{
			Row_SIMD_C = rowMajor_SIMD_test();
		}
		t10.toc();
		
		fprintf(io::getHandle(), " rowMajor SIMD: %f   (result):%f %f %f %f\n", t10.timeInSeconds(), Row_SIMD_C.x, Row_SIMD_C.y, Row_SIMD_C.z, Row_SIMD_C.w);
		fprintf(io::getHandle(), "        Faster: %f\n", t9.timeInSeconds() / t10.timeInSeconds());

	


		// --------------- ColMajor ----------------------------------------------

		fprintf(io::getHandle(), "\n\n---------- colMajor ----------------\n");
		printf("                 : colMajor\n");
		Vect4D Col_C;
		t11.tic();
		for (int k = 0; k < 10000 * FACTOR; k++)
		{
			Col_C = rowMajor_test();
		}
		t11.toc();
		
		fprintf(io::getHandle(), " colMajor Orig: %f    (result):%f %f %f %f\n", t11.timeInSeconds(), Col_C.x, Col_C.y, Col_C.z, Col_C.w);

		// --------------- colMajor SIMD ----------------------------------------------
		printf("                 : colMajor SIMD\n");
		Vect4D_SIMD Col_SIMD_C;
		t12.tic();
		for (int k = 0; k < 10000 * FACTOR; k++)
		{
			Col_SIMD_C = colMajor_SIMD_test();
		}
		t12.toc();
		
		fprintf(io::getHandle(), " colMajor SIMD: %f   (result):%f %f %f %f\n", t12.timeInSeconds(), Col_SIMD_C.x, Col_SIMD_C.y, Col_SIMD_C.z, Col_SIMD_C.w);
		fprintf(io::getHandle(), "        Faster: %f\n", t11.timeInSeconds() / t12.timeInSeconds());

		// Tests done
		printf("Performance tests: done() \n\n");


		// Bugs with Lerp: here's a check (please leave it)
		printf(" %f %f %f %f\n", LERP_C.x, LERP_C.y, LERP_C.z, LERP_C.w);
		printf(" %f %f %f %f\n", LERP_SIMD_C.x, LERP_SIMD_C.y, LERP_SIMD_C.z, LERP_SIMD_C.w);

		Vect4D_SIMD vOut;
		Vect4D_SIMD A(1.00f, 2.0f, 3.0f, 4.0f);
		Vect4D_SIMD B(21.00f, 12.0f, 23.0f, 40.0f);

		VectApp_SIMD::Lerp(vOut, A, B, 0.65f);
		VectApp_SIMD::Lerp(vOut, A, vOut, 0.65f);
		printf("orig %f %f %f %f\n", vOut.x, vOut.y, vOut.z, vOut.w);

		Vect4D_SIMD vOut_SIMD;
		Vect4D_SIMD A_SIMD(1.00f, 2.0f, 3.0f, 4.0f);
		Vect4D_SIMD B_SIMD(21.00f, 12.0f, 23.0f, 40.0f);

		VectApp_SIMD::Lerp(vOut_SIMD, A_SIMD, B_SIMD, 0.65f);
		VectApp_SIMD::Lerp(vOut_SIMD, A_SIMD, vOut_SIMD, 0.65f);
		printf("simd %f %f %f %f\n", vOut_SIMD.x, vOut_SIMD.y, vOut_SIMD.z, vOut_SIMD.w);
	}


	

}

