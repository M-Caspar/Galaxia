#include <vector>
#include <random>
#include <chrono>
#include <assert.h>
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
		xfor = 0.0;
		yfor = 0.0;
	};
	void move(double dt)
	{
		xpos += xvel*dt + 0.5*(xfor/mass)*dt*dt;
		ypos += yvel*dt + 0.5*(yfor/mass)*dt*dt;
		xvel += (xfor/mass);
		yvel += (yfor/mass);
		xfor = 0.;
		yfor = 0.;
	};
	double xpos, ypos;
	double xvel, yvel;
	double xfor, yfor;
	double mass;
};

class galaxy
{
public:

	void init(double radius, unsigned int nos, double sx, double sy, double vx, double vy)
	{
		const double M = 1.98892E30;
		const double G = 6.674E-11;
		particles.reserve(nos);
		double v_0 = sqrt(G*M);
		unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
		std::default_random_engine generator (seed);
  		std::normal_distribution<double> distribution(0.0, radius);
  		for (int i = 0; i < nos; i++)
  		{
  			double x = distribution(generator);
  			double y = distribution(generator);
  			double alpha = atan2(y , x);
  			double tv = v_0/pow(x*x + y*y,0.25);
  			Star temp(x + sx ,y + sy,tv*sin(alpha) + vx,tv*cos(alpha) + vy,M);
  			particles.push_back(temp);
		}
	};
	std::vector<Star> particles;
};