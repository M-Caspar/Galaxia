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
		xacc = 0.0;
		yacc = 0.0;
	};
	double xpos, ypos;
	double xvel, yvel;
	double xacc, yacc;
	double mass;
};
