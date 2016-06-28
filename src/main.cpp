/** 
*@file main.cpp
*@brief The main program containing menus and basic structure. 
*/ 

/** 
* @mainpage Galaxia
* @image html screenshot.png
* @image latex screenshot.png "Simulating a galaxy with Galaxia" width=5cm
* We developed this program to calculate the movement of stars in galaxy collisions. 
* <br>By changing the intial conditions it can be used to tackle about any N-Body problem in classical astrophysics.
* @section pre_sec Prerequisites
* Your system has to have a working installation of gnuplot. If you don't have gnuplot installed yet, go to http://www.gnuplot.info/ and get it, it's free.
* <br> You will also need cmake and make in order to compile the code and Doxygen for compiling the documentation (optional). Additionally, ffmpeg is used for video output.
* @section inst_sec Installation
* This has only been tested on linux machines. While the program should likely also work under MacOS and Windows, please don't get mad at us if it doesn't.
* First, open a terminal, <code>cd</code> to the Galaxia dir and use <code>cmake CMakeList.txt</code> to generate the makefile. Then use <code>make</code> to compile Galaxia.
* <br> Additionaly, <code>doxygen Doxyfile</code> will provide excellent HTML and LaTeX documentation.
* @section ack_sec Acknowledgements
* We use Jeremy Conlin's Gnuplot interface for C++. You can find it at https://code.google.com/archive/p/gnuplot-cpp/.
* 
* @author Maximilian Caspar
* @author Johannes Esser
* @date 2016
* 
* @copyright GNU Public License.
*/

#include "stars.h"
#include "gravity.h"
#include "plot.h"
#include "gnuplot_i.hpp"
#include "fileio.h"

#include <iostream>
#include <vector>

const double time_interval = 6E15; //!< The time interval is made available for user convenience.

int main(int argc, char const *argv[])
{

	intro_art();
	
	std::vector<Star> elements;
	make_galaxy(elements, 4.73E20, 1000, -1E21,-1E21,1E3,1E3,4100000);
	make_galaxy(elements, 6.696E20,1000,5E20,8E20,-1E3, -1E3,4500000);
	std::cout << elements.size() << std::endl;
	gFile g("Collision1");
	g.save(elements);
	
	for(unsigned int i = 1; i<=2000;i++)
	{

		std::cout << i << "\n";
		usleep(2);
		accelerate(elements, time_interval);
		export_plot(elements, 1.5E21);


	}
	make_video(true); 
	
	gFile f("Collision2");
	f.save(elements);

	return 0;
}
