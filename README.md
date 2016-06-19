# Galaxia
A simply galatic simulation tool

Instalation
===========
This has only been tested on linux machines. While the program should likely also work under MacOS and Windows, please don't get mad at us if it doesn't. But you will have to change the method of video encoding and Gnuplot has to be globally available.
First, open a terminal, *cd* to the Galaxia dir and use *cmake CMakeList.txt* to generate the makefile. Then use *make* to compile Galaxia.
Additionaly, *doxygen Doxyfile* will provide excellent HTML and LaTeX documentation.

Prerequisites
=============
Your system has to have a working installation of gnuplot. If you don't have Gnuplot installed yet, go to http://www.gnuplot.info/ and get it, it's free.
You will also need cmake and make in order to compile the code and Doxygen for compiling the documentation (optional). Additionally, ffmpeg is required for video output.

Authors
=======
This tool was written during a programing seminar for physicist at the University of Wuppertal by Maximilian Caspar and Johannes Esser.

Acknowledgements
================
We use Jeremy Conlin's Gnuplot interface for C++. You can find it at https://code.google.com/archive/p/gnuplot-cpp/.
