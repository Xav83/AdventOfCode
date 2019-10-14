cmake_minimum_required(VERSION 3.12.4)

add_executable(ReindeerOlympics src/main.cpp)
set_target_properties(ReindeerOlympics PROPERTIES CXX_STANDARD 17)
target_link_libraries(ReindeerOlympics PUBLIC stringManipulation)

add_test(NAME ReindeerOlympics_part_one
    COMMAND $<TARGET_FILE:ReindeerOlympics> ${CMAKE_CURRENT_LIST_DIR}/res/puzzle_input.txt 2696
)
