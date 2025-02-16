cmake_minimum_required(VERSION 3.10)
project(AR_Ruler)

set(CMAKE_CXX_STANDARD 14)
find_package(OpenCV REQUIRED)

add_executable(ar_ruler main.cpp)
target_link_libraries(ar_ruler ${OpenCV_LIBS})
