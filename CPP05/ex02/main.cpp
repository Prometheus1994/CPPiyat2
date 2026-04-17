#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
	{
		Bureaucrat B1("Garden Observer", 140);
		Bureaucrat B2("Gardener", 130);
		ShrubberyCreationForm F1("Home");
		B1.signForm(F1);
		B2.executeForm(F1);
	}
	std::cout << std::endl;
	{
		Bureaucrat B1("Robotomizing Signer", 70);
		Bureaucrat B2("Robotomizer", 40);
		RobotomyRequestForm F2("HolyCrapTrash");
		B1.signForm(F2);
		B2.executeForm(F2);
	}
	std::cout << std::endl;
	{
		Bureaucrat B1("Prison Warden", 25);
		Bureaucrat B2("President", 1);
		PresidentialPardonForm F3("ZaphZoph");
		B2.executeForm(F3);
		B1.signForm(F3);
		B2.executeForm(F3);
	}
}