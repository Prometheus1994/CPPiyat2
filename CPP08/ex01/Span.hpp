#ifndef SPAN_HPP
#define SPAN_HPP
#include <vector>

class Span
{
	unsigned int N;
	std::vector<int> v;
	class ContainerIsFull : public std::exception
	{
		const char* what() const throw();
	};
	class NotEnoughSpace : public std::exception
	{
		const char* what() const throw();
	};
	class SpanNotFound : public std::exception
	{
		const char* what() const throw();
	};

	public:
	Span();
	Span(unsigned int N);
	Span(const Span& other);
	Span& operator=(const Span& other);
	~Span();

	void addNumber(int nbr);
	unsigned int shortestSpan();
	unsigned int longestSpan();
	void addNumbers(std::vector<int> nbrs);
};

unsigned int custom_rand();

#endif