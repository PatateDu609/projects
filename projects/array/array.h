#ifndef ARRAY_H
#define ARRAY_H

#include <initializer_list>
#include <stdexcept>
#include <iostream>

template <class type, unsigned int size>
class Array
{
public:
				Array();
				Array(const Array &arr);
				Array(type arr[size]);
				Array(std::initializer_list<type> c);

	type&		at(const unsigned int index);
	type		back();
	type		*data();

	template<class T, unsigned int s>
	friend std::ostream&	operator<<(std::ostream& os, const Array<T, s>& arr);
	type&		operator[](const unsigned int index);

	void		display(char *separator);
	void		swap(Array &other);
	void		fill(const type& value);

private:
	type		_values[size];
};

#include "array.cpp"
#include "access.cpp"
#include "operators.cpp"
#include "operations.cpp"

#endif