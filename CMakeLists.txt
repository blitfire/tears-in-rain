cmake_minimum_required(VERSION 4.0)

set(CMAKE_C_STANDARD 17)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_BUILD_TYPE Debug)

set(PROJECT_NAME tears-in-rain)
project(${PROJECT_NAME})

add_executable(${PROJECT_NAME} src/main.c
  src/alloc.c)
target_include_directories(${PROJECT_NAME} PUBLIC include)
