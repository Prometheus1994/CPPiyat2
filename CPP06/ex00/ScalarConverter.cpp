#include "ScalarConverter.hpp"

bool ScalarConverter::is_char_literal(const char *literal)
{
	if (literal[1] == '\0')
		return true;
	return false;
}

bool ScalarConverter::is_int_literal(const char *literal)
{
	char *end;
	std::strtol(literal, &end, 0);
	if (*end == '\0')
		return true;
	return false;
}

bool ScalarConverter::is_float_literal(const char *literal)
{
	char *end;
	std::strtof(literal, &end);
	if (*end == 'f' && *(end + 1) == '\0' && literal[2] != 'n')
		return true;
	return false;
}

bool ScalarConverter::is_double_literal(const char *literal)
{
	char *end;
	std::strtod(literal, &end);
	if (*end == '\0' && literal[2] != 'n')
		return true;
	return false;
}

bool ScalarConverter::is_integer_float(const char *literal)
{
	char *end;
	std::strtol(literal, &end, 0);
	if (*end == '.' && *(end + 1) == '0' && *(end + 2) == 'f' && *(end + 3) == '\0')
		return true;
	return false;
}

bool ScalarConverter::is_integer_double(const char *literal)
{
	char *end;
	std::strtol(literal, &end, 0);
	if (*end == '.' && *(end + 1) == '0' && *(end + 2) == '\0')
		return true;
	return false;
}

bool ScalarConverter::is_minff_literal(const char *literal)
{
	std::string lit = literal;
	if (lit == "-inff")
		return true;
	return false;
}

bool ScalarConverter::is_pinff_literal(const char *literal)
{
	std::string lit = literal;
	if (lit == "+inff")
		return true;
	return false;
}

bool ScalarConverter::is_nanf_literal(const char *literal)
{
	std::string lit = literal;
	if (lit == "nanf")
		return true;
	return false;
}

bool ScalarConverter::is_minf_literal(const char *literal)
{
	std::string lit = literal;
	if (lit == "-inf")
		return true;
	return false;
}

bool ScalarConverter::is_pinf_literal(const char *literal)
{
	std::string lit = literal;
	if (lit == "+inf")
		return true;
	return false;
}

bool ScalarConverter::is_nan_literal(const char *literal)
{
	std::string lit = literal;
	if (lit == "nan")
		return true;
	return false;
}

void ScalarConverter::convert(const char *literal)
{
	char   c;
	int    i;
	float  f;
	double d;
	char *end;
	if (is_int_literal(literal))
	{
		i = static_cast<int>(strtol(literal, &end, 0));

		c = static_cast<char>(i);
		f = static_cast<float>(i);
		d = static_cast<double>(i);

		std::cout << "char: ";
		if (strtol(literal, &end, 0) >= 32 && strtol(literal, &end, 0) <= 126)
			std::cout << "'" << c << "'" << std::endl;
		else if (strtol(literal, &end, 0) >= 0 && strtol(literal, &end, 0) <= 127)
			std::cout << "Non displayable" << std::endl;
		else
			std::cout << "impossible" << std::endl;
		std::cout << "int: ";
		if (strtol(literal, &end, 0) >= INT_MIN && strtol(literal, &end, 0) <= INT_MAX)
			std::cout << i << std::endl;
		else
			std::cout << "impossible" << std::endl;
		std::cout << "float: " << f << ".0f" << std::endl;
		std::cout << "double: " << d << ".0" << std::endl;
	}
	else if (is_char_literal(literal))
	{
		c = static_cast<char>(literal[0]);

		i = static_cast<int>(c);
		f = static_cast<float>(c);
		d = static_cast<double>(c);

		std::cout << "char: " << "'" << c << "'" << std::endl;
		std::cout << "int: " << i << std::endl;
		std::cout << "float: " << f << ".0f" << std::endl;
		std::cout << "double: " << d << ".0" << std::endl;
	}
	else if (is_float_literal(literal))
	{
		f = static_cast<float>(strtof(literal, &end));

		c = static_cast<char>(f);
		i = static_cast<int>(f);
		d = static_cast<double>(f);

		std::cout << "char: ";
		if (strtol(literal, &end, 0) >= 32 && strtol(literal, &end, 0) <= 126)
			std::cout << "'" << c << "'" << std::endl;
		else if (strtol(literal, &end, 0) >= 0 && strtol(literal, &end, 0) <= 127)
			std::cout << "Non displayable" << std::endl;
		else
			std::cout << "impossible" << std::endl;
		std::cout << "int: ";
		if (static_cast<long>(f) >= INT_MIN && static_cast<long>(f) <= INT_MAX)
			std::cout << i << std::endl;
		else
			std::cout << "impossible" << std::endl;
		std::cout << "float: ";
		if (strtod(literal, &end) >= -FLT_MAX && strtod(literal, &end) <= FLT_MAX && is_integer_float(literal))
			std::cout << f << ".0f" << std::endl;
		else if (strtod(literal, &end) >= -FLT_MAX && strtod(literal, &end) <= FLT_MAX)
			std::cout << f << "f" << std::endl;
		else
			std::cout << "impossible" << std::endl;
		std::cout << "double: ";
		if (is_integer_float(literal))
			std::cout << d << ".0" << std::endl;
		else
			std::cout << d << std::endl;
	}
	else if (is_double_literal(literal))
	{
		d = static_cast<double>(strtod(literal, &end));

		c = static_cast<char>(d);
		i = static_cast<int>(d);
		f = static_cast<float>(d);

		std::cout << "char: ";
		if (strtol(literal, &end, 0) >= 32 && strtol(literal, &end, 0) <= 126)
			std::cout << "'" << c << "'" << std::endl;
		else if (strtol(literal, &end, 0) >= 0 && strtol(literal, &end, 0) <= 127)
			std::cout << "Non displayable" << std::endl;
		else
			std::cout << "impossible" << std::endl;
		std::cout << "int: ";
		if (static_cast<long>(d) >= INT_MIN && static_cast<long>(d) <= INT_MAX)
			std::cout << i << std::endl;
		else
			std::cout << "impossible" << std::endl;
		std::cout << "float: ";
		if (is_integer_double(literal))
			std::cout << f << ".0f" << std::endl;
		else
			std::cout << f << "f" << std::endl;
		std::cout << "double: ";
		if (is_integer_double(literal))
			std::cout << d << ".0" << std::endl;
		else
			std::cout << d << std::endl;
	}
	else if (is_minff_literal(literal) || is_minf_literal(literal))
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: -inff" << std::endl;
		std::cout << "double: -inf" << std::endl;
	}
	else if (is_pinff_literal(literal) || is_pinf_literal(literal))
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: +inff" << std::endl;
		std::cout << "double: +inf" << std::endl;
	}
	else if (is_nanf_literal(literal) || is_nan_literal(literal))
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: nanf" << std::endl;
		std::cout << "double: nan" << std::endl;
	}
	else
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: impossible" << std::endl;
		std::cout << "double: impossible" << std::endl;
	}
}