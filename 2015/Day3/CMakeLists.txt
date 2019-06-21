cmake_minimum_required(VERSION 3.12.4)

add_library(PerfectlySphericalHousesInAVacuum_shared STATIC src/coordinate.cpp)
set_target_properties(PerfectlySphericalHousesInAVacuum_shared PROPERTIES CXX_STANDARD 17)

add_executable(PerfectlySphericalHousesInAVacuum_Part1 src/part_one.cpp)
set_target_properties(PerfectlySphericalHousesInAVacuum_Part1 PROPERTIES CXX_STANDARD 17)
target_link_libraries(PerfectlySphericalHousesInAVacuum_Part1 PerfectlySphericalHousesInAVacuum_shared)

add_executable(PerfectlySphericalHousesInAVacuum_Part2 src/part_two.cpp)
set_target_properties(PerfectlySphericalHousesInAVacuum_Part2 PROPERTIES CXX_STANDARD 17)
target_link_libraries(PerfectlySphericalHousesInAVacuum_Part2 PerfectlySphericalHousesInAVacuum_shared)

add_test(NAME PerfectlySphericalHousesInAVacuum_part_one_example_1
    COMMAND $<TARGET_FILE:PerfectlySphericalHousesInAVacuum_Part1> ${CMAKE_CURRENT_LIST_DIR}/res/Part1/example1.txt 2
)

add_test(NAME PerfectlySphericalHousesInAVacuum_part_one_example_2
    COMMAND $<TARGET_FILE:PerfectlySphericalHousesInAVacuum_Part1> ${CMAKE_CURRENT_LIST_DIR}/res/Part1/example2.txt 4
)

add_test(NAME PerfectlySphericalHousesInAVacuum_part_one_example_3
    COMMAND $<TARGET_FILE:PerfectlySphericalHousesInAVacuum_Part1> ${CMAKE_CURRENT_LIST_DIR}/res/Part1/example3.txt 2
)

add_test(NAME PerfectlySphericalHousesInAVacuum_part_one_puzzle_input
    COMMAND $<TARGET_FILE:PerfectlySphericalHousesInAVacuum_Part1> ${CMAKE_CURRENT_LIST_DIR}/res/puzzle_input.txt 2081
)

add_test(NAME PerfectlySphericalHousesInAVacuum_part_two_example_1
    COMMAND $<TARGET_FILE:PerfectlySphericalHousesInAVacuum_Part2> ${CMAKE_CURRENT_LIST_DIR}/res/Part2/example1.txt 3
)

add_test(NAME PerfectlySphericalHousesInAVacuum_part_two_example_2
    COMMAND $<TARGET_FILE:PerfectlySphericalHousesInAVacuum_Part2> ${CMAKE_CURRENT_LIST_DIR}/res/Part2/example2.txt 3
)

add_test(NAME PerfectlySphericalHousesInAVacuum_part_two_example_3
    COMMAND $<TARGET_FILE:PerfectlySphericalHousesInAVacuum_Part2> ${CMAKE_CURRENT_LIST_DIR}/res/Part2/example3.txt 11
)

add_test(NAME PerfectlySphericalHousesInAVacuum_part_two_puzzle_input
    COMMAND $<TARGET_FILE:PerfectlySphericalHousesInAVacuum_Part2> ${CMAKE_CURRENT_LIST_DIR}/res/puzzle_input.txt 2341
)
