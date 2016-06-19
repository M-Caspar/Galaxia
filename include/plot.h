/** @file plot.h*/ 

#pragma once

#include "stars.h"
#include "gnuplot_i.hpp"

#include <iostream>

using std::cout;
using std::endl;

/**
*@brief A simple way of keeping a program open, for example to keep a plot window from closing.
*/

void wait_for_key ()
{
#if defined(WIN32) || defined(_WIN32) || defined(__WIN32__) || defined(__TOS_WIN__)  // every keypress registered, also arrow keys
    cout << endl << "Press any key to continue..." << endl;

    FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE));
    _getch();
#elif defined(unix) || defined(__unix) || defined(__unix__) || defined(__APPLE__)
    cout << endl << "Press ENTER to continue..." << endl;

    std::cin.clear();
    std::cin.ignore(std::cin.rdbuf()->in_avail());
    std::cin.get();
#endif
    return;
}

/**
*@brief Converts the vector of all stars into x,y values needed by the gnuplot interface.
*@param cluster The list of all stars in the simulation, called by reference.
*@param x Output list of all x values, called by reference.
*@param y Output list of all y values, called by reference.
*/

void export_xy(const std::vector<Star> & cluster, std::vector<double> & x, std::vector<double> & y)
{
	unsigned int n = cluster.size();
	for(unsigned int i=0; i<n; i++)
	{
		x[i] = cluster[i].xpos;
		y[i] = cluster[i].ypos;
	}
}

/**
*@brief Initializes the vectors used for calling gnuplot. Needed only once-
*@param x List of all x values, called by reference.
*@param y List of all y values, called by reference.
*/


void init_xy(std::vector<double> & x, std::vector<double> & y, unsigned int n)
{
	x.reserve(n);
	y.reserve(n);
	for (int i = 0; i < n; ++i)
	{
		x.push_back(0);
		y.push_back(0);
	}
}

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