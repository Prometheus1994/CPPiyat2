#include "Form.hpp"

int main()
{
	{
		Bureaucrat B1;
		std::cout << B1 << std::endl;
		Form F1;
		std::cout << F1 << std::endl;
		B1.signForm(F1);
	}
	std::cout << std::endl;
	{
		Bureaucrat B2("Ami lHaj", 50);
		std::cout << B2 << std::endl;
		Form F2("28A+", 50, 25);
		std::cout << F2 << std::endl;
		B2.signForm(F2);
		std::cout << F2 << std::endl;
	}
}