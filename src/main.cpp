#include "stars.h"
#include <iostream>
#include "gravity.cpp"

int main(int argc, char const *argv[])
{
	std::vector<Star> elements;
	make_galaxy(elements, 9.461E20, 1000, 0, 0, 0, 0);
	int i = 0;
	for(double t = 0; t < 864000000; t+= 86400000)
	{
		i++;
		std::cout << i << " " << t << " " << elements[2].xvel << "\n";
		accelerate(elements, 86400000);
	}
	return 0;
}