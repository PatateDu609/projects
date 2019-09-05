#ifndef OPERATIONS_CPP
#define OPERATIONS_CPP

#include "array.h"
#include "algorithms.h"
#include "swap.cpp"

template <class type, unsigned int size>
void	Array<type, size>::display(char *separator)
{
	int i = 0;

	while (i < size - 1)
		std::cout << _values[i++] << separator;
	std::cout << _values[i];
}

template <class type, unsigned int size>
void	Array<type, size>::swap(Array &other)
{
	int i = -1;

	while (++i < size)
		::swap(_values + i, other._values + i);
}

template <class type, unsigned int size>
void	Array<type, size>::fill(const type& value)
{
	int i = 0;
	
	while (i < size)
		_values[i++] = value;
}

#endif