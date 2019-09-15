#ifndef MATRIX_CPP
#define MATRIX_CPP

#include "matrix.h"

template <class type>
Matrix<type>::Matrix() : _x(0), _y(0), _matrix(NULL)
{}

template <class type>
Matrix<type>::Matrix(unsigned int x, unsigned int y) : _x(x), _y(y)
{
	_matrix = new type*[_y];

	for(int i = 0; i < _y; i++)
		_matrix[i] = new type[_x];
}

template <class type>
Matrix<type>::Matrix(unsigned int x, unsigned int y, const type value) : Matrix(x, y)
{
	for(int i = 0; i < _y; i++)
		for(int j = 0; j < _x; j++)
			_matrix[i][j] = value;
}

template <class type>
Matrix<type>::Matrix(const Matrix& a) : Matrix(a._x, a._y)
{
	for(int i = 0; i < _y; i++)
		for(int j = 0; j < _x; j++)
			_matrix[i][j] = a._matrix[i][j];
}

template <class type>
Matrix<type>::~Matrix()
{
	for (int i = 0; i < _y; i++)
		delete [] _matrix[i];
	delete [] _matrix;
}

#endif