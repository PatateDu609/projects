#include "matrix.h"

int main(int ac, char **av)
{
	Matrix<int> m;
	Matrix<int> m1(m);
	Matrix<int> m2(3, 3);

	m2.setCell(20, 0, 0);
	m2.setCell(0, 0, 1);
	m2.setCell(2, 0, 2);

	m2.setCell(15, 1, 0);
	m2.setCell(55, 1, 1);
	m2.setCell(5, 1, 2);
	
	m2.setCell(10, 2, 0);
	m2.setCell(5, 2, 1);
	m2.setCell(2, 2, 2);
	std::cout << m2;
}