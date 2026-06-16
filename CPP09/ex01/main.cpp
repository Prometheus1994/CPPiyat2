#include "RPN.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << "Error: there must be exactly one expression." << std::endl;
		return 1;
	}

	if (unvalid_token(argv[1]))
	{
		std::cerr << "Error: unvalid token." << std::endl;
		return 1;
	}

	std::cout << RPN(argv[1]) << std::endl;
}