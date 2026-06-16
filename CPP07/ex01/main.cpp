#include <iostream>
#include "iter.hpp"

int main()
{
	{
		const int arr[] = {1, 2, 3, 4};;

		::iter(arr, sizeof(arr) / sizeof(int), print);
	}
	std::cout << std::endl << "----------" << std::endl;
	{
		char arr[] = {'a', 'b', 'c', 'd'};

		::iter(arr, sizeof(arr) / sizeof(char), print);
	}
	std::cout << std::endl << "----------" << std::endl;
	{
		float arr[] = {1.2, 3.4, 5.6, 7.8};

		::iter(arr, sizeof(arr) / sizeof(float), print<float>);
	}
	std::cout << std::endl;
}