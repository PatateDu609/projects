#include "file.h"

int main(int ac, char **av)
{
	File f("test.txt");
	std::cout << f.open() << std::endl;
	std::cout << f.close() << std::endl;
}