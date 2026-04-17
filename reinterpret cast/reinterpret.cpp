#include <iostream>

struct Data
{
	char a; char b; char c; char d;
	char e; char f; char g; char h;
	char i;
};

int main()
{
	Data d;
	d.a = 0; d.b = 1; d.c = 2; d.d = 3;
	d.e = 4; d.f = 5; d.g = 6; d.h = 7;
	d.i = 8;

	int *p = reinterpret_cast<int*>(&d);
	std::cout << (int)*p << std::endl;
	float f = 3.14;
	int *g = reinterpret_cast<int*>(&f);
	std::cout << *g << std::endl;
}