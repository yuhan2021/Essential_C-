cmake_minimum_required(VERSION 3.8)

project(class_test)
include_directories(${PROJECT_SOURCE_DIR})
set(SRC 
    ${PROJECT_SOURCE_DIR}/main.cpp
    ${PROJECT_SOURCE_DIR}/util_load.cpp )

add_executable(${SRC})

