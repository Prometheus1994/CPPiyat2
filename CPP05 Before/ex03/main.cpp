#include "Intern.hpp"

int main()
{
	{
		Intern someRandomIntern;
		AForm* rrf;
		rrf = someRandomIntern.makeForm("robotomy request", "Bender");

		Bureaucrat rsb("Robotomy Signer", 70);
		Bureaucrat reb("Robotomy Executor", 40);
		rsb.signForm(*rrf);
		reb.executeForm(*rrf);
	}
	std::cout << std::endl;
	{
		Intern someOtherRandomIntern;
		AForm* cmf;
		cmf = someOtherRandomIntern.makeForm("coffee making", "Cup");
	}
}