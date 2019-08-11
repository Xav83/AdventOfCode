cmake_minimum_required(VERSION 3.12.4)

add_executable(Matchsticks src/main.cpp)
set_target_properties(Matchsticks PROPERTIES CXX_STANDARD 17)
target_link_libraries(Matchsticks PUBLIC stringManipulation)

add_test(NAME Matchsticks_part_one_example
    COMMAND $<TARGET_FILE:Matchsticks> ${CMAKE_CURRENT_LIST_DIR}/res/Part1/example.txt 12
)

add_test(NAME Matchsticks_part_one_puzzle_input
    COMMAND $<TARGET_FILE:Matchsticks> ${CMAKE_CURRENT_LIST_DIR}/res/puzzle_input.txt 1333
)
