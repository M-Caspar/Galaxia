/** 
*@file scenarios.h
*@brief Provides some pre-made scenarios to play around with
*/ 

#pragma once

#include "stars.h"
#include "plot.h"
#include "gravity.h"
#include "fileio.h"

using std::cout;
using std::endl;
using std::vector;

/**
*@brief A simple collision that will occur in a few billion years. The collision as depicted in Galaxia is probalbly not massive enough because it lacks stars, but it looks rather nice.
*@param video Decide wether to convert the output plots into a video
*/

void scenario_andromeda(bool video)
{
	cout << std::endl;
	vector<Star> elements;
	gFile g("examples/scenarios/Collision1.galaxia", false);
	elements = g.load();
	const double time_interval = 1E15;

	for(unsigned int i = 1; i<=1000;i++)
	{
		double ctime1 = omp_get_wtime();
		cout << "Simulation step "  << i << "\t";
		usleep(4);
		accelerate(elements, time_interval);
		export_plot(elements, 1.5E21);
		double ctime2 = omp_get_wtime();
		cout << "Time: " << ctime2 - ctime1 << " s" << endl;

	}
	
	if(video)
	{
		make_video(true);
	}
	else
	{
		Gnuplot g1;
		sleep(3);
		g1.remove_tmpfiles();
		cout << "Deleted temporary files" << endl;
	}

}

/**
*@brief A rather nice overview over our home galaxy.
*@param video Decide wether to convert the output plots into a video
*/

void scenario_milkyway(bool video)
{
	cout << endl;
	vector<Star> elements;
	gFile g("examples/scenarios/Milkyway.galaxia", false);
	elements = g.load();
	const double time_interval = 6E13;

	for(unsigned int i = 1; i<=1000;i++)
	{
		double ctime1 = omp_get_wtime();
		cout << "Simulation step " << i << "\t";
		usleep(4);
		accelerate(elements, time_interval);
		export_plot(elements, 7.5E20);
		double ctime2 = omp_get_wtime();
		cout << "Time: " << ctime2 - ctime1 << " s" << endl;

	}

	if(video)
	{
		make_video(true);
	}
	else
	{
		Gnuplot g1;
		sleep(3);
		g1.remove_tmpfiles();
		cout << "Deleted temporary files" << endl;
	}
	
}

/**
*@brief A rather boring uniform distribution.
*@param video Decide wether to convert the output plots into a video
*/

void scenario_square(bool video)
{
	cout << endl;
	vector<Star> elements;
	gFile g("examples/scenarios/Square.galaxia", false);
	elements = g.load();
	const double time_interval = 1.2E13;

	for(unsigned int i = 1; i<=1000;i++)
	{
		double ctime1 = omp_get_wtime();
		cout << "Simulation step " << i << "\t";
		usleep(4);
		accelerate(elements, time_interval);
		export_plot(elements, 9.5E20);
		double ctime2 = omp_get_wtime();
		cout << "Time: " << ctime2 - ctime1 << " s" << endl;

	}

	if(video)
	{
		make_video(true);
	}
	else
	{
		Gnuplot g1;
		sleep(3);
		g1.remove_tmpfiles();
		cout << "Deleted temporary files" << endl;
	}
}