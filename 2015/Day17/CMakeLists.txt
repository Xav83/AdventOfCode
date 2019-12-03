cmake_minimum_required(VERSION 3.12.4)

add_executable(NoSuchThingAsTooMuch_Part1 src/part_one.cpp)
set_target_properties(NoSuchThingAsTooMuch_Part1 PROPERTIES CXX_STANDARD 17)
target_link_libraries(NoSuchThingAsTooMuch_Part1 PUBLIC stringManipulation)

add_executable(NoSuchThingAsTooMuch_Part2 src/part_two.cpp)
set_target_properties(NoSuchThingAsTooMuch_Part2 PROPERTIES CXX_STANDARD 17)
target_link_libraries(NoSuchThingAsTooMuch_Part2 PUBLIC stringManipulation)

add_test(NAME NoSuchThingAsTooMuch_Part1_example
         COMMAND $<TARGET_FILE:NoSuchThingAsTooMuch_Part1>
                 ${CMAKE_CURRENT_LIST_DIR}/res/example.txt 25 4)

add_test(NAME NoSuchThingAsTooMuch_Part1_puzzle_input
         COMMAND $<TARGET_FILE:NoSuchThingAsTooMuch_Part1>
                 ${CMAKE_CURRENT_LIST_DIR}/res/puzzle_input.txt 150 654)

add_test(NAME NoSuchThingAsTooMuch_Part2_example
         COMMAND $<TARGET_FILE:NoSuchThingAsTooMuch_Part2>
                 ${CMAKE_CURRENT_LIST_DIR}/res/example.txt 25 3)
