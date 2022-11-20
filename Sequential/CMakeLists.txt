cmake_minimum_required(VERSION 3.23)
project(PORR)

set(CMAKE_CXX_STANDARD 20)

add_executable(PORR main.cpp Graph.cpp)

find_package(OpenMP)
if(OpenMP_CXX_FOUND)
    target_link_libraries(MyTarget PUBLIC OpenMP::OpenMP_CXX)
endif()