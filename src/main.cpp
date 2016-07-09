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
* You will need at least gnuplot, ffmpeg for usage. g++ and cmake are required for compiling. Boost is required for compiling the code 
* and Doxygen is used for documentation. If you are using a Debian based System like Ubuntu, you can install most of these by typing 
* <code>sudo apt-get install gnuplot ffmpeg doxygen g++ cmake</code>. After you have done this, go to http://www.boost.org/users/download/ and get the 
* source for the latest version of boost. In the Galaxia folder, create a folder named boost, then unpack the boost source into it. Open 
* a terminal, <code>cd</code> to boost and type <code>./bootstrap.sh</code>. After this it done it will tell you to execute <code>./b2</code>. While root is building its binaries you can go 
* grab a coffee, it takes quite a while.
* @section inst_sec Compiling
* -# <code>cd</code> into the Galaxia dir.
* -#  Use <code>cmake .</code> to build the makefile.
* -#  Use <code>make</code> for compilation.
* -#  You can now run Galaxia with <code>./bin/Galaxia</code>
* -#  Use <code>doxygen Doxyfile</code>. This will generate documentation in Galaxia/doc .
* @section ack_sec Acknowledgements
* We use Jeremy Conlin's Gnuplot interface for C++. You can find it at https://code.google.com/archive/p/gnuplot-cpp/.
* 
* @author Maximilian Caspar
* @author Johannes Esser
* @date 2016
* 
* @copyright GNU Public License.
*/

#include "scenarios.h"

#include <iomanip>

using std::cout;
using std::endl;
using std::cin;

/**
*@brief Print the program name to the console
*/
void intro_art()
{
	cout << "     _________    __    ___   _  __ ________" << endl
		 << "    / ____/   |  / /   /   | | |/ //  _/   |" << endl
		 << "   / / __/ /| | / /   / /| | |   / / // /| |" << endl
		 << "  / /_/ / ___ |/ /___/ ___ |/   |_/ // ___ |" << endl
		 << "  \\____/_/  |_/_____/_/  |_/_/|_/___/_/  |_|" << endl << endl
		 << "Writen by Maximilian Caspar and Johannes Esser" << endl 
		 << "University of Wuppertal, 2016" << endl << endl;
}

/**
*@brief Print a basic user menu.
*/

void make_menu()
{
	cout << "Hello and welcome to Galaxia. Here are your options:" << endl << endl;
	cout << "  a The Milkyway: Watch our home galaxy in all it\'s beauty." << endl << endl;
	cout << "  b Andromeda: See our neighbour galaxy smash into us." << endl << endl;
	cout << "  c Uniform distribution: Do uniform distributions turn more chaotic over time?" << endl << endl;
	cout << "  x Exit Galaxia" << endl << endl;
}

/**
*@brief Initialize components and handle user choices.
*@param argc The number of arguments.
*@param argv Arguments passed to the program, currently unused.
*/

int main(int argc, char const *argv[])
{
	std::cout << std::fixed << std::setprecision (3);
	intro_art();
	make_menu();
	cout << "Please input your choice: ";
	char choice;


	do
	{
		cin >> choice;
		switch(choice)
		{
			case 'a':
			cout << "Do you want to create a video (this will delete plot files)? (y/n) ";
			cin >> choice;
			if(choice == 'y')
			{
				scenario_milkyway(true);
				}
			else
			{
				scenario_milkyway(false);
			}
			break;

			case 'b':
			cout << "Do you want to create a video (this will delete plot files)? (y/n) ";
			cin >> choice;
			if(choice == 'y')
			{
				scenario_andromeda(true);
			}
			else
			{
				scenario_andromeda(false);
			}
			break;

			case 'c':
			cout << "Do you want to create a video (this will delete plot files)? (y/n) ";
			cin >> choice;
			if(choice == 'y')
			{
				scenario_square(true);
			}
			else
			{
				scenario_square(false);
			}
			break;

			case 'x':
			break;

			default :
			choice = 'u';
			cout << "You picked an invalid option, please choose again: ";
			break;
		}
	} while(choice == 'u');

	cout << "Live long and prosper!" << endl;

	return 0;
}
