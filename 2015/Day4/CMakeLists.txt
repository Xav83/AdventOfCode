cmake_minimum_required(VERSION 3.12.4)

find_program(CONAN NAMES conan.exe HINTS "C:\\Program Files\\Conan\\conan")

if(${CONAN}-NOTFOUND)
    message(FATAL_ERRO "Conan not found")
endif(${CONAN}-NOTFOUND)

# Download automatically, you can also just copy the conan.cmake file
if(NOT EXISTS "${CMAKE_BINARY_DIR}/conan.cmake")
   message(STATUS "Downloading conan.cmake from https://github.com/conan-io/cmake-conan")
   file(DOWNLOAD "https://raw.githubusercontent.com/conan-io/cmake-conan/master/conan.cmake"
                  "${CMAKE_BINARY_DIR}/conan.cmake")
endif()

include(${CMAKE_BINARY_DIR}/conan.cmake)

conan_cmake_run(REQUIRES OpenSSL/1.1.1a@conan/stable
                BASIC_SETUP CMAKE_TARGETS
                BUILD missing
                OPTIONS OpenSSL:shared=False
)

message ("Conan libs : ${CONAN_LIBS}")

add_executable(TheIdealStockingStuffer_Part1 src/part_one.cpp)
set_target_properties(TheIdealStockingStuffer_Part1 PROPERTIES CXX_STANDARD 17)
target_link_libraries(TheIdealStockingStuffer_Part1 PUBLIC CONAN_PKG::OpenSSL)

add_test(NAME TheIdealStockingStuffer_part_one_example_1
    COMMAND $<TARGET_FILE:TheIdealStockingStuffer_Part1> "abcdef" 609043
)

add_test(NAME TheIdealStockingStuffer_part_one_example_2
    COMMAND $<TARGET_FILE:TheIdealStockingStuffer_Part1> "pqrstuv" 1048970
)

add_test(NAME TheIdealStockingStuffer_part_one_puzzle_input
    COMMAND $<TARGET_FILE:TheIdealStockingStuffer_Part1> "yzbqklnj" 282749
)
