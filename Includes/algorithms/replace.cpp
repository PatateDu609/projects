#include "algorithms.h"

template <class T>
void	replace(T *tab, int length, T old, T new_value)
{
	int i = 0;

	while (i < length)
		if (tab[i++] == old)
			tab[i - 1] = new_value;
}