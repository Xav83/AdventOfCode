cmake_minimum_required(VERSION 3.12.4)

add_executable(ElvesLookElvesSay src/main.cpp)
set_target_properties(ElvesLookElvesSay PROPERTIES CXX_STANDARD 17)

add_test(NAME ElvesLookElvesSay_part_one_puzzle_input 
    COMMAND $<TARGET_FILE:ElvesLookElvesSay> 40 1113122113 360154
)
