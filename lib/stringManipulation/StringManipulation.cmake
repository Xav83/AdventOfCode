cmake_minimum_required(VERSION 3.12.4)

add_library(stringManipulation ${CMAKE_CURRENT_LIST_DIR}/src/string_manipulation.cpp)
set_target_properties(stringManipulation PROPERTIES CXX_STANDARD 17)
target_include_directories(stringManipulation PUBLIC ${CMAKE_CURRENT_LIST_DIR}/include)
