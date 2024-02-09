cmake_minimum_required(VERSION 3.23)

project(Task2 C)

set(CMAKE_C_STANDARD 11)

set(StackFile MixedStack_t.c) # setting the Mixed Stack '.c' file as 'StackFile'

add_executable(2a 2a.c) # adding '2a.c' as an executable (Implementation a, supporting integers and 64 character strings)

add_library(MixedStack_t SHARED ${StackFile}) # adding StackFile as shared library

set(DriverFile 2b.c) # setting '2b.c' file as 'DriverFile'

add_executable(2b ${DriverFile}) # adding 'DriverFile' as an executable

target_link_libraries(2b MixedStack_t) # linking the Mixed Stack shared library to the driver '.c' file