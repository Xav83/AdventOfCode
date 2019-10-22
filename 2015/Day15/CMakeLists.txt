cmake_minimum_required(VERSION 3.12.4)

add_executable(ScienceForHungryPeople_Part1 src/part_one.cpp)
set_target_properties(ScienceForHungryPeople_Part1 PROPERTIES CXX_STANDARD 17)
target_link_libraries(ScienceForHungryPeople_Part1 PUBLIC stringManipulation)

add_executable(ScienceForHungryPeople_Part2 src/part_two.cpp)
set_target_properties(ScienceForHungryPeople_Part2 PROPERTIES CXX_STANDARD 17)
target_link_libraries(ScienceForHungryPeople_Part2 PUBLIC stringManipulation)

add_test(NAME ScienceForHungryPeople_part_one_example
         COMMAND $<TARGET_FILE:ScienceForHungryPeople_Part1>
                 ${CMAKE_CURRENT_LIST_DIR}/res/example.txt 62842880)

add_test(NAME ScienceForHungryPeople_part_one_puzzle_input
         COMMAND $<TARGET_FILE:ScienceForHungryPeople_Part1>
                 ${CMAKE_CURRENT_LIST_DIR}/res/puzzle_input.txt 13882464)

add_test(NAME ScienceForHungryPeople_part_two_example
         COMMAND $<TARGET_FILE:ScienceForHungryPeople_Part2>
                 ${CMAKE_CURRENT_LIST_DIR}/res/example.txt 57600000)

add_test(NAME ScienceForHungryPeople_part_two_puzzle_input
         COMMAND $<TARGET_FILE:ScienceForHungryPeople_Part2>
                 ${CMAKE_CURRENT_LIST_DIR}/res/puzzle_input.txt 11171160)
