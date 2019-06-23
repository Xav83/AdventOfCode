cmake_minimum_required(VERSION 3.12.4)

add_executable(DoesntHeHaveInternElvesForThis_Part1 src/part_one.cpp)
set_target_properties(DoesntHeHaveInternElvesForThis_Part1 PROPERTIES CXX_STANDARD 17)
target_link_libraries(DoesntHeHaveInternElvesForThis_Part1 PUBLIC stringManipulation)

add_test(NAME DoesntHeHaveInternElvesForThis_Part1_part_one_example_1
    COMMAND $<TARGET_FILE:DoesntHeHaveInternElvesForThis_Part1> ${CMAKE_CURRENT_LIST_DIR}/res/Part1/example1.txt 1
)

add_test(NAME DoesntHeHaveInternElvesForThis_Part1_part_one_example_2
    COMMAND $<TARGET_FILE:DoesntHeHaveInternElvesForThis_Part1> ${CMAKE_CURRENT_LIST_DIR}/res/Part1/example2.txt 1
)

add_test(NAME DoesntHeHaveInternElvesForThis_Part1_part_one_example_3
    COMMAND $<TARGET_FILE:DoesntHeHaveInternElvesForThis_Part1> ${CMAKE_CURRENT_LIST_DIR}/res/Part1/example3.txt 0
)

add_test(NAME DoesntHeHaveInternElvesForThis_Part1_part_one_example_4
    COMMAND $<TARGET_FILE:DoesntHeHaveInternElvesForThis_Part1> ${CMAKE_CURRENT_LIST_DIR}/res/Part1/example4.txt 0
)

add_test(NAME DoesntHeHaveInternElvesForThis_Part1_part_one_example_5
    COMMAND $<TARGET_FILE:DoesntHeHaveInternElvesForThis_Part1> ${CMAKE_CURRENT_LIST_DIR}/res/Part1/example5.txt 0
)

add_test(NAME DoesntHeHaveInternElvesForThis_Part1_part_one_puzzle_input
    COMMAND $<TARGET_FILE:DoesntHeHaveInternElvesForThis_Part1> ${CMAKE_CURRENT_LIST_DIR}/res/puzzle_input.txt 255
)
