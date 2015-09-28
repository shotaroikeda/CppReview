template <class T>
class C
{
public:
	C(const T val);
	~C();
	T getMe();

private:
	T mystery;
};

#include "temp_test.cpp"
