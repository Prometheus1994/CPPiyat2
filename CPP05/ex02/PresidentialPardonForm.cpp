#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("Presidential Pardon Form", 25, 5) {}

PresidentialPardonForm::PresidentialPardonForm(std::string _target) : AForm("Presidential Pardon Form", 25, 5, _target) {}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other) : AForm(other) {}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm &other)
{
	AForm::operator=(other);
	return *this;
}

PresidentialPardonForm::~PresidentialPardonForm() {}

void PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
	if (executor.getGrade() > getGradeToExecute())
		throw (GradeTooLowException());
	if (!getIsSigned())
		throw (FormIsNotSignedException());
	std::cout << getTarget() << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}