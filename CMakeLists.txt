cmake_minimum_required(VERSION 3.23)
project(virtual_machine C)

set(CMAKE_C_STANDARD 23)

add_executable(virtual_machine main.c instruction_decoder.c instruction_runner.c memory.c)
add_executable(virtual_machine_test test.c instruction_decoder.c instruction_runner.c memory.c)
