/** @file main.cpp*/ 


#include "stars.h"
#include "gravity.h"
#include "plot.h"
#include "gnuplot_i.hpp"

#include <iostream>
#include <vector>


int main(int argc, char const *argv[])
{

		intro_art();
	std::vector<Star> elements;
	make_galaxy(elements, 4.73E20, 1100, 0,0,0,0);

	std::vector<double> xrats;
	std::vector<double> yrats;
	init_xy(xrats,yrats, elements.size());

		Gnuplot g1("Galaxia");
		g1.set_grid();
		g1.set_xrange(-2*4.73E20,2*4.73E20);
		g1.set_yrange(-2*4.73E20,2*4.73E20);
	for(unsigned int i = 1; i<=1015;i++)
	{


		export_xy(elements, xrats, yrats);
		g1.reset_plot();
		g1.set_style("points").plot_xy(xrats,yrats,"Galaxia");
		accelerate(elements, 8E15);
		std::cout << i << "\t" << elements[1].xfor << std::endl;

	}

	g1.remove_tmpfiles();
		wait_for_key();


	return 0;
}
