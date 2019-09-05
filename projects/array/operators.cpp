#ifndef OPERATORS_CPP
#define OPERATORS_CPP

#include "array.h"

template <class type, unsigned int size>
type&	Array<type, size>::operator[](const unsigned int index)
{
	return (at(index));
}

template<class type, unsigned int size>
std::ostream&	operator<<(std::ostream& os, const Array<type, size>& arr)
{
	int i = 0;

	while (i < size - 1)
		std::cout << arr._values[i++] << " ";
	std::cout << arr._values[i];
	return (os);
}

#endif