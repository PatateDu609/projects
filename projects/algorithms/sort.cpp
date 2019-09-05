#include "algorithms.h"

template <class T>
int		partition(T *tab, int start, int end, int (*cmp)(T, T))
{
	T	pivot = tab[end];
	int i = start - 1;

	for (int j = start; j <= end - 1; j++)
	{
		if ((*cmp)(tab[j], pivot))
		{
			i++;
			swap<T>(tab + i, tab + j);
		}
	}
	swap<T>(tab + i + 1, tab + end);
	return (i + 1);
}

template <class T>
void	quicksort(T *tab, int start, int end, int (*cmp)(T, T))
{
	if (start < end)
	{
		int pivot = partition(tab, start, end, cmp);
		quicksort(tab, start, pivot - 1, cmp);
		quicksort(tab, pivot + 1, end, cmp);
	}
}

template <class T>
void	sort(T *tab, int l, int (*cmp)(T, T))
{
	quicksort<T>(tab, 0, l - 1, cmp);
}