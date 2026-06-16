#ifndef EASYFIND_HPP
#define EASYFIND_HPP
#include <exception>
#include <algorithm>

class NotFoundException : public std::exception
{
	const char* what() const throw()
	{
		return "Value not found";
	}
};

template <class T>
typename T::iterator easyfind(T &container, int val)
{
	typename T::iterator it;
	it = std::find(container.begin(), container.end(), val);
	if (it != container.end())
		return it;
	else
		throw (NotFoundException());
}

#endif