/** 
*@file gravity.h
*@brief Provides the functions needed for particles to be generated and interact.
*/ 

#pragma once
#include "stars.h"
#include <cmath>
#include <random>
#include <chrono>
#include <omp.h>
#include <iostream>

const double G  = 6.674E-11; //!< The gravitational constant
const double MASS_OF_SUN = 1.98892E30; //!< The mass of our sun serves as a template when creating galaxies.
const double LIGTHYEAR = 9.46073E15; //!< The lightyear is needed for calculating orbital speed distribution.

/**
 * @BRIEF Return the Angle of a 2D-Vector given by (x,y)
 * 
 * The standart C++ function 'atan2()' returns an angle for two given coordinates, but 
 * we need the angle to be between \f$ 0 \f$ and \f$ 2 \Pi \f$.
 *
 */

double get_angle(const double & x, const double & y)
{
	double at = atan2(y,x);
	if(at >=0.)
	{
		return at;
	}
	else
	{
		return 6.28318530718 + at; 
	}
}

/**
 * @BRIEF Return the orbit velocity of a star based on the distance to the galaxy center.
 * @param radius The distance from galaxy center in meters
 * The orbital velocity can be approximated as a funtion dependend only on the distance to the
 * galaxy center according to http://spacemath.gsfc.nasa.gov/Calculus/6Page106.pdf . The output had to be scaled for usable results.
 */

double orbit_velocity(const double & radius)
{
	double x = radius/( LIGTHYEAR*10000); //!< Normalize radius to 10000 lightyears.
	return 1100*x/pow(1+x*x,0.75);

}

/**
 * @BRIEF Return the orbit velocity of a star based on the distance to the galaxy center and the mass ratio for the galactic center.
 * @param radius The distance from galaxy center in meters
 * The orbital velocity can be approximated by assuming a homogeneous mass distribution. However, in discrete simulations it's more sensible 
 * to work with the direct approach \f$ v_o = \sqrt{\frac{G \cdot M}{r}}\f$
 */

double orbit_velocity(const double & radius, const unsigned int & mco)
{
	return sqrt(G*MASS_OF_SUN*mco / radius);
}


/**
 * @BRIEF Initialize a galaxy distribution and write it in an array.
 * @param Elements The vector of stars the galaxy is going to be written into, called by reference.
 * @param radius The mean radius of the galaxy.
 * @param nos The number of stars that is going to be generated.
 * @param sx The x position of the galaxy.
 * @param sy The y position of the galaxy.
 * @param vx The x velocity of the galaxy.
 * @param vy The y velocity of the galaxy.
 * @param mco The mass ratio from star to galactic center.
 *
 * The galaxies are generated as random distributions of stars around a specific point in space.
 * The orbital speed of the stars is set by an external function. A supermassive galactic center is set.
 */

void make_galaxy(std::vector<Star> & Elements, const double & radius, const unsigned int & nos, const double & sx, const double & sy, const double & vx, const double & vy, const unsigned int & mco)
{

	//Elements.reserve(Elements.size() + nos);
	unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
	std::default_random_engine generator (seed);
  	std::normal_distribution<double> distribution(0.0, radius/2);

  	for (unsigned int i = 0; i < nos; i++)
  	{
  		double x = 0;
  		double y = 0;
  		double rad = 0;
  		while(rad < 0.05*radius)
  		{
  			x = distribution(generator);
  			y = distribution(generator);
  			rad = sqrt(x*x + y*y);
  		}
  		double alpha = get_angle(x , y);
  		double v = orbit_velocity(rad, mco);
  		Star temp(x + sx ,y + sy,v*sin(alpha) + vx,-v*cos(alpha) + vy,MASS_OF_SUN);
  		Elements.push_back(temp);
	}
	Star center(sx, sy, vx, vy, MASS_OF_SUN*mco);
	Elements.push_back(center);
}

/**
*@brief Calculates the forces between all stars and moves them for a given timestep.
*@param cluster The vector containing all stars, called by reference
*@param dt Time intervall used for calculating the movement.
*
* Calculation of force and movement are parallelised in order to spped up the calculation for large amounts of stars.
* The movement of the star is calculated from within the Star class.
*/

void accelerate(std::vector<Star> & cluster, double dt)
{
	unsigned int n = cluster.size();

	#pragma omp parallel for
	for(unsigned int i=0; i<n-1;i++)
	{

		for(unsigned int j=i+1;j<n;j++)
		{
			double xvec = cluster[i].xpos - cluster[j].xpos;
			double yvec = cluster[i].ypos - cluster[j].ypos;
			double r = sqrt(xvec*xvec + yvec*yvec);
			double con = G*cluster[i].mass*cluster[j].mass;
			cluster[i].xfor -= con*xvec*pow(r,-3);
			cluster[i].yfor -= con*yvec*pow(r,-3);
			cluster[j].xfor += con*xvec*pow(r,-3);
			cluster[j].yfor += con*yvec*pow(r,-3);
		}
	}
	#pragma omp parallel for
	for(unsigned int i = 0; i < n ;i++)
	{
		cluster[i].move(dt);
	}
}

