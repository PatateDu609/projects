#include "file.h"

int main(int ac, char **av)
{
	File f("file.txt");
	std::cout << f.open() << std::endl;
	f.seek(50);
	f.seek(1000);
	f.seek(1, EF);
	std::cout << f.close() << std::endl;
}