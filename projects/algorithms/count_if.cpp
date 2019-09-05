#include "algorithms.h"

template <class T>
int		count_if(T *tab, int length, int (*f)(T))
{
	int i = 0, counter = 0;

	while (i < length)
		if ((*f)(tab[i++]))
			counter++;
	return (counter);
}