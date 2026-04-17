#include "AForm.hpp"

AForm::AForm() : name("28A"), grade_to_sign(100), grade_to_execute(50)
{
	is_signed = false;
}

AForm::AForm(std::string _name, int _grade_to_sign, int _grade_to_execute) : name(_name), grade_to_sign(_grade_to_sign), grade_to_execute(_grade_to_execute)
{
	try
	{
		if (_grade_to_sign < 1 || _grade_to_execute < 1)
			throw (GradeTooHighException());
		if (_grade_to_sign > 150 || grade_to_execute > 150)
			throw (GradeTooLowException());
	}
	catch (std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	is_signed = false;
}

AForm::AForm(std::string _name, int _grade_to_sign, int _grade_to_execute, std::string _target) : name(_name), grade_to_sign(_grade_to_sign), grade_to_execute(_grade_to_execute)
{
	try
	{
		if (_grade_to_sign < 1 || _grade_to_execute < 1)
			throw (GradeTooHighException());
		if (_grade_to_sign > 150 || grade_to_execute > 150)
			throw (GradeTooLowException());
		target = _target;
	}
	catch (std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	is_signed = false;
}

AForm::AForm(const AForm &other) : name(other.name), grade_to_sign(other.grade_to_sign), grade_to_execute(other.grade_to_execute)
{
	is_signed = other.is_signed;
}

AForm& AForm::operator=(const AForm &other)
{
	is_signed = other.is_signed;
	return *this;
}

AForm::~AForm() {}

const char* AForm::GradeTooHighException::what() const throw()
{
	return "Grade is too high";
}

const char* AForm::GradeTooLowException::what() const throw()
{
	return "Grade is too low";
}

const char* AForm::FormIsNotSignedException::what() const throw()
{
	return "Form is not signed yet";
}

std::string AForm::getName() const
{
	return name;
}

bool AForm::getIsSigned() const
{
	return is_signed;
}

int AForm::getGradeToSign() const
{
	return grade_to_sign;
}

int AForm::getGradeToExecute() const
{
	return grade_to_execute;
}

std::string AForm::getTarget() const
{
	return target;
}

void AForm::beSigned(Bureaucrat signer)
{
	try
	{
		if (signer.getGrade() > grade_to_sign)
			throw (GradeTooLowException());
		is_signed = true;
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
}

std::ostream& operator<<(std::ostream& os, AForm& F)
{
	if (F.getIsSigned() == true)
		os << F.getName() << ", form grade to sign is " << F.getGradeToSign() << " and grade to execute is " << F.getGradeToExecute() << " and it is signed";
	else
		os << F.getName() << ", form grade to sign is " << F.getGradeToSign() << " and grade to execute is " << F.getGradeToExecute() << " and it is unsigned";
	return os;
}