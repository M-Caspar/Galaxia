/**
*@file fileio.h
*@brief Definition of a simple Class representing a unit of mass in the simulation.
*/ 

#pragma once

#include "stars.h"

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <boost/archive/text_oarchive.hpp>
#include <boost/archive/text_iarchive.hpp>
#include <boost/serialization/vector.hpp>
using namespace std;
using namespace boost::archive;


class gFile
{
public:
	gFile(string in_name)
	{
		name = "out/" + in_name + ".galaxia";
		try
		{
			if(exists_test(name))
			{
				string inp;
				cout << "File " << name << " already exists, overwrite[y/n]: ";
				cin >> inp;
				if(inp.at(0) == 'n' || inp.at(0) == 'N')
				{
					throw "File output error\n";
				}
			}
			

		}
		catch(string err)
		{
			cout << err;
		}
	}

	vector<Star> load()
	{
		ifstream file{name};
 		text_iarchive ia{file};
 		vector<Star> stars;
 		ia >> stars;
 		return stars;
	}
	void save(vector<Star>& out_stars)
	{
  		std::ofstream file{name};
  		text_oarchive oa{file};
  	
  			oa << out_stars;
  		
	}
private:

	string name;

	inline bool exists_test (const std::string& name)
	{
    	ifstream f(name.c_str());
    	return f.good();
	}

};