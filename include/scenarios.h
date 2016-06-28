/** 
*@file scenarios.h
*@brief Provides some pre-made scenarios to play around with
*/ 

#pragma once

#include "stars.h"
#include "plot.h"
#include "gravity.h"
#include "fileio.h"

void scenario_andromeda(bool video)
{
	std::vector<Star> elements;
	gFile g("examples/scenarios/Collision1.galaxia", false);
	elements = g.load();
	const double time_interval = 6E15; //!< The time interval is made available for user convenience.

	for(unsigned int i = 1; i<=1000;i++)
	{

		std::cout << i << "\n";
		usleep(2);
		accelerate(elements, time_interval);
		export_plot(elements, 1.5E21);


	}
	if(video){make_video(true);}; 
}