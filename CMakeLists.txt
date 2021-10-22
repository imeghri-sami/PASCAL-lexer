cmake_minimum_required(VERSION 3.17)
project(pascal_scanner C)

set(CMAKE_C_STANDARD 99)

add_executable(pascal_scanner main.c headers/tokens.h headers/helpers.h headers/global.h helpers/helpers.c headers/structs.h headers/includes.h headers/core.h core/scanner.c)