cmake_minimum_required(VERSION 3.12.4)

project(AdventOfCode VERSION 0.0.4 LANGUAGES CXX)

find_program(CPPCHECK NAMES cppcheck cppcheck.exe HINTS "C:\\Program Files\\Cppcheck")

if(${CPPCHECK} MATCHES CPPCHECK-NOTFOUND)
    message(FATAL_ERROR "Cppcheck not found")
endif(${CPPCHECK} MATCHES CPPCHECK-NOTFOUND)

add_custom_target(
        cppcheck ALL
        COMMAND ${CPPCHECK}
        --error-exitcode=1
        --enable=warning,style,performance,portability
        --std=c++11
        --force
        --project=${PROJECT_NAME}.sln
        WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
        COMMENT "Running cppcheck"
)

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
