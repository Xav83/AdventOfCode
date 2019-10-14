cmake_minimum_required(VERSION 3.12.4)

add_executable(Matchsticks_Part1 src/part_one.cpp)
set_target_properties(Matchsticks_Part1 PROPERTIES CXX_STANDARD 17)
target_link_libraries(Matchsticks_Part1 PUBLIC stringManipulation)

add_executable(Matchsticks_Part2 src/part_two.cpp)
set_target_properties(Matchsticks_Part2 PROPERTIES CXX_STANDARD 17)
target_link_libraries(Matchsticks_Part2 PUBLIC stringManipulation)

add_test(NAME Matchsticks_part_one_example
         COMMAND $<TARGET_FILE:Matchsticks_Part1>
                 ${CMAKE_CURRENT_LIST_DIR}/res/example.txt 12)

add_test(NAME Matchsticks_part_one_puzzle_input
         COMMAND $<TARGET_FILE:Matchsticks_Part1>
                 ${CMAKE_CURRENT_LIST_DIR}/res/puzzle_input.txt 1333)

add_test(NAME Matchsticks_part_two_example
         COMMAND $<TARGET_FILE:Matchsticks_Part2>
                 ${CMAKE_CURRENT_LIST_DIR}/res/example.txt 19)

add_test(NAME Matchsticks_part_two_puzzle_input
         COMMAND $<TARGET_FILE:Matchsticks_Part2>
                 ${CMAKE_CURRENT_LIST_DIR}/res/puzzle_input.txt 2046)
