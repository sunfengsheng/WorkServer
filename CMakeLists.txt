cmake_minimum_required(VERSION 3.8)
project(testserver CXX)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
add_definitions(-DORMPP_ENABLE_MYSQL)

add_subdirectory("3rd")
add_subdirectory("src")