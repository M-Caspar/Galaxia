/**
*@file fileio.h
*@brief Defines a class handling conversion from stars into files and back. Requires boost.
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

/**
*@class gFile
*
*A class used for input/output capability. It saves and loads .galaxia files containing boost archives.
*
*/
class gFile
{
public:
	/**
	*The constructor for gFile.
	*@brief Sets the file name and determines swether to overwrite already existing files.
	*@param in_name The file name (without file type or location)
	*/
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
	/**
	*@brief Returns the array of stars loaded from the .galaxia file.
	*/
	vector<Star> load()
	{
		ifstream file{name};
 		text_iarchive ia{file};
 		vector<Star> stars;
 		ia >> stars;
 		return stars;
	}
	/**
	*@brief Writes a vector of stars into a .galaxia file.
	*@param out_stars The vector of stars to be saved.
	*/
	void save(vector<Star>& out_stars)
	{
  		std::ofstream file{name};
  		text_oarchive oa{file};
  	
  			oa << out_stars;
  		
	}
private:

	string name; //!< The filename

	/**
	*@brief Checks whether or not a file already exists.
	*/
	inline bool exists_test (const std::string& name)
	{
    	ifstream f(name.c_str());
    	return f.good();
	}

};