cmake_minimum_required(VERSION 3.12.4)

add_executable(SomeAssemblyRequired src/main.cpp)
set_target_properties(SomeAssemblyRequired PROPERTIES CXX_STANDARD 17)
target_link_libraries(SomeAssemblyRequired PUBLIC stringManipulation)

add_test(NAME SomeAssemblyRequired_part_one_puzzle_input
         COMMAND $<TARGET_FILE:SomeAssemblyRequired>
                 ${CMAKE_CURRENT_LIST_DIR}/res/Part1/puzzle_input.txt 46065)

add_test(NAME SomeAssemblyRequired_part_two_puzzle_input
         COMMAND $<TARGET_FILE:SomeAssemblyRequired>
                 ${CMAKE_CURRENT_LIST_DIR}/res/Part2/puzzle_input.txt 14134)
