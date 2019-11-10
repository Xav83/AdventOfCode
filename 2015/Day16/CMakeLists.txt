cmake_minimum_required(VERSION 3.12.4)

add_library(AuntSue_SharedCode src/Aunt.cpp)
set_target_properties(AuntSue_SharedCode PROPERTIES CXX_STANDARD 17)

add_executable(AuntSue_Part1 src/part_one.cpp)
set_target_properties(AuntSue_Part1 PROPERTIES CXX_STANDARD 17)
target_link_libraries(AuntSue_Part1 PUBLIC stringManipulation
                                           AuntSue_SharedCode)

add_executable(AuntSue_Part2 src/part_two.cpp)
set_target_properties(AuntSue_Part2 PROPERTIES CXX_STANDARD 17)
target_link_libraries(AuntSue_Part2 PUBLIC stringManipulation
                                           AuntSue_SharedCode)

add_test(NAME AuntSue_part_one_puzzle_input
         COMMAND $<TARGET_FILE:AuntSue_Part1>
                 ${CMAKE_CURRENT_LIST_DIR}/res/puzzle_input.txt 40)

add_test(NAME AuntSue_part_two_puzzle_input
         COMMAND $<TARGET_FILE:AuntSue_Part2>
                 ${CMAKE_CURRENT_LIST_DIR}/res/puzzle_input.txt 241)
