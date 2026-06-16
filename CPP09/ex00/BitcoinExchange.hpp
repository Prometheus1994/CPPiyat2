#include <iostream>
#include <fstream>
#include <string>
#include <map>

int is_bad_input(std::string line);
int is_unvalid_date(std::string line);
int is_not_a_positive_number(std::string line);
int is_a_too_large_number(std::string line);
float get_exchange_rate(std::map<std::string, float> data, std::string date);