cmake_minimum_required(VERSION 3.5)
project(snake)

option(SNAKE_BUILD_CLIENT "" OFF)
option(SNAKE_BUILD_SERVER "" OFF)

if (${SNAKE_BUILD_CLIENT})
    add_subdirectory(./src/client ${CMAKE_BINARY_DIR}/client)
endif()

if (${SNAKE_BUILD_SERVER})
    add_subdirectory(./src/server ${CMAKE_BINARY_DIR}/server)
endif()
