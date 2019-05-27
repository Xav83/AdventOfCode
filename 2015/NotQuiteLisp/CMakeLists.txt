cmake_minimum_required(VERSION 3.12.4)

add_executable(NotQuiteLisp src/main)
set_target_properties(NotQuiteLisp PROPERTIES CXX_STANDARD 17)

add_test(NAME advent_of_code_program_input
    COMMAND $<TARGET_FILE:NotQuiteLisp> ${CMAKE_CURRENT_LIST_DIR}/res/puzzle_input.txt 280
)
