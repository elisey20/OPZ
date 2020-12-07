cmake_minimum_required(VERSION 3.17)
project(OPZ)

set(CMAKE_CXX_STANDARD 20)

set(SOURCE_FILES source/methods.cpp source/structs.cpp)

add_executable(OPZ main.cpp ${SOURCE_FILES})

include_directories(source)

install(TARGETS OPZ DESTINATION bin)