cmake_minimum_required(VERSION 3.29)
project(exam_environment C)

set(CMAKE_C_STANDARD 11)

add_subdirectory(datastructures)
add_subdirectory(compare)

add_executable(datastructure datastructure_test.c)
add_executable(exam_environment main.c)
target_link_libraries(datastructure PUBLIC datastructures)
target_link_libraries(exam_environment PUBLIC datastructures)
target_link_libraries(datastructure PUBLIC compare)
target_link_libraries(exam_environment PUBLIC compare)
target_include_directories(datastructure PUBLIC datastructures)
target_include_directories(exam_environment PUBLIC datastructures)
target_include_directories(datastructure PUBLIC compare)
target_include_directories(exam_environment PUBLIC compare)

