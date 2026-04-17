#ifndef SCALAR_CONVERTER_HPP
#define SCALAR_CONVERTER_HPP

#include <iostream>
#include <cstdlib>
#include <climits>
#include <cfloat>

class ScalarConverter
{
	ScalarConverter();
	ScalarConverter(const ScalarConverter& other);
	ScalarConverter& operator=(const ScalarConverter& other);
	~ScalarConverter();

	static bool is_char_literal(const char *literal);
	static bool is_int_literal(const char *literal);
	static bool is_float_literal(const char *literal);
	static bool is_double_literal(const char *literal);
	static bool is_integer_float(const char *literal);
	static bool is_integer_double(const char *literal);

	static bool is_minff_literal(const char *literal);
	static bool is_pinff_literal(const char *literal);
	static bool is_nanf_literal(const char *literal);
	static bool is_minf_literal(const char *literal);
	static bool is_pinf_literal(const char *literal);
	static bool is_nan_literal(const char *literal);

	public:
	static void convert(const char *literal);
};

#endif