cmake_minimum_required(VERSION 3.0.0)
project(learn_cpp VERSION 0.1.0)
set (CMAKE_CXX_STANDARD 14)

list(APPEND CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/cmake)
enable_testing()
include(gmock)

include_directories(${CMAKE_CURRENT_SOURCE_DIR})
add_subdirectory(ToDoCore)

add_executable(helloWorld src/helloWorld.cpp)
add_executable(cpp11 src/cpp11.cpp)
add_executable(cpp14 src/cpp14.cpp src/add.cpp)

add_executable(ToDo_Main src/ToDo_Main.cpp)
target_link_libraries(ToDo_Main toDoCore)

add_executable(maybe src/maybe.cpp)

add_test(toDoTest toDo)