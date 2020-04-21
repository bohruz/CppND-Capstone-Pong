cmake_minimum_required(VERSION 3.7)

add_definitions(-std=c++17)

set(CXX_FLAGS "-Wall")
set(CMAKE_CXX_FLAGS, "${CXX_FLAGS}")

project(Pong)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/")

find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS} src)
find_package(Threads)

add_executable("${PROJECT_NAME}" src/main.cpp src/game.cpp src/ball.cpp src/controller.cpp src/renderer.cpp src/paddle.cpp)
string(STRIP ${SDL2_LIBRARIES} SDL2_LIBRARIES)
target_link_libraries("${PROJECT_NAME}" ${SDL2_LIBRARIES})
target_link_libraries("${PROJECT_NAME}" ${CMAKE_THREAD_LIBS_INIT})