#include "algorithms.h"
#include <iostream>

template <class T>
void	swap(T *a, T *b)
{
	T temp;
	temp = *a;
	*a = *b;
	*b = temp;
}