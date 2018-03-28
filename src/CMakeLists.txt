cmake_minimum_required(VERSION 2.8)

set(CMAKE_CXX_STANDARD 11)

find_package(OpenCV 3.0 REQUIRED)

add_library(frks main.cpp cv/FaceMeasurement.h cv/FaceMeasurement.cpp)