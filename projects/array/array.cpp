#ifndef ARRAY_CPP
#define ARRAY_CPP

#include "array.h"

template <class type, unsigned int size>
Array<type, size>::Array()
{}

template <class type, unsigned int size>
Array<type, size>::Array(const Array &arr)
{
	int i = -1;
	while (++i < size)
		_values[i] = arr._values[i];
}

template <class type, unsigned int size>
Array<type, size>::Array(type arr[size])
{
	int i = -1;

	while (++i < size)
		_values[i] = arr[i];
}

template <class type, unsigned int size>
Array<type, size>::Array(std::initializer_list<type> arr)
{
	int i = 0;

	for(auto it = arr.begin(); it != arr.end(); i++, it++)
		_values[i] = *it;
}

#endif