cmake_minimum_required(VERSION 3.12.4)

add_executable(CorporatePolicy src/main.cpp)
set_target_properties(CorporatePolicy PROPERTIES CXX_STANDARD 17)

add_test(NAME CorporatePolicy_part_one_puzzle_input
    COMMAND $<TARGET_FILE:CorporatePolicy> hxbxwxba hxbxxyzz
)
