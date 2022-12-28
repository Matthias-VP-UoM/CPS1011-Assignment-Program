cmake_minimum_required(VERSION 3.23)
project(Task1 C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall")

set(SOURCE_FILES1 task1c.c task1a.c task1b.c)
add_executable(task1 ${SOURCE_FILES1})
