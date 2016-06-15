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
	void move(double dt)
	{
		xpos += xvel*dt + 0.5*xacc*dt*dt;
		ypos += yvel*dt + 0.5*yacc*dt*dt;
		xvel += xacc*dt;
		yvel += yacc*dt;
		xacc = 0.;
		yacc = 0.;
	};
	double xpos, ypos;
	double xvel, yvel;
	double xacc, yacc;
	double mass;
};
