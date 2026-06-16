#include "Span.hpp"
#include <iostream>

int main()
{
	{
		try
		{
			Span sp = Span(5);
			sp.addNumber(6);
			sp.addNumber(3);
			sp.addNumber(17);
			sp.addNumber(9);
			sp.addNumber(11);

			std::cout << sp.shortestSpan() << std::endl;
			std::cout << sp.longestSpan() << std::endl;

			std::cout << "-----" << std::endl;
			sp.addNumber(96);
		}
		catch (std::exception &e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
	std::cout << "----------" << std::endl;
	{
		try
		{
			Span sp = Span(10000);
			int i = 0;
			while (i < 5000)
			{
				sp.addNumber(custom_rand());
				i++;
			}

			std::cout << "Shortest span before adding numbers: " << sp.shortestSpan() << std::endl;
			std::cout << "Longest span before adding numbers: " << sp.longestSpan() << std::endl;

			std::vector<int> v;
			i = 0;
			while (i < 5000)
			{
				v.push_back(custom_rand());
				i++;
			}

			std::cout << "-----" << std::endl;
			sp.addNumbers(v);

			std::cout << "Shortest span after adding numbers: " << sp.shortestSpan() << std::endl;
			std::cout << "Longest span after adding numbers: " << sp.longestSpan() << std::endl;

			std::cout << "-----" << std::endl;
			sp.addNumbers(v);
		}
		catch (std::exception &e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
	std::cout << "----------" << std::endl;
	{
		try
		{
			Span sp;
			sp.addNumber(1);

			std::cout << sp.shortestSpan() << std::endl;
			std::cout << sp.longestSpan() << std::endl;			
		}
		catch (std::exception &e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
}