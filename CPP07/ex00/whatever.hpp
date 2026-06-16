#ifndef WHATEVER_HPP
#define WHATEVER_HPP

template <class T>
void swap(T &T1, T &T2)
{
	T tmp = T1;
	T1 = T2;
	T2 = tmp;
}

template <class T>
T& min(T &T1, T &T2)
{
	return T2 <= T1 ? T2 : T1;
}

template <class T>
T& max(T &T1, T &T2)
{
	return T2 >= T1 ? T2 : T1;
}

#endif