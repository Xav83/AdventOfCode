cmake_minimum_required(VERSION 3.12.4)

add_executable(NotQuiteLispPart1 src/part_one.cpp)
set_target_properties(NotQuiteLispPart1 PROPERTIES CXX_STANDARD 17)

add_test(NAME advent_of_code_program_input_part_one
    COMMAND $<TARGET_FILE:NotQuiteLispPart1> ${CMAKE_CURRENT_LIST_DIR}/res/puzzle_input.txt 280
)
