#include "Intern.hpp"

Intern::Intern() {}

Intern::Intern(const Intern &other)
{
	(void) other;
}

Intern& Intern::operator=(const Intern &other)
{
	(void) other;
	return *this;
}

Intern::~Intern() {}

AForm* Intern::makeForm(std::string name, std::string target)
{
	std::string forms[] = {"shrubbery creation", "robotomy request", "presidential pardon"};
	int i = 0;
	while (i < 3)
	{
		if (name == forms[i])
		{
			switch (name[0])
			{
				case 's':
					std::cout << "Intern creates " << name << std::endl;
					return (new ShrubberyCreationForm(target));
				case 'r':
					std::cout << "Intern creates " << name << std::endl;
					return (new RobotomyRequestForm(target));
				case 'p':
					std::cout << "Intern creates " << name << std::endl;
					return (new PresidentialPardonForm(target));
			}
		}
		i++;
	}
	std::cerr << "Form name \"" << name << "\" does not exist" << std::endl;
	return (NULL);
}