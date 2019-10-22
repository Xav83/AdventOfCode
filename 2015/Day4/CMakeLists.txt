cmake_minimum_required(VERSION 3.12.4)

include(${CMAKE_BINARY_DIR}/conanbuildinfo_multi.cmake)

add_library(Md5Wrapper STATIC src/md5_wrapper.cpp)
set_target_properties(Md5Wrapper PROPERTIES CXX_STANDARD 17)
target_link_libraries(Md5Wrapper PUBLIC CONAN_PKG::OpenSSL)

add_executable(TheIdealStockingStuffer_Part1 src/part_one.cpp)
set_target_properties(TheIdealStockingStuffer_Part1 PROPERTIES CXX_STANDARD 17)
target_link_libraries(TheIdealStockingStuffer_Part1 PUBLIC Md5Wrapper)

add_executable(TheIdealStockingStuffer_Part2 src/part_two.cpp)
set_target_properties(TheIdealStockingStuffer_Part2 PROPERTIES CXX_STANDARD 17)
target_link_libraries(TheIdealStockingStuffer_Part2 PUBLIC Md5Wrapper)

add_test(NAME TheIdealStockingStuffer_part_one_example_1
         COMMAND $<TARGET_FILE:TheIdealStockingStuffer_Part1> "abcdef" 609043)

add_test(NAME TheIdealStockingStuffer_part_one_example_2
         COMMAND $<TARGET_FILE:TheIdealStockingStuffer_Part1> "pqrstuv" 1048970)

add_test(NAME TheIdealStockingStuffer_part_one_puzzle_input
         COMMAND $<TARGET_FILE:TheIdealStockingStuffer_Part1> "yzbqklnj" 282749)

add_test(NAME TheIdealStockingStuffer_part_two_puzzle_input
         COMMAND $<TARGET_FILE:TheIdealStockingStuffer_Part2> "yzbqklnj"
                 9962624)
