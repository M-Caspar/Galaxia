#include <galaxy.h>
#include <iostream>

int main(int argc, char const *argv[])
{
	const double M = 1.98892E30;
	galaxy gal;
	gal.init(9.461E20, 1000, 0, 0, 0, 0);
	std::cout << gal.particles[2].xpos;
	return 0;
}