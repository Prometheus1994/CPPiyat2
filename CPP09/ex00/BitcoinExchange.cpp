#include "BitcoinExchange.hpp"

int is_bad_input(std::string line)
{
	if (line[4] != '-' || line[7] != '-' || (line[10] != ' ' || line[11] != '|' || line[12] != ' '))
		return 1;
	return 0;
}

int is_unvalid_date(std::string line)
{
	if (std::stoi(line.substr(5)) > 12 || std::stoi(line.substr(5)) < 1)
		return 1;
	if (std::stoi(line.substr(8)) > 31 || std::stoi(line.substr(8)) < 1)
		return 1;
	return 0;
}

int is_not_a_positive_number(std::string line)
{
	if (std::stof(line.substr(13)) < 0)
		return 1;
	return 0;
}

int is_a_too_large_number(std::string line)
{
	if (std::stof(line.substr(13)) > 1000)
		return 1;
	return 0;
}

float get_exchange_rate(std::map<std::string, float> data, std::string date)
{
	std::map<std::string, float>::iterator it = data.lower_bound(date);
	if (it->first == date || it->first == "2009-01-02")
		return it->second;
	else
	{
		it--;
		return it->second;
	}
}