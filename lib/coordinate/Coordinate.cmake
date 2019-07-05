cmake_minimum_required(VERSION 3.12.4)

add_library(coordinate ${CMAKE_CURRENT_LIST_DIR}/src/coordinate.cpp)
set_target_properties(coordinate PROPERTIES CXX_STANDARD 17)
target_include_directories(coordinate PUBLIC ${CMAKE_CURRENT_LIST_DIR}/include)
