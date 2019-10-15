cmake_minimum_required(VERSION 3.12.4)

add_library(dimension src/dimension.cpp)
set_target_properties(dimension PROPERTIES CXX_STANDARD 17)
target_link_libraries(dimension PUBLIC stringManipulation)

add_executable(IWasToldThereWouldBeNoMath_Part1 src/part_one.cpp)
set_target_properties(IWasToldThereWouldBeNoMath_Part1
                      PROPERTIES CXX_STANDARD 17)
target_link_libraries(IWasToldThereWouldBeNoMath_Part1
                      PUBLIC dimension stringManipulation)

add_executable(IWasToldThereWouldBeNoMath_Part2 src/part_two.cpp)
set_target_properties(IWasToldThereWouldBeNoMath_Part2
                      PROPERTIES CXX_STANDARD 17)
target_link_libraries(IWasToldThereWouldBeNoMath_Part2
                      PUBLIC dimension stringManipulation)

add_test(NAME IWasToldThereWouldBeNoMath_part_one_example_1
         COMMAND $<TARGET_FILE:IWasToldThereWouldBeNoMath_Part1>
                 ${CMAKE_CURRENT_LIST_DIR}/res/examples/example1.txt 58)

add_test(NAME IWasToldThereWouldBeNoMath_part_one_example_2
         COMMAND $<TARGET_FILE:IWasToldThereWouldBeNoMath_Part1>
                 ${CMAKE_CURRENT_LIST_DIR}/res/examples/example2.txt 43)

add_test(NAME IWasToldThereWouldBeNoMath_part_one_puzzle_input
         COMMAND $<TARGET_FILE:IWasToldThereWouldBeNoMath_Part1>
                 ${CMAKE_CURRENT_LIST_DIR}/res/puzzle_input.txt 1606483)

add_test(NAME IWasToldThereWouldBeNoMath_part_two_example_1
         COMMAND $<TARGET_FILE:IWasToldThereWouldBeNoMath_Part2>
                 ${CMAKE_CURRENT_LIST_DIR}/res/examples/example1.txt 34)

add_test(NAME IWasToldThereWouldBeNoMath_part_two_example_2
         COMMAND $<TARGET_FILE:IWasToldThereWouldBeNoMath_Part2>
                 ${CMAKE_CURRENT_LIST_DIR}/res/examples/example2.txt 14)

add_test(NAME IWasToldThereWouldBeNoMath_part_two_puzzle_input
         COMMAND $<TARGET_FILE:IWasToldThereWouldBeNoMath_Part2>
                 ${CMAKE_CURRENT_LIST_DIR}/res/puzzle_input.txt 3842356)
