#ifndef MATRIX_H
#define MATRIX_H

#include <initializer_list>
#include <iostream>

template <class type>
class Matrix
{
public:
	Matrix();
	Matrix(unsigned int x, unsigned int y);
	Matrix(unsigned int x, unsigned int y, const type value);
	Matrix(const Matrix& a);
	~Matrix();

	// static Matrix empty
	bool setCell(type data, unsigned int i, unsigned int j);
	bool setLine(std::initializer_list<type> line, unsigned int i);

	Matrix& operator=(const Matrix& a);
	Matrix& operator*=(const Matrix& a);
	Matrix& operator*=(int lambda);
	Matrix& operator+=(const Matrix& a);
	Matrix& operator-=(const Matrix& a);

	// friend Matrix& operator*(const Matrix& a, const Matrix& b);
	// friend Matrix& operator*(const Matrix& a, int lambda);
	// friend Matrix& operator+(const Matrix& a, const Matrix& b);
	// friend Matrix& operator-(const Matrix& a, const Matrix& b);
	template <class T>
	friend std::ostream& operator<<(std::ostream& os, const Matrix<T>& a);

private:
	unsigned int _x;
	unsigned int _y;
	type	**_matrix;
};

#include "access.cpp"
#include "matrix.cpp"
#include "operations.cpp"
#include "operators.cpp"

#endif