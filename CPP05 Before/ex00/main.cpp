#include "Bureaucrat.hpp"

int main()
{
	{
		Bureaucrat B1("Vice President", 2);
		std::cout << B1 << std::endl;
		B1.promote();
		std::cout << "If the President died the Vice President becomes President." << std::endl;
		std::cout << B1 << std::endl;
		B1.promote();
		std::cout << "The former Vice President can't be promoted more." << std::endl;
	}
	std::cout << std::endl;
	{
		Bureaucrat B2;
		std::cout << B2 << std::endl;
		B2.demote();
		std::cout << "The Junior Officer is the last title. There is nothing beneath it." << std::endl;
	}
	std::cout << std::endl;
	{
		Bureaucrat B3("Anarchist", 1312);
		std::cout << "There is no 1312 grade for Anarchist in the hierarchy." << std::endl;
	}
}