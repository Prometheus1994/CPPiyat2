#include "BitcoinExchange.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << "Error: could not open file." << std::endl;
		return 1;
	}

	std::string line;
	std::map<std::string, float> data;

	std::ifstream data_file("data.csv");
	std::getline(data_file, line);
	while (std::getline(data_file, line))
		data[line.substr(0, 10)] = std::stof(line.substr(11));

	std::ifstream input_file(argv[1]);
	std::getline(input_file, line);
	while (std::getline(input_file, line))
	{
		if (is_bad_input(line))
			std::cerr << "Error: bad input => " << line << std::endl;
		else if (is_unvalid_date(line))
			std::cerr << "Error: date is unvalid." << std::endl;
		else if (is_not_a_positive_number(line))
			std::cerr << "Error: not a positive number." << std::endl;
		else if (is_a_too_large_number(line))
			std::cerr << "Error: too large a number." << std::endl;
		else
			std::cout << line.substr(0, 10) << " => " << line.substr(13) << " = " << std::stof(line.substr(13)) * get_exchange_rate(data, line.substr(0, 10)) << std::endl;
	}
}