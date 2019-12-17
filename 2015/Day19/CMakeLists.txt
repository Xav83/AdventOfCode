cmake_minimum_required(VERSION 3.12.4)

add_executable(MedecineForRudolph_Part1 src/part_one.cpp)
set_target_properties(MedecineForRudolph_Part1 PROPERTIES CXX_STANDARD 17)
target_link_libraries(MedecineForRudolph_Part1 PUBLIC stringManipulation)

add_executable(MedecineForRudolph_Part2 src/part_two.cpp)
set_target_properties(MedecineForRudolph_Part2 PROPERTIES CXX_STANDARD 17)
target_link_libraries(MedecineForRudolph_Part2 PUBLIC stringManipulation)

add_test(NAME MedecineForRudolph_part_one_example
         COMMAND $<TARGET_FILE:MedecineForRudolph_Part1>
                 ${CMAKE_CURRENT_LIST_DIR}/res/Part1/example.txt 4)

add_test(NAME MedecineForRudolph_part_one_puzzle_input
         COMMAND $<TARGET_FILE:MedecineForRudolph_Part1>
                 ${CMAKE_CURRENT_LIST_DIR}/res/puzzle_input.txt 535)

add_test(NAME MedecineForRudolph_part_two_example
         COMMAND $<TARGET_FILE:MedecineForRudolph_Part2>
                 ${CMAKE_CURRENT_LIST_DIR}/res/Part2/example.txt 3)

add_test(NAME MedecineForRudolph_part_two_puzzle_input
         COMMAND $<TARGET_FILE:MedecineForRudolph_Part2>
                 ${CMAKE_CURRENT_LIST_DIR}/res/puzzle_input.txt 535)
