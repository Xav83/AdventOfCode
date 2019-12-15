cmake_minimum_required(VERSION 3.12.4)

add_executable(MedecineForRudolph src/main.cpp)
set_target_properties(MedecineForRudolph PROPERTIES CXX_STANDARD 17)
target_link_libraries(MedecineForRudolph PUBLIC stringManipulation)

add_test(NAME MedecineForRudolph_example
         COMMAND $<TARGET_FILE:MedecineForRudolph>
                 ${CMAKE_CURRENT_LIST_DIR}/res/example.txt 4)
