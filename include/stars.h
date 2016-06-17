#pragma once

#include <vector>

class Star
{
public:
	Star(double sx,double sy, double vx, double vy, double m)
	{
		mass = m;
		xpos = sx;
		ypos = sy;
		xvel = vx;
		yvel = vy;
		xfor = 1.0;
		yfor = 1.0;
	};
	double xpos, ypos;
	double xvel, yvel;
	double xfor, yfor;
	double mass;
};
