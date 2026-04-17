#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP
#include <iostream>
#include <string>
#include <exception>
class AForm;

class Bureaucrat
{
	const std::string name;
	int grade;
	class GradeTooHighException : public std::exception
	{
		const char* what() const throw();
	};
	class GradeTooLowException : public std::exception
	{
		const char* what() const throw();
	};
	class FormIsNotSignedException : public std::exception
	{
		const char* what() const throw();
	};

	public:
	Bureaucrat();
	Bureaucrat(std::string name, int grade);
	Bureaucrat(const Bureaucrat &other);
	Bureaucrat& operator=(const Bureaucrat& other);
	~Bureaucrat();

	std::string getName() const;
	int getGrade() const;

	void promote();
	void demote();

	void signForm(AForm& form);

	void executeForm(AForm const & form) const;
};

std::ostream& operator<<(std::ostream &os, Bureaucrat &B);

#endif