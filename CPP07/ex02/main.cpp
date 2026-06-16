#include <iostream>
#include "Array.hpp"

int main()
{
	try
	{
		Array<char> A(26);

		unsigned int i = 0;
		while (i < A.size())
		{
			A[i] = 'A' + i;
			i++;
		}

		i = 0;
		while (i < A.size())
		{
			std::cout << A[i] << ", ";
			i++;
		}

		std::cout << std::endl << "----------" << std::endl;

		A[30] = '$';
	}
	catch (std::exception &e)
	{
		std::cout << "The index is out of bounds" << std::endl;
	}
}