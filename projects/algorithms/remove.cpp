#include "algorithms.h"
#include <cstdlib>
#include <iostream>

template <class T>
T	*remove(T *tab, int length, T value, int *removed)
{
	int i = 0;
	int j = 0;
	T	*result;

	while (i < length)
		if (tab[i++] == value)
			j++;
	if (!(result = (T *)malloc(sizeof(T) * j)))
		return (0);
	i = 0;
	*removed = j;
	j = 0;
	while (i < length)
		if (tab[i++] != value)
			result[j++] = tab[i - 1];
	return (result);
}