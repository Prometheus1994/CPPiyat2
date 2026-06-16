#include "RPN.hpp"

int unvalid_token(std::string expression)
{
	int i = 0;
	while (expression[i] != '\0')
	{
		if (i % 2 == 0 && !(expression[i] >= '0' && expression[i] <= '9') && expression[i] != '+' && expression[i] != '-' && expression[i] != '*' && expression[i] != '/')
			return 1;
		if (i % 2 == 1 && expression[i] != ' ')
			return 1;
		i++;
	}
	return 0;
}

void do_the_op(std::stack<int> &operands, char operator_)
{
	int second_nbr = operands.top();
	operands.pop();
	int first_nbr = operands.top();
	operands.pop();
	if (operator_ == '+')
		operands.push(first_nbr + second_nbr);
	if (operator_ == '-')
		operands.push(first_nbr - second_nbr);
	if (operator_ == '*')
		operands.push(first_nbr * second_nbr);
	if (operator_ == '/')
		operands.push(first_nbr / second_nbr);
}

int RPN(std::string expression)
{
	std::stack<int> operands;
	int i = 0;
	while (expression[i * 2] != '\0')
	{
		if (expression[i * 2] >= '0' && expression[i * 2] <= '9')
			operands.push(expression[i * 2] - '0');
		if (expression[i * 2] == '+' || expression[i * 2] == '-' || expression[i * 2] == '*' || expression[i * 2] == '/')
		{
			if (operands.size() < 2)
			{
				std::cerr << "Error: not enough operands for doing the operation." << std::endl;
				exit(1);
			}
			do_the_op(operands, expression[i * 2]);
		}
		i++;
	}

	if (operands.size() != 1)
	{
		std::cerr << "Error: finished with more than one number." << std::endl;
		exit(1);
	}
	return (operands.top());
}