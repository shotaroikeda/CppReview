#include <string>
using namespace std;

#ifndef INHERIT_TEST
#define INHERIT_TEST

class A
{
public:
	A();
	~A();
	int getTemp();
	int superTest();

private:
	int temp;
};

       
class B: public A
{
public:
	B();
	~B();
	string getDankMeme();
	int superTest();

private:
	string dankMeme;
};

#endif
