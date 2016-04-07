cmake_minimum_required(VERSION 2.8.9)
project(sudoku)
set(PROJ "sudoku")
set(CMAKE_CXX_FLAGS "--std=c++11")
file(GLOB SOURCES "*.cpp")
file(GLOB INCLUDE_FILES "*.h")
set(SOURCES ${SOURCES} ${INCLUDE_FILES})
add_executable(${PROJ} ${SOURCES})

