cmake_minimum_required(VERSION 2.8)

set(CMAKE_CXX_STANDARD 11)

add_library(face
        FaceMeasurement.h
        FaceMeasurement.cpp
        FaceMeasurementStream.h
        FaceMeasurementStream.cpp
        VideoCaptureStream.cpp VideoCaptureStream.h)


find_package(OpenCV 3.0 REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})
target_link_libraries(face ${OpenCV_LIBS})