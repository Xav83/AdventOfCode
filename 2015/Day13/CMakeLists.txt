cmake_minimum_required(VERSION 3.12.4)

add_executable(KnightsOftheDinnerTable src/main.cpp)
set_target_properties(KnightsOftheDinnerTable PROPERTIES CXX_STANDARD 17)
target_link_libraries(KnightsOftheDinnerTable PUBLIC stringManipulation)

add_test(NAME KnightsOftheDinnerTable_part_one_example
    COMMAND $<TARGET_FILE:KnightsOftheDinnerTable> ${CMAKE_CURRENT_LIST_DIR}/res/Part1/example.txt 330
)

