cmake_minimum_required(VERSION 3.3)
project(Monocular_SLAM)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

find_package(OpenCV REQUIRED core imgproc highgui)
include_directories(${OpenCV_INCLUDE_DIRS})

set(SOURCE_FILES main.cpp data_manager.cpp data_manager.h)
add_executable(Monocular_SLAM ${SOURCE_FILES})
target_link_libraries(Monocular_SLAM ${OpenCV_LIBS})