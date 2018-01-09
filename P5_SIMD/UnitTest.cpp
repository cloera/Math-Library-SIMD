#include "UnitTest.h"

Test::Test(const char * pTestName)
	:SLink()
{
	// initialized data
	this->pName = pTestName;
	this->testFunc = this;

	// register it
	TestRegistry::AddTest(this);

}