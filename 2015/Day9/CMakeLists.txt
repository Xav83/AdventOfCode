cmake_minimum_required(VERSION 3.12.4)

add_executable(AllInASingleNight src/part_one.cpp)
set_target_properties(AllInASingleNight PROPERTIES CXX_STANDARD 17)
target_link_libraries(AllInASingleNight PUBLIC stringManipulation)

add_test(NAME AllInASingleNight_part_one_example
    COMMAND $<TARGET_FILE:AllInASingleNight> ${CMAKE_CURRENT_LIST_DIR}/res/Part1/example.txt 605
)

add_test(NAME AllInASingleNight_part_one_puzzle_input
    COMMAND $<TARGET_FILE:AllInASingleNight> ${CMAKE_CURRENT_LIST_DIR}/res/puzzle_input.txt 141
)
