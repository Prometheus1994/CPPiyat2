#ifndef ITER_HPP
#define ITER_HPP

template <class T>
void print(T &t)
{
	std::cout << t << ", ";
}

template <class T>
void print(const T &t)
{
	std::cout << t << ", ";
}

template <class T>
void iter(T *arr, const int len, void (*f)(T&))
{
	int i = 0;
	while (i < len)
	{
		f(arr[i]);
		i++;
	}
}

template <class T>
void iter(const T *arr, const int len, void (*f)(const T&))
{
	int i = 0;
	while (i < len)
	{
		f(arr[i]);
		i++;
	}
}

#endif