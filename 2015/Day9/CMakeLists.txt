cmake_minimum_required(VERSION 3.12.4)

add_library(AllInASingleNight_SharedCode src/types.cpp src/input_parser.cpp)
set_target_properties(AllInASingleNight_SharedCode PROPERTIES CXX_STANDARD 17)

add_executable(AllInASingleNight_Part1 src/part_one.cpp)
set_target_properties(AllInASingleNight_Part1 PROPERTIES CXX_STANDARD 17)
target_link_libraries(AllInASingleNight_Part1
                      PUBLIC stringManipulation AllInASingleNight_SharedCode)

add_executable(AllInASingleNight_Part2 src/part_two.cpp)
set_target_properties(AllInASingleNight_Part2 PROPERTIES CXX_STANDARD 17)
target_link_libraries(AllInASingleNight_Part2
                      PUBLIC stringManipulation AllInASingleNight_SharedCode)

add_test(NAME AllInASingleNight_part_one_example
         COMMAND $<TARGET_FILE:AllInASingleNight_Part1>
                 ${CMAKE_CURRENT_LIST_DIR}/res/example.txt 605)

add_test(NAME AllInASingleNight_part_one_puzzle_input
         COMMAND $<TARGET_FILE:AllInASingleNight_Part1>
                 ${CMAKE_CURRENT_LIST_DIR}/res/puzzle_input.txt 141)

add_test(NAME AllInASingleNight_part_two_example
         COMMAND $<TARGET_FILE:AllInASingleNight_Part2>
                 ${CMAKE_CURRENT_LIST_DIR}/res/example.txt 982)

add_test(NAME AllInASingleNight_part_two_input
         COMMAND $<TARGET_FILE:AllInASingleNight_Part2>
                 ${CMAKE_CURRENT_LIST_DIR}/res/puzzle_input.txt 736)
