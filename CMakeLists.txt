# cmake_minimum_required(VERSION 3.17)
project(OPZ)

# set(CMAKE_CXX_STANDARD 20)

set(SOURCE_FILES source/methods.cpp source/structs.cpp)

add_subdirectory(googletest)

include_directories(source)
include_directories(googletest/googletest/include)

add_executable(OPZ main.cpp ${SOURCE_FILES})
add_executable(tests tests.cpp ${SOURCE_FILES})

target_link_libraries(tests gtest)