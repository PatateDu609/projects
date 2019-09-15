#ifndef OPERATORS_CPP
#define OPERATORS_CPP

#include "matrix.h"

template <class type>
std::ostream& operator<<(std::ostream& os, const Matrix<type>& a)
{
	for (int i = 0; i < a._y; i++)
	{
		for (int j = 0; j < a._x; j++)
			os << a._matrix[i][j] << ((i + 1 != a._y || (i + 1 == a._y && j + 1 != a._x)) ? "\t" : "\0");
		if (i + 1 != a._y) os << "\n\n";
	}

	return (os);
}

#endif