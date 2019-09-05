#include "algorithms.h"
#include "basics.h"
#include <iostream>
#include "remove.cpp"

int main (int ac, char **av)
{
	int tab[] = {6, 6, 6, 65, 6, 5};
	int size = *(&tab + 1) - tab;
	for (int i = 0; i < size; i++)
		std::cout << tab[i] << " ";
	std::cout << std::endl;
	
	int removed;
	int *tab2 = remove(tab, size, 6, &removed);

	for (int i = 0; i < size - removed; i++)
		std::cout << tab2[i] << " ";
	std::cout << std::endl;
	free(tab2);
	return (0);
}