#include "stars.h"
#include <iostream>
#include "gravity.h"

#define _G 6.674E-11;
#define _MASS_OF_SUN 1.98892E30;
#define _LIGTHYEAR 9.46073E15;

int main(int argc, char const *argv[])
{
	std::vector<Star> elements;
	make_galaxy(elements, 9.461E20, 5000, 0, 0, 0, 0);
	for(int t = 1; t < 100; t++)
	{
		std::cout << t << " "  << elements[2].xpos << " " << elements[2].xvel<<"\n";
		accelerate(elements, 8E15);

	}
	return 0;
}