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

class Meme
{
public:
        Meme(const string &name, const int &year); // Tell others that we promise not to change the state
        virtual ~Meme(); // Must declare virtual or delete *base_class is undefined
        string getName() const; // Tell others that this func will not change the state of the object
        int getYear() const;

private:
        string * memeName;
        int * memeYear;
};

class Doge: public Meme
{
public:
        Doge(const string &name, const int &year);
        Doge(const string &name, const int &year, const string &noise);
        ~Doge();

        string getNoise();
	string getName() const;

private:
        string * noise;

};

// class PizzaDog: public Meme
// {
// public:
//      PizzaDog(const string &name, const int &year);
//      PizzaDog(const string &name, const int &year, const string &noise);
//      ~PizzaDog();

//      string getNoise();

// private:
//      string * noise;

// }

#endif
