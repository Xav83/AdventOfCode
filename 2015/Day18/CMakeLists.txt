cmake_minimum_required(VERSION 3.12.4)

add_library(LikeAGIFForYourYard_SharedCode src/Light.cpp src/Grid.cpp)
set_target_properties(LikeAGIFForYourYard_SharedCode PROPERTIES CXX_STANDARD 17)

add_executable(LikeAGIFForYourYard_Part1 src/part_one.cpp)
set_target_properties(LikeAGIFForYourYard_Part1 PROPERTIES CXX_STANDARD 17)
target_link_libraries(LikeAGIFForYourYard_Part1
                      PUBLIC stringManipulation LikeAGIFForYourYard_SharedCode)

add_executable(LikeAGIFForYourYard_Part2 src/part_two.cpp)
set_target_properties(LikeAGIFForYourYard_Part2 PROPERTIES CXX_STANDARD 17)
target_link_libraries(LikeAGIFForYourYard_Part2
                      PUBLIC stringManipulation LikeAGIFForYourYard_SharedCode)

add_test(NAME LikeAGIFForYourYard_part_one_puzzle_input
         COMMAND $<TARGET_FILE:LikeAGIFForYourYard_Part1>
                 ${CMAKE_CURRENT_LIST_DIR}/res/puzzle_input.txt 814)

add_test(NAME LikeAGIFForYourYard_part_two_puzzle_input
         COMMAND $<TARGET_FILE:LikeAGIFForYourYard_Part2>
                 ${CMAKE_CURRENT_LIST_DIR}/res/puzzle_input.txt 924)
