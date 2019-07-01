cmake_minimum_required(VERSION 3.12.4)

add_executable(ProbablyAFireHazard_Part1 src/part_one.cpp)
set_target_properties(ProbablyAFireHazard_Part1 PROPERTIES CXX_STANDARD 17)
target_link_libraries(ProbablyAFireHazard_Part1 PUBLIC stringManipulation coordinate)

add_executable(ProbablyAFireHazard_Part2 src/part_two.cpp)
set_target_properties(ProbablyAFireHazard_Part2 PROPERTIES CXX_STANDARD 17)
target_link_libraries(ProbablyAFireHazard_Part2 PUBLIC stringManipulation coordinate)
target_link_options(ProbablyAFireHazard_Part2 PRIVATE /STACK:10000000)

add_test(NAME ProbablyAFireHazard_part_one_puzzle_input
    COMMAND $<TARGET_FILE:ProbablyAFireHazard_Part1> ${CMAKE_CURRENT_LIST_DIR}/res/puzzle_input.txt 543903
)

add_test(NAME ProbablyAFireHazard_part_two_puzzle_input
    COMMAND $<TARGET_FILE:ProbablyAFireHazard_Part2> ${CMAKE_CURRENT_LIST_DIR}/res/puzzle_input.txt 14687245
)
