#ifndef LERP_H
#define LERP_H

#include "Vect4D.h"

#define UNUSED_VAR(v) ((void )v)

class VectApp
{
		
public:

	// lerp
	static void Lerp( Vect4D &out, const Vect4D &a,  const Vect4D &b,  const float t );

};


#endif