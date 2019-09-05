#include "algorithms.h"

template <class T>
int		any_of(T * tab, int length, int (*f)(T))
{
	int i = 0;
	
	while (i < length)
		if ((*f)(tab[i++]))
			return (1);
	return (0);
}