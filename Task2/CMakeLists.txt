cmake_minimum_required(VERSION 3.23)
project(Task2 C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall")

set(SOURCEFILES_1 task2a.c stack.c)
add_executable(app1 ${SOURCEFILES_1})

set(SOURCEFILES_2 task2b.c stack_2.c)
add_executable(app2 ${SOURCEFILES_2})

set(SOURCEFILES_STACK stack_2.c)
add_library(list SHARED ${SOURCEFILES_STACK})

set(SOURCE_FILESTEST_DRIVER task2b.c stack_2.c)
add_executable(app3 ${SOURCE_FILESTEST_DRIVER})
target_link_libraries(app3 list)

