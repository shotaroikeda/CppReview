#include <iostream>
#include "temp_test.h"
#include "inherit_test.h"

using namespace std;

int main(int argc, char* argv[])
{
	cout << "Hello world!\n";

	A a;
	cout <<"A: temp: " <<  a.getTemp() << endl;
	B b;
	cout << "B: dank: " << b.getDankMeme() << endl;

	cout << "A: SuperTest(): " << a.superTest() << endl;
	cout << "B: SuperTest(): " << b.superTest() << endl;

	cout << "B: temp: " << b.getTemp() << endl;
	return 0;
}
