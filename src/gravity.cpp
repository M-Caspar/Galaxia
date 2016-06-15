#include "stars.h"
#include <cmath>
#include <random>
#include <chrono>
#include <omp.h>

inline void interact(Star & s1, Star & s2)
{
	const double G = 6.674E-11;
	double xvec = s1.xpos - s2.xpos;
	double yvec = s1.ypos - s2.ypos;
	double r = sqrt(xvec*xvec + yvec*yvec);

	s1.xacc -= G*s1.mass*xvec*pow(r,-3);
	s1.yacc -= G*s1.mass*yvec*pow(r,-3);
	s2.xacc += G*s1.mass*xvec*pow(r,-3);
	s2.yacc += G*s1.mass*yvec*pow(r,-3);
}

inline void make_galaxy(std::vector<Star> & Elements, double radius, unsigned int nos, double sx, double sy, double vx, double vy)
{

	const double M = 1.98892E30;
	const double G = 6.674E-11;
	Elements.reserve(Elements.size() + nos);
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
  		Elements.push_back(temp);
	}
}

inline void accelerate(std::vector<Star> cluster)
{
	unsigned int n = cluster.size();
	#pragma omp parallel for
	for(unsigned int i=0; i<n-1;i++)
	{
		for(unsigned int j=i+1;j<n;j++)
		{
			interact(cluster[i],cluster[j]);
		}
	}
}