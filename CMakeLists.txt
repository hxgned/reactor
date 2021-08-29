cmake_minimum_required(VERSION 3.0)
project(reactor)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_BUILD_TYPE debug)
set(CMAKE_CXX_FLAGS
    " -std=c++2a -g -Wall -Wextra -Werror -Wno-unused-parameter  -Wshadow ")

find_package(Threads REQUIRED)

include_directories(${PROJECT_SOURCE_DIR})
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)


add_subdirectory(base)
add_subdirectory(net)
add_subdirectory(3rdParty)
add_subdirectory(examples)
