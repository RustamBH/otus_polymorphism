cmake_minimum_required(VERSION 3.5)

project(statistics)

add_executable(statistics
	Statistics.cpp
 	IStatistics.h
  	Max.h
   	Min.h
    Mean.h   	
    StdDev.h
)

set_target_properties(statistics PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED ON
)