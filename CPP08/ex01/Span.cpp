#include "Span.hpp"

Span::Span()
{
	N = 10000;
}

Span::Span(unsigned int _N)
{
	N = _N;
}

Span::Span(const Span& other)
{
	N = other.N;
}

Span& Span::operator=(const Span& other)
{
	N = other.N;
	return *this;
}

Span::~Span() {}

const char* Span::ContainerIsFull::what() const throw()
{
	return "Container is already full";
}

void Span::addNumber(int nbr)
{
	if (v.end() - v.begin() == N)
		throw (ContainerIsFull());
	v.push_back(nbr);
}

const char* Span::SpanNotFound::what() const throw()
{
	return "No span can be found";
}

unsigned int Span::shortestSpan()
{
	if (v.end() - v.begin() < 2)
		throw (SpanNotFound());
	std::vector<int> sorted_v = v;
	sort(sorted_v.begin(), sorted_v.end());
	std::vector<int> spans;
	int i = 1;
	while (i < sorted_v.end() - sorted_v.begin())
	{
		spans.push_back(sorted_v[i] - sorted_v[i - 1]);
		i++;
	}
	return *std::min_element(spans.begin(), spans.end());
}

unsigned int Span::longestSpan()
{
	if (v.end() - v.begin() < 2)
		throw (SpanNotFound());
	return *std::max_element(v.begin(), v.end()) - *std::min_element(v.begin(), v.end());
}

const char* Span::NotEnoughSpace::what() const throw()
{
	return "There is not enough space to add numbers";
}

void Span::addNumbers(std::vector<int> nbrs)
{
	if (v.end() - v.begin() + nbrs.end() - nbrs.begin() > N)
		throw (NotEnoughSpace());
	v.insert(v.end(), nbrs.begin(), nbrs.end());
}

unsigned int current_seed = 1337;

unsigned int custom_rand()
{
	current_seed = 1103515245 * current_seed + 1337;
	return current_seed;
}