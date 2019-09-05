#include "array.h"
#include <iostream>

int main(int ac, char **av)
{
	Array<int, 5> a({5, 4, 3, 2, 1});
	Array<int, 5> b({11, 22, 33, 44, 55});

	std::cout << "a : " << a << std::endl;
	std::cout << "b : " << b << std::endl << std::endl;
	a.swap(b);
	std::cout << "a : " << a << std::endl;
	std::cout << "b : " << b << std::endl;
}