#include "stars.h"
#include <iostream>
#include "gravity.cpp"

int main(int argc, char const *argv[])
{
	std::vector<Star> elements;
	make_galaxy(elements, 9.461E20, 10000, 0, 0, 0, 0);
	std::cout << elements[2].xvel << "\n";
	/*int i = 0;
	for(double t = 0; t < 100000; t+= 1000)
	{
		i++;
		std::cout << i << " " << t << "\n";
		accelerate(elements);
		move(elements);
	}*/
	return 0;
}