#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : name("Junior Officer")
{
	grade = 150;
}

Bureaucrat::Bureaucrat(std::string _name, int _grade) : name(_name)
{
	try
	{
		if (_grade < 1)
			throw (GradeTooHighException());
		if (_grade > 150)
			throw (GradeTooLowException());
		grade = _grade;
	}
	catch (std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
}

Bureaucrat::Bureaucrat(const Bureaucrat &other) : name(other.name)
{
	grade = other.grade;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other)
{
	grade = other.grade;
	return *this;
}

Bureaucrat::~Bureaucrat() {}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return "Grade is too high";
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return "Grade is too low";
}

std::string Bureaucrat::getName() const
{
	return name;
}

int Bureaucrat::getGrade() const
{
	return grade;
}

void Bureaucrat::promote()
{
	try
	{
		if (grade == 1)
			throw (GradeTooHighException());
		grade--;
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
}

void Bureaucrat::demote()
{
	try
	{
		if (grade == 150)
			throw (GradeTooLowException());
		grade++;
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
}

std::ostream& operator<<(std::ostream &os, Bureaucrat &B)
{
	os << B.getName() << ", bureaucrat grade " << B.getGrade();
	return os;
}