cmake_minimum_required(VERSION 3.0.0)
project(learn_cpp VERSION 0.1.0)
set (CMAKE_CXX_STANDARD 11)

list(APPEND CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/cmake)
enable_testing()
include(gmock)

include_directories(${CMAKE_CURRENT_SOURCE_DIR})
add_subdirectory(ToDoCore)

add_executable(helloworld helloWorld.cpp)
add_executable(cpp11 cpp11.cpp)
add_executable(cpp14 cpp14.cpp src/add.cpp)

add_executable(toDo ToDo_Main.cpp)
target_link_libraries(toDo toDoCore)

add_test(toDoTest toDo)