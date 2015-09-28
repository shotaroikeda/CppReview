#include "inherit_test.h"

A::A()
{
	temp = 8;
}

A::~A()
{
}

int A::getTemp()
{
	return temp;
}

int A::superTest()
{
	return 10;
}

B::B()
{
	dankMeme = "Doge.";
}

B::~B()
{
	
}

string B::getDankMeme()
{
	return dankMeme;
}

int B::superTest()
{
	return -1;
}
