#ifndef AFORM_HPP
#define AFORM_HPP
#include "Bureaucrat.hpp"

class AForm
{
	const std::string name;
	bool is_signed;
	const int grade_to_sign;
	const int grade_to_execute;
	std::string target;

	protected:
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
	AForm();
	AForm(std::string name, int grade_to_sign, int grade_to_execute);
	AForm(std::string name, int grade_to_sign, int grade_to_execute, std::string target);
	AForm(const AForm &other);
	AForm& operator=(const AForm &other);
	~AForm();

	std::string getName() const;
	bool getIsSigned() const;
	int getGradeToSign() const;
	int getGradeToExecute() const;
	std::string getTarget() const;

	void beSigned(Bureaucrat signer);

	virtual void execute(Bureaucrat const & executor) const = 0;
};

std::ostream& operator<<(std::ostream& os, AForm& F);

#endif