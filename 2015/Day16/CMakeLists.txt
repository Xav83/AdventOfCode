cmake_minimum_required(VERSION 3.12.4)

add_executable(AuntSue src/main.cpp)
set_target_properties(AuntSue PROPERTIES CXX_STANDARD 17)
target_link_libraries(AuntSue PUBLIC stringManipulation)

add_test(NAME AuntSue_part_one_puzzle_input
         COMMAND $<TARGET_FILE:AuntSue>
                 ${CMAKE_CURRENT_LIST_DIR}/res/puzzle_input.txt 40)
