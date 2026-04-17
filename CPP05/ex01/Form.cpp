#include "Form.hpp"

Form::Form() : name("28A"), grade_to_sign(100), grade_to_execute(50)
{
	is_signed = false;
}

Form::Form(std::string _name, int _grade_to_sign, int _grade_to_execute) : name(_name), grade_to_sign(_grade_to_sign), grade_to_execute(_grade_to_execute)
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

Form::Form(const Form &other) : name(other.name), grade_to_sign(other.grade_to_sign), grade_to_execute(other.grade_to_execute)
{
	is_signed = other.is_signed;
}

Form& Form::operator=(const Form &other)
{
	is_signed = other.is_signed;
	return *this;
}

Form::~Form() {}

const char* Form::GradeTooHighException::what() const throw()
{
	return "Grade is too high";
}

const char* Form::GradeTooLowException::what() const throw()
{
	return "Grade is too low";
}

std::string Form::getName() const
{
	return name;
}

bool Form::getIsSigned() const
{
	return is_signed;
}

int Form::getGradeToSign() const
{
	return grade_to_sign;
}

int Form::getGradeToExecute() const
{
	return grade_to_execute;
}

void Form::beSigned(Bureaucrat signer)
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

std::ostream& operator<<(std::ostream& os, Form& F)
{
	if (F.getIsSigned() == true)
		os << F.getName() << ", form grade to sign is " << F.getGradeToSign() << " and grade to execute is " << F.getGradeToExecute() << " and it is signed";
	else
		os << F.getName() << ", form grade to sign is " << F.getGradeToSign() << " and grade to execute is " << F.getGradeToExecute() << " and it is unsigned";
	return os;
}