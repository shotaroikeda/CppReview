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

Meme::Meme(const string &name, const int &year)
{
	memeName = new string(name);
	memeYear = new int(year);
}

Meme::~Meme()
{
	delete memeName;
	delete memeYear;

	memeName = NULL;
	memeYear = NULL;
}

string Meme::getName() const
{
	return *memeName;
}

int Meme::getYear() const
{
	return *memeYear;
}

Doge::Doge(const string &name, const int &year) : Meme(name, year)
{
	noise = new string("Much very wowe\n");
}

Doge::Doge(const string &name, const int &year, const string &noise) : Meme(name, year)
{
	this->noise = new string(noise);
}

string Doge::getName() const
{
	return *noise;
}

Doge::~Doge()
{
	delete noise;
	noise = NULL;
}
