cmake_minimum_required(VERSION 3.12.4)

add_executable(NotQuiteLispPart1 src/part_one.cpp)
set_target_properties(NotQuiteLispPart1 PROPERTIES CXX_STANDARD 17)

add_executable(NotQuiteLispPart2 src/part_two.cpp)
set_target_properties(NotQuiteLispPart2 PROPERTIES CXX_STANDARD 17)

add_test(NAME advent_of_code_program_input_part_one
    COMMAND $<TARGET_FILE:NotQuiteLispPart1> ${CMAKE_CURRENT_LIST_DIR}/res/puzzle_input.txt 280
)

add_test(NAME advent_of_code_program_input_part_two
    COMMAND $<TARGET_FILE:NotQuiteLispPart2> ${CMAKE_CURRENT_LIST_DIR}/res/puzzle_input.txt 1796
)
