#include <iostream>
#include "temp_test.h"
#include "inherit_test.h"
#include "linked_list.hpp"

using namespace std;

// int main(int argc, char* argv[])
// {
//      cout << "Hello world!\n";

//      A a;
//      cout <<"A: temp: " <<  a.getTemp() << endl;
//      B b;
//      cout << "B: dank: " << b.getDankMeme() << endl;

//      cout << "A: SuperTest(): " << a.superTest() << endl;
//      cout << "B: SuperTest(): " << b.superTest() << endl;

//      cout << "B: temp: " << b.getTemp() << endl;
//      return 0;
// }

class Potato
{
public:
        int *pot;
        Potato()
                {
                        pot = new int(100);
                }
        ~Potato()
                {
                        delete pot;
                }

        void copy(const Potato &other)
                {
                        this->pot = new int(*other.pot);
                }

        Potato &operator =(const Potato &other)
                {
                        if (this != &other)
                        {
                                copy(other);
                        }

                        return *this;
                }

        Potato(const Potato &other)
                {
                        copy(other);
                }

};

class PotatoParty
{
public:
        Potato **potato;
	PotatoParty()
                {
                        // generate a lot of potato
                        potato = new Potato* [10];
                                for (int i = 0; i < 10; i++)
                                {
                                        potato[i] = new Potato();
                                }
                };

        ~PotatoParty() {
		for (int i = 0; i < 10; i++)
			delete potato[i];

                delete[] potato;
        };
};

int main(int argc, char* argv[])
{
	LinkedList<int> t;

	t.insertAt(1, 10);
	t.insertFront(30);
	t.insertBack(50);
	int i = 1000;
	t.insertBack(i);
	t.printAll();

	std::cout << "Now changing i magic\n";
	i = 10;
	t.printAll();

	std::cout << "2nd position: " << t[1] << std::endl;

	t.removeAt(1);
	t.changeAt(2, 9001);
	t.printAll();
        return 0;
}
