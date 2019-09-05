#include "algorithms.h"

template <class T>
void	foreach(T *tab, int length, void (*f)(T))
{
	int i = 0;

	while (i < length)
		(*f)(tab[i++]);
}