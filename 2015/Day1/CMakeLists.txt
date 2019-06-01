cmake_minimum_required(VERSION 3.12.4)

add_executable(NotQuiteLispPart1 src/part_one.cpp)
set_target_properties(NotQuiteLispPart1 PROPERTIES CXX_STANDARD 17)

add_executable(NotQuiteLispPart2 src/part_two.cpp)
set_target_properties(NotQuiteLispPart2 PROPERTIES CXX_STANDARD 17)

add_test(NAME advent_of_code_program_input_part_one_example_1
    COMMAND $<TARGET_FILE:NotQuiteLispPart1> ${CMAKE_CURRENT_LIST_DIR}/res/Part1/example1.txt 0
)

add_test(NAME advent_of_code_program_input_part_one_example_2
    COMMAND $<TARGET_FILE:NotQuiteLispPart1> ${CMAKE_CURRENT_LIST_DIR}/res/Part1/example2.txt 0
)

add_test(NAME advent_of_code_program_input_part_one_example_3
    COMMAND $<TARGET_FILE:NotQuiteLispPart1> ${CMAKE_CURRENT_LIST_DIR}/res/Part1/example3.txt 3
)

add_test(NAME advent_of_code_program_input_part_one_example_4
    COMMAND $<TARGET_FILE:NotQuiteLispPart1> ${CMAKE_CURRENT_LIST_DIR}/res/Part1/example4.txt 3
)

add_test(NAME advent_of_code_program_input_part_one_example_5
    COMMAND $<TARGET_FILE:NotQuiteLispPart1> ${CMAKE_CURRENT_LIST_DIR}/res/Part1/example5.txt 3
)

add_test(NAME advent_of_code_program_input_part_one_example_6
    COMMAND $<TARGET_FILE:NotQuiteLispPart1> ${CMAKE_CURRENT_LIST_DIR}/res/Part1/example6.txt -1
)

add_test(NAME advent_of_code_program_input_part_one_example_7
    COMMAND $<TARGET_FILE:NotQuiteLispPart1> ${CMAKE_CURRENT_LIST_DIR}/res/Part1/example7.txt -1
)

add_test(NAME advent_of_code_program_input_part_one_example_8
    COMMAND $<TARGET_FILE:NotQuiteLispPart1> ${CMAKE_CURRENT_LIST_DIR}/res/Part1/example8.txt -3
)

add_test(NAME advent_of_code_program_input_part_one_example_9
    COMMAND $<TARGET_FILE:NotQuiteLispPart1> ${CMAKE_CURRENT_LIST_DIR}/res/Part1/example9.txt -3
)

add_test(NAME advent_of_code_program_input_part_one
    COMMAND $<TARGET_FILE:NotQuiteLispPart1> ${CMAKE_CURRENT_LIST_DIR}/res/puzzle_input.txt 280
)

add_test(NAME advent_of_code_program_input_part_two_example_1
    COMMAND $<TARGET_FILE:NotQuiteLispPart2> ${CMAKE_CURRENT_LIST_DIR}/res/Part2/example1.txt 1
)

add_test(NAME advent_of_code_program_input_part_two_example_2
    COMMAND $<TARGET_FILE:NotQuiteLispPart2> ${CMAKE_CURRENT_LIST_DIR}/res/Part2/example2.txt 5
)

add_test(NAME advent_of_code_program_input_part_two
    COMMAND $<TARGET_FILE:NotQuiteLispPart2> ${CMAKE_CURRENT_LIST_DIR}/res/puzzle_input.txt 1797
)
