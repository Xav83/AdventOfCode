cmake_minimum_required(VERSION 3.12.4)

add_library(Reindeer src/Reindeer.cpp)
target_link_libraries(Reindeer PUBLIC stringManipulation)

add_executable(ReindeerOlympics_Part1 src/part_one.cpp)
set_target_properties(ReindeerOlympics_Part1 PROPERTIES CXX_STANDARD 17)
target_link_libraries(ReindeerOlympics_Part1 PUBLIC Reindeer)

add_executable(ReindeerOlympics_Part2 src/part_two.cpp)
set_target_properties(ReindeerOlympics_Part2 PROPERTIES CXX_STANDARD 17)
target_link_libraries(ReindeerOlympics_Part2 PUBLIC Reindeer)

add_test(NAME ReindeerOlympics_part_one
    COMMAND $<TARGET_FILE:ReindeerOlympics_Part1> ${CMAKE_CURRENT_LIST_DIR}/res/puzzle_input.txt 2696
)

add_test(NAME ReindeerOlympics_part_two
    COMMAND $<TARGET_FILE:ReindeerOlympics_Part2> ${CMAKE_CURRENT_LIST_DIR}/res/puzzle_input.txt 1084
)
