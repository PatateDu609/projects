#include "algorithms.h"

template <class T>
T*		find(T *tab, int length, T element)
{
	int i = 0;

	while (i < length)
		if (tab[i++] == element)
			return (tab + i - 1);
	return (0);
}