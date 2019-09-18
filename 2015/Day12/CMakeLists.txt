cmake_minimum_required(VERSION 3.12.4)

if(NOT EXISTS "${CMAKE_BINARY_DIR}/conan.cmake")
   message(STATUS "Downloading conan.cmake from https://github.com/conan-io/cmake-conan")
   file(DOWNLOAD "https://github.com/conan-io/cmake-conan/raw/v0.14/conan.cmake"
                 "${CMAKE_BINARY_DIR}/conan.cmake")
endif()

include(${CMAKE_BINARY_DIR}/conan.cmake)
conan_cmake_run(REQUIRES jsonformoderncpp/3.7.0@vthiery/stable
                BASIC_SETUP CMAKE_TARGETS
                BUILD missing)

add_executable(JSAbacusFrameworkIo_Part1 src/part_one.cpp)
set_target_properties(JSAbacusFrameworkIo_Part1 PROPERTIES CXX_STANDARD 17)
target_link_libraries(JSAbacusFrameworkIo_Part1 PUBLIC CONAN_PKG::jsonformoderncpp)

add_executable(JSAbacusFrameworkIo_Part2 src/part_two.cpp)
set_target_properties(JSAbacusFrameworkIo_Part2 PROPERTIES CXX_STANDARD 17)
target_link_libraries(JSAbacusFrameworkIo_Part2 PUBLIC CONAN_PKG::jsonformoderncpp)

add_test(NAME JSAbacusFrameworkIo_part_one_puzzle_input
    COMMAND $<TARGET_FILE:JSAbacusFrameworkIo_Part1> ${CMAKE_CURRENT_LIST_DIR}/res/puzzle_input.json 111754
)

add_test(NAME JSAbacusFrameworkIo_part_two_puzzle_input
    COMMAND $<TARGET_FILE:JSAbacusFrameworkIo_Part2> ${CMAKE_CURRENT_LIST_DIR}/res/puzzle_input.json 65402
)
