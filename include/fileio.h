#include "stars.h"

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;



class gFile
{
public:
	gFile(std::string in_name)
	{
		name = "out/" + in_name + ".galaxia";
	}

	void write_star(Star out_star)
	{
		ofstream myfile;
		myfile.open(name);
		myfile << out_star.mass << ";" << out_star.xpos << ";" << out_star.ypos << ";"
		<< out_star.xvel << ";" << out_star.yvel << "\n";
		myfile.close();
	}
	void write_stars(std::vector<Star> out_stars)
	{
		ofstream myfile;
		myfile.open(name);
		for(unsigned int i=0; i < out_stars.size(); i++)
		{
			myfile << out_stars[i].mass << ";" << out_stars[i].xpos << ";" << out_stars[i].ypos << ";"
			<< out_stars[i].xvel << ";" << out_stars[i].yvel << "\n";		
		}
		myfile.close();
	}	
private:

	std::string name;
};