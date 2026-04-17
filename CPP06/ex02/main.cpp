#include "Identify.hpp"

int main()
{
	{
		Base *p = generate();
		identify(p);
		delete p;
	}
	std::cout << "----------" << std::endl;
	{
		Base *p = generate();
		identify(*p);
		delete p;
	}
}