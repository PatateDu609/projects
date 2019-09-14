#ifndef MATRIX_H
#define MATRIX_H

template <class type>
class Cell
{
	public:
	Cell(const type data)
	{
		_data = data;
		_next = NULL;
		_previous = NULL;
	}

	Cell(const type data, Cell *next, Cell *previous)
	{
		_data = data;
		_next = next;
		_previous = previous;
	}

	Cell(const type data, Cell *next)
	{
		_data = data;
		_next = next;
		_previous = NULL;
	}

	Cell(const type data, Cell *previous)
	{
		_data = data;
		_next = NULL;
		_previous = previous;
	}

	Cell	*getnext() const
	{
		return (_next);
	}

	Cell	*getprevious() const
	{
		return (_previous);
	}

	type	data() const
	{
		return (data);
	}

	void	setnext(Cell *next = NULL)
	{
		_next = next;
	}

	void	setprevious(Cell *previous = NULL)
	{
		_previous = previous;
	}

	private:
	Cell	*_next;
	Cell	*_previous;
	type	_data;
};

template <class type>
class Matrix
{
public:
	Matrix();
	Matrix(unsigned int x, unsigned int y, const type *value = NULL);
	Matrix(const Matrix& a);

	Matrix& operator=(const Matrix& a);
	Matrix& operator*=(const Matrix& a);
	Matrix& operator*=(int lambda);
	Matrix& operator+=(const Matrix& a);
	Matrix& operator-=(const Matrix& a);

	friend Matrix& operator*(const Matrix& a, const Matrix& b);
	friend Matrix& operator*(const Matrix& a, int lambda);
	friend Matrix& operator+(const Matrix& a, const Matrix& b);
	friend Matrix& operator-(const Matrix& a, const Matrix& b);
	friend std::ostream& operator<<(std::ostream& os, const Matrix& a);

private:

};

#include "access.cpp"
#include "matrix.cpp"
#include "operations.cpp"
#include "operators.cpp"

#endif