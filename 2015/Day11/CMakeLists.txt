cmake_minimum_required(VERSION 3.12.4)

add_executable(CorporatePolicy src/main.cpp)
set_target_properties(CorporatePolicy PROPERTIES CXX_STANDARD 17)

add_test(NAME CorporatePolicy_example_one
         COMMAND $<TARGET_FILE:CorporatePolicy> abcdefgh abcdffaa)

add_test(NAME CorporatePolicy_example_two
         COMMAND $<TARGET_FILE:CorporatePolicy> ghijklmn ghjaabcc)

add_test(NAME CorporatePolicy_part_one_puzzle_input
         COMMAND $<TARGET_FILE:CorporatePolicy> hxbxwxba hxbxxyzz)

add_test(NAME CorporatePolicy_part_two_puzzle_input
         COMMAND $<TARGET_FILE:CorporatePolicy> hxbxxyzz hxcaabcc)
