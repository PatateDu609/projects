#ifndef OPERATIONS_CPP
#define OPERATIONS_CPP

#include "matrix.h"

template <class type>
bool Matrix<type>::setCell(type data, unsigned int i, unsigned int j)
{
	if (i < 0 || j < 0 || i > _x || j > _y)
		return (false);
	_matrix[j][i] = data;
	return (true);
}

template <class type>
bool Matrix<type>::setLine(std::initializer_list<type> line, unsigned int i)
{
	if (i < 0 || i > _x)
		return (false);
	
	for (auto it = line.begin(); it != line.end(); it++)
		_matrix[i][line] = 

	return (true);
}

#endif