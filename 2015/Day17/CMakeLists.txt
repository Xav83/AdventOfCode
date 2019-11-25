cmake_minimum_required(VERSION 3.12.4)

add_executable(NoSuchThingAsTooMuch src/main.cpp)
set_target_properties(NoSuchThingAsTooMuch PROPERTIES CXX_STANDARD 17)
target_link_libraries(NoSuchThingAsTooMuch PUBLIC stringManipulation)

add_test(NAME NoSuchThingAsTooMuch_example
         COMMAND $<TARGET_FILE:NoSuchThingAsTooMuch>
                 ${CMAKE_CURRENT_LIST_DIR}/res/example.txt 25 4)
