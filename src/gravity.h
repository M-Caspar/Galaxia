#pragma once
#include "stars.h"
#include <cmath>
#include <random>
#include <chrono>
#include <omp.h>
#include <iostream>

double orbit_velocity(const double & radius)
{
	const double lightyear = 9.46073E15;
	long x = radius/(lightyear*10000);
	return 350000*x/pow(1+x*x,0.75);
}


void make_galaxy(std::vector<Star> & Elements, double radius, unsigned int nos, double sx, double sy, double vx, double vy)
{

	const double M = 1.98892E30;
	Elements.reserve(Elements.size() + nos);
	unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
	std::default_random_engine generator (seed);
  	std::normal_distribution<double> distribution(0.0, radius);

  	for (unsigned int i = 0; i < nos; i++)
  	{
  		double x = distribution(generator);
  		double y = distribution(generator);
  		double alpha = atan2(y , x);
  		double rad = sqrt(x*x + y*y);
  		double v = orbit_velocity(rad);
  		Star temp(x + sx ,y + sy,v*sin(alpha) + vx,v*cos(alpha) + vy,M);
  		Elements.push_back(temp);
	}
	Star center(sx, sy, vx, vy, M*4310000);
	Elements.push_back(center);
}

void accelerate(std::vector<Star> & cluster, double dt)
{
	unsigned int n = cluster.size();
	const double G = 6.674E-11;
	for(unsigned int i=0; i<n-1;i++)
	{
		for(unsigned int j=i+1;j<n;j++)
		{
			double xvec = cluster[i].xpos - cluster[j].xpos;
			double yvec = cluster[i].ypos - cluster[j].ypos;
			double r = sqrt(xvec*xvec + yvec*yvec);
			double con = G*cluster[i].mass*cluster[j].mass;
			cluster[i].xfor += con*xvec*pow(r,-3);
			cluster[i].yfor += con*yvec*pow(r,-3);
			cluster[j].xfor -= con*xvec*pow(r,-3);
			cluster[j].yfor -= con*yvec*pow(r,-3);
		}
	}
	for(unsigned int i = 0; i < n ;i++)
	{

		cluster[i].xvel = cluster[i].xvel + (cluster[i].xfor / cluster[i].mass)*dt;
		cluster[i].yvel = cluster[i].yvel + (cluster[i].yfor / cluster[i].mass)*dt;
		cluster[i].xpos = cluster[i].xpos + cluster[i].xvel*dt;
		cluster[i].ypos = cluster[i].ypos + cluster[i].yvel*dt;
		cluster[i].xfor = 0.;
		cluster[i].yfor = 0.;
	}
}
