# Galaxia
_A simply galatic simulation tool_

##Installation
###Compatibility
This program has only been tested on Linux machines. We cannot guarantee flawless execution with Windows, although you should be able to make it work.

###Prerequisites
You will need at least gnuplot, ffmpeg for usage. g++ and cmake are required for compiling. Boost is required for compiling the code and Doxygen is used for documentation. If you are using a Debian based System like Ubuntu, you can install most of these by typing `sudo apt-get install gnuplot ffmpeg doxygen g++ cmake`. After you have done this, go to http://www.boost.org/users/download/ and get the source for the latest version of boost. In the _Galaxia_ folder, create a folder named _boost_, then unpack the boost source into it. Open a terminal, `cd` to boost and type `./bootstrap.sh`. After this it done it will tell you to execute `./b2`. While root is building its binaries you can go grab a coffee, it takes quite a while.

###Compiling the source
1. `cd` into the _Galaxia_ dir.
2. Use `cmake .` to build the makefile.
3. Use `make` for compilation.
4. You can now run Galaxia with `./bin/Galaxia`
5. Use `doxygen Doxyfile`. This will generate documentation in _Galaxia/doc_.

##Authors
This tool was written during a programming seminar for physicist at the University of Wuppertal by _Maximilian Caspar_ and _Johannes Esser_.

##Acknowledgements
We use Jeremy Conlin's Gnuplot interface for C++. You can find it at https://code.google.com/archive/p/gnuplot-cpp/.
