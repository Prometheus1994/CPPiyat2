#ifndef FORM_HPP
#define FORM_HPP
#include "Bureaucrat.hpp"

class Form
{
	const std::string name;
	bool is_signed;
	const int grade_to_sign;
	const int grade_to_execute;

	class GradeTooHighException : public std::exception
	{
		const char* what() const throw();
	};
	class GradeTooLowException : public std::exception
	{
		const char* what() const throw();
	};

	public:
	Form();
	Form(std::string name, int grade_to_sign, int grade_to_execute);
	Form(const Form &other);
	Form& operator=(const Form &other);
	~Form();

	std::string getName() const;
	bool getIsSigned() const;
	int getGradeToSign() const;
	int getGradeToExecute() const;

	void beSigned(Bureaucrat signer);
};

std::ostream& operator<<(std::ostream& os, Form& F);

#endif