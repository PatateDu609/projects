#include "list.h"

int main(int ac, char **av)
{
	List<int> a({1, 54, 2, 1, 2});
	
	auto data = a.data();
	for(int i = 0; i < a.getsize(); i++)
		std::cout << data[i] << std::endl;
	a.push_back(26684);
	std::cout << std::endl;
	delete [] data;

	data = a.data();
	for(int i = 0; i < a.getsize(); i++)
		std::cout << data[i] << std::endl;
	delete [] data;
	std::cout << std::endl;
	
	a.pop_front();
	data = a.data();
	for(int i = 0; i < a.getsize(); i++)
		std::cout << data[i] << std::endl;
	delete [] data;
}