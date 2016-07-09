/** 
*@file plot.h
*@brief Most of the conversion and talking to the Gnuplot interface happens in here.
*@todo Add file IO
*/ 

#pragma once

#include "stars.h"
#include "gnuplot_i.hpp"

#include <stdio.h>
#include <iostream>
#include <string>
#include <ctime>
#include <assert.h>

using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::cin;

unsigned int nop = 0; //!< The global file counter.

/**
*@brief Calculate the number of digits of an unsigned int based on its log10.
*@param i Input number
*@return Number of digits
*/

unsigned int number_of_digits (unsigned int i)
{
    return i > 0 ? (int) log10 ((double) i) + 1 : 1;
}

string filename(unsigned int n)
{
	string name = "out/p";

	for(unsigned int i = 1; i<= 5; i++)
	{
		if(i <= 5 - number_of_digits(n))
		{
			name += "0";
		}
		else
		{
			break;
		}
	}
	name += std::to_string(n);
	return name;
}

/**
*@brief Turn all of the plot files in /out into a video file.
*@param delete_plotfiles Specify wether to delete the plots or to keep them
* This function removes temporary files and calls ffmpeg to turn all available plot files into an .mp4 file.
* By passing delete_plotfiles to TRUE all .png files are removed in the process.
*/

void make_video(bool delete_plotfiles)
{
	try
	{
		cout << endl;
		Gnuplot g1;
		sleep(3);
		g1.remove_tmpfiles();
		cout << "Deleted temporary files" << endl;
		if (system("ffmpeg -hide_banner -loglevel panic -i out/p%05d.png out/movie.mp4 -vcodec mpeg4 -vb 128k -r 18") == 0)
		{
			cout << "Successfully created video, you can find it at out/movie.mp4" << endl;
			if(delete_plotfiles)
			{
				for(unsigned int i=1; i<=nop;i++)
				{
					string name = filename(i) + ".png";
					if(remove(name.c_str()) != 0)
					{
						throw ("Unspecified file deletion error");
					}
				}
				cout << "Deleted plot files" << endl;
				nop = 0;
			}
		}
		else
		{
			throw ("Failed to create output video output");
		}
	}
	catch(string er)
	{
		cout << er << endl;
	}

}

/**
*@brief A simple way of keeping a program open, for example to keep a plot window from closing.
*A simple, system independent way of delaying a program until the user inputs a key. Taken from the example program that comes with the Gnuplot interface.
*@author Jeremy Conlin 
*/


void wait_for_key ()
{
#if defined(WIN32) || defined(_WIN32) || defined(__WIN32__) || defined(__TOS_WIN__)  // every keypress registered, also arrow keys
    cout << endl << "Press any key to continue..." << endl;

    FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE));
    _getch();
#elif defined(unix) || defined(__unix) || defined(__unix__) || defined(__APPLE__)
    cout << endl << "Press ENTER to continue..." << endl;

    cin.clear();
    cin.ignore(cin.rdbuf()->in_avail());
    cin.get();
#endif
    return;
}

/**
*@brief Converts the vector of all stars into x,y values needed by the Gnuplot interface.
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
*@brief Initializes the vectors used for calling Gnuplot. Needed only once.
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
*@brief A makro for exporting an image of the current stars. Assumes (0,0) to be the middle of the plot.
*@param cluster The vector containing all stars.
*@param scale Determines the scale of the plot.
*@todo Make saving files more efficient, ditch the timer.
*/

void export_plot(const std::vector<Star> & cluster, const double scale)
{
	vector<double> x,y;
	init_xy(x,y, cluster.size());
	export_xy(cluster,x,y);

	nop++;

	string name = filename(nop);
	cout << "File saved: " << name.c_str() << "  ";


    Gnuplot g1("points");
    g1.savetopng(name.c_str());
    g1.set_style("points").set_samples(300).set_xrange(- scale, scale).set_yrange(- scale, scale).plot_xy(x,y);
    g1.reset_all();
    if(nop%1000 == 0)
    {
    	sleep(5);
    	g1.remove_tmpfiles();
    	g1.cmd("exit");
    }
}

