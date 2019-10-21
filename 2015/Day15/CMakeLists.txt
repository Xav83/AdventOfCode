cmake_minimum_required(VERSION 3.12.4)

add_executable(ScienceForHungryPeople src/main.cpp)
set_target_properties(ScienceForHungryPeople PROPERTIES CXX_STANDARD 17)
target_link_libraries(ScienceForHungryPeople PUBLIC stringManipulation)

add_test(NAME ScienceForHungryPeople_part_one_example
         COMMAND $<TARGET_FILE:ScienceForHungryPeople>
                 ${CMAKE_CURRENT_LIST_DIR}/res/example.txt 62842880)
