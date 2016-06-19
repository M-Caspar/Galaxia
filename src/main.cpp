/** 
*@file main.cpp
*@brief The main program containing menus and basic structure. 
*/ 

/** 
* @mainpage Galaxia
* 
* We developed this program to calculate the movement of stars in galaxy collisions. 
* <br>By changing the intial conditions it can be used to tackle about any N-Body problem in classical astrophysics.
* @section pre_sec Prerequisites
* Your system has to have a working installation of gnuplot. If you don't have gnuplot installed yet, go to http://www.gnuplot.info/ and get it, it's free.
* <br> You will also need cmake and make in order to compile the code and Doxygen for compiling the documentation (optional).
* @section inst_sec Installation
* This has only been tested on linux machines. While the program should likely also work under MacOS and Windows, please don't get mad at us if it doesn't.
* First, open a terminal, <code>cd</code> to the Galaxia dir and use <code>cmake CMakeList.txt</code> to generate the makefile. Then use <code>make</code> to compile Galaxia.
* <br> Additionaly, <code>doxygen Doxyfile</code> will provide excellent HTML and LaTeX documentation.
* @section ack_sec Acknowledgements
* 
* @author Maximilian Caspar
* @author Johannes Esser
* @date 2016
* @copyright GNU Public License.
*/ 

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
	make_galaxy(elements, 4.73E20, 1100, 0,0,0,0,10000);

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
