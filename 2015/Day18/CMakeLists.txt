cmake_minimum_required(VERSION 3.12.4)

add_library(LikeAGIFForYourYard_SharedCode src/Light.cpp src/Grid.cpp)
set_target_properties(LikeAGIFForYourYard_SharedCode PROPERTIES CXX_STANDARD 17)

add_executable(LikeAGIFForYourYard src/main.cpp)
set_target_properties(LikeAGIFForYourYard PROPERTIES CXX_STANDARD 17)
target_link_libraries(LikeAGIFForYourYard PUBLIC stringManipulation
                                                 LikeAGIFForYourYard_SharedCode)

add_test(NAME LikeAGIFForYourYard_puzzle_input
         COMMAND $<TARGET_FILE:LikeAGIFForYourYard>
                 ${CMAKE_CURRENT_LIST_DIR}/res/puzzle_input.txt 814)
