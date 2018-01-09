//-----------------------------------------------------------------------------
// Copyright Ed Keenan 2016
// Optimized C++
//----------------------------------------------------------------------------- 

#ifndef OUTPUT_H
#define OUTPUT_H

class io
{
public:

	static void create(const char * const name);
	static void destroy();
	static FILE *getHandle();

private:
	// big four
	io();
	~io();
	io(const io &) = delete;
	io & operator=(const io &) = delete;

	// methods
	static io	*privGetInstance();
	void		privDestroy();
	void		privCreate(const char * const name);
	FILE		*privGetHandle();

	// data
	FILE *fileHandle;

};

#endif //output.h