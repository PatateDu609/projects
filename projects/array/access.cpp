#ifndef ACCESS_CPP
#define ACCESS_CPP

#include "array.h"

template <class type, unsigned int size>
type&	Array<type, size>::at(const unsigned int index)
{
	if (index >= size || index < 0)
		throw std::invalid_argument("invalid index");
	return (_values[index]);
}

template <class type, unsigned int size>
type	*Array<type, size>::data()
{
	return (_values);
}

template <class type, unsigned int size>
type	Array<type, size>::back()
{
	return (_values[size - 1]);
}

#endif