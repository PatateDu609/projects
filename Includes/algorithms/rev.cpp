#include "algorithms.h"

template <class T>
void	_rev(T *tab, int start, int end)
{
	if (end < start)
		return ;
	swap<T>(tab + start, tab + end);
	_rev(tab, start + 1, end - 1);
}

template <class T>
void	rev(T *tab, int size)
{
	_rev(tab, 0, size - 1);
}