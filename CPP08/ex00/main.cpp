#include "easyfind.hpp"
#include <iostream>
#include <vector>
#include <list>

int main()
{
	{
		try
		{
			std::vector<int> v;
			v.push_back(19);
			v.push_back(21);
			v.push_back(42);
			v.push_back(13);

			std::vector<int>::iterator it;
			it = easyfind(v, 13);
			std::cout << "The value " << *it << " has been found." << std::endl; 
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
			std::list<int> l;
			l.push_back(19);
			l.push_back(21);
			l.push_back(42);
			l.push_back(13);

			std::list<int>::iterator it;
			it = easyfind(l, 01);
			std::cout << "The value " << *it << " has been found." << std::endl; 
		}
		catch (std::exception &e)
		{
			std::cerr << e.what() << std::endl;
		}
	}	
}