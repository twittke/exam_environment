cmake_minimum_required(VERSION 3.29)
project(exam_environment C)

set(CMAKE_C_STANDARD 11)

add_subdirectory(datastructures)
#add_subdirectory(compare)

add_executable(exam_environment main.c)
target_link_libraries(exam_environment PUBLIC datastructures)
#target_link_libraries(exam_environment PUBLIC compare)
target_include_directories(exam_environment PUBLIC datastructures)
#target_include_directories(exam_environment PUBLIC compare)

add_executable(test_datastructures datastructures/tests_datastructures.c)
target_link_libraries(test_datastructures PUBLIC datastructures)
target_include_directories(test_datastructures PUBLIC datastructures)