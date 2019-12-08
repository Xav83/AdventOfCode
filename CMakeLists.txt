cmake_minimum_required(VERSION 3.12.4)

project(
  AdventOfCode
  VERSION 0.0.4
  LANGUAGES CXX)

find_program(
  CPPCHECK
  NAMES cppcheck cppcheck.exe
  HINTS "C:\\Program Files\\Cppcheck")

if(${CPPCHECK} MATCHES CPPCHECK-NOTFOUND)
  message(FATAL_ERROR "Cppcheck not found")
endif(${CPPCHECK} MATCHES CPPCHECK-NOTFOUND)

add_custom_target(
  cppcheck
  COMMAND ${CPPCHECK} --error-exitcode=1
          --enable=warning,style,performance,portability --std=c++11
          --project=${PROJECT_NAME}.sln
  WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
  COMMENT "Running cppcheck")

find_program(
  CONAN
  NAMES conan.exe
  HINTS "C:\\Program Files\\Conan\\conan")

if(${CONAN}-NOTFOUND)
  message(FATAL_ERROR "Conan not found")
endif(${CONAN}-NOTFOUND)

execute_process(
  COMMAND
    ${CONAN} install ${CMAKE_CURRENT_LIST_DIR} -s arch=x86 -s build_type=Debug
    -s compiler.runtime=MTd --build=missing
  COMMAND
    ${CONAN} install ${CMAKE_CURRENT_LIST_DIR} -s arch=x86 -s build_type=Release
    -s compiler.runtime=MT --build=missing
  WORKING_DIRECTORY ${CMAKE_BINARY_DIR})

include(${CMAKE_BINARY_DIR}/conanbuildinfo_multi.cmake)
conan_basic_setup(TARGETS)

include(${PROJECT_SOURCE_DIR}/lib/coordinate/Coordinate.cmake)
include(${PROJECT_SOURCE_DIR}/lib/stringManipulation/StringManipulation.cmake)

enable_testing()

add_subdirectory(2015/Day1)
add_subdirectory(2015/Day2)
add_subdirectory(2015/Day3)
add_subdirectory(2015/Day4)
add_subdirectory(2015/Day5)
add_subdirectory(2015/Day6)
add_subdirectory(2015/Day7)
add_subdirectory(2015/Day8)
add_subdirectory(2015/Day9)
add_subdirectory(2015/Day10)
add_subdirectory(2015/Day11)
add_subdirectory(2015/Day12)
add_subdirectory(2015/Day13)
add_subdirectory(2015/Day14)
add_subdirectory(2015/Day15)
add_subdirectory(2015/Day16)
add_subdirectory(2015/Day17)
add_subdirectory(2015/Day18)
