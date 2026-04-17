#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("Shrubbery Creation Form", 145, 137) {}

ShrubberyCreationForm::ShrubberyCreationForm(std::string _target) : AForm("Shrubbery Creation Form", 145, 137, _target) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other) : AForm(other) {}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{
	AForm::operator=(other);
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	if (executor.getGrade() > getGradeToExecute())
		throw (GradeTooLowException());
	if (!getIsSigned())
		throw (FormIsNotSignedException());
	std::ofstream file(getTarget() + "_shrubbery");
	file << "     ______\n" <<
			"  .-\"      \"-.\n" <<
			" /            \\\n" <<
			"|              |\n" <<
			" \\,          ,/\n" <<
			"   \"--------\"\n" <<
			"       ||";
}