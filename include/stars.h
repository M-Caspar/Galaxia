/**
*@file stars.h
*@brief Definition of a simple Class representing a unit of mass in the simulation.
*/ 


#pragma once

#include <vector>

/**
*@class Star
*
*A simple class that represents an object of mass with a position, a velecity and a force acting on it.
*
*/

class Star
{
public:
	/**
	*The constructor for Star.
	*@brief Sets the initial position, speed and mass. The initial force acting on a star is always 0.
	*@param sx The initial x position of the star.
	*@param sy The initial y position of the star.
	*@param vx The initial x velocity of the star.
	*@param vy The initial y velocity of the star.
	*@param m The mass of the star.
	*
	*/
	Star(double sx,double sy, double vx, double vy, double m)
	{
		mass = m;
		xpos = sx;
		ypos = sy;
		xvel = vx;
		yvel = vy;
		xfor = 0.0;
		yfor = 0.0;
	};
	/**
	*@brief Moves the star according to its speed, accelerates the star according to its force and resets the force to 0. 
	*@param dt This sets the time interval in which the movement takes place.
	*/
	void move(double dt)
	{
		xpos = xpos + xvel*dt;
		ypos = ypos + yvel*dt;
		xvel = xvel + (xfor / mass)*dt;
		yvel = yvel + (yfor / mass)*dt;
		xfor = 0.0;
		yfor = 0.0;
	}
	double xpos, //!< Current x position
		   ypos; //!< Current y position
	double xvel, //!< Current y velocity
		   yvel; //!< Current y velocity
	double xfor, //!< Current x force
		   yfor; //!< Current y force
	double mass; //!< Mass of star
};
