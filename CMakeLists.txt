cmake_minimum_required(VERSION 2.8)
project(Galaxia)

set(CMAKE_CXX_FLAGS "-O4 -std=c++0x -fopenmp" )
set(CMAKE_VERBOSE_MAKEFILE "ON")

include_directories(include)
include_directories(boost)
link_directories(boost/stage/lib)


file(GLOB headers RELATIVE ${CMAKE_CURRENT_SOURCE_DIR}
     include/*.h)
file(GLOB test_src RELATIVE ${CMAKE_CURRENT_SOURCE_DIR}
	src/*.cpp)

add_executable(bin/Galaxia ${test_src})
target_link_libraries(bin/Galaxia boost_serialization)